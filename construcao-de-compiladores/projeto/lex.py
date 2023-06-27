import re
import tabela as t

arquivo = None
estado = 1 # inicia em 1
linha = 0
coluna = 0
coluna_comeco_token = 0
final = False
char_atual = None
nome_id = ""


def abre_arquivo(caminho_arquivo):
    global arquivo
    arquivo = open(caminho_arquivo, "r")

def lookahead(): # quando faz lookahead: volta 1 posição
    arquivo.seek(arquivo.tell()-1 , 0)

# chama o proximo char e verifica se acabou o arquivo
# utilizada em todos, e apenas em, estados não finais
def getCharVerifica():
    global final, char_atual, arquivo
    if final: return True # chegou no final e deu erro
    char_atual = arquivo.read(1)
    if char_atual == "":
        final = True
    return False # não chegou no final e leu um char

def setID():
    global nome_id, coluna_comeco_token
    item = t.tabela_de_simbolos.get(nome_id)
    if item == None: # não é reservado e não presente na tabela
        t.tabela_de_simbolos[nome_id] = ("id", "-", "-")
        return ("id", nome_id, (linha, coluna_comeco_token))
    else:
        if item[0] == "id": # não reservado e presente na tabela
            return("id", nome_id, (linha, coluna_comeco_token))
        else: # é reservado
            return (nome_id, "-", (linha, coluna_comeco_token))

def setChar():
    global nome_id, coluna_comeco_token
    nome_id = "'" + nome_id + "'"
    item = t.tabela_de_simbolos.get(nome_id)
    if item == None:
        t.tabela_de_simbolos[nome_id] = ("caractere", nome_id, "char")
    return ("caractere", nome_id, (linha, coluna_comeco_token))

def setInt():
    global nome_id, coluna_comeco_token
    item = t.tabela_de_simbolos.get(nome_id)
    if item == None:
        t.tabela_de_simbolos[nome_id] = ("numero", int(nome_id), "int")
    return ("numero", nome_id, (linha, coluna_comeco_token))

def setFrac():
    global nome_id, coluna_comeco_token
    item = t.tabela_de_simbolos.get(nome_id)
    if item == None:
        t.tabela_de_simbolos[nome_id] = ("numero", float(nome_id), "float")
    return ("numero", nome_id, (linha, coluna_comeco_token))

def setExp():
    global nome_id, coluna_comeco_token

    # converte de string de notação científica para float:
    numero = nome_id.split("E")
    numero = float(numero[0]) * pow(10, float(numero[1]))

    item = t.tabela_de_simbolos.get(nome_id)
    if item == None:
        t.tabela_de_simbolos[nome_id] = ("numero", numero, "float")
    return ("numero", nome_id, (linha, coluna_comeco_token))

def getToken():
    global estado, arquivo, final, linha, coluna, char_atual, nome_id, coluna_comeco_token
    estado = 1
    print_estados = 0
    final = False
    nome_id = ""
    if arquivo != None:
        while(1):
            match estado:
                # =======================
                # inicial
                case 1:
                    coluna_comeco_token = coluna
                    char_atual = arquivo.read(1)
                    coluna += 1

                    if print_estados == 1 : print("Entrou no estado 1 com o char", char_atual)
                    if re.match("[ |\t|\n]", char_atual):
                    #if char_atual == " " or char_atual == "\t" or char_atual == "\n":
                        if char_atual == "\n":
                            coluna = 0
                            linha += 1
                        estado = 42 # ws
                    

                    elif char_atual == '=':  estado = 2
                    elif char_atual == '<':  estado = 5
                    elif char_atual == '>':  estado = 9

                    elif char_atual == '+':  estado = 12
                    elif char_atual == '-':  estado = 13
                    elif char_atual == '*':  estado = 14
                    elif char_atual == '^':  estado = 15
                    
                    elif char_atual == '/':  estado = 17 # comentario ou divisão

                    elif char_atual == "'":  estado = 21
                    
                    elif re.match("[A-Za-z_]", char_atual): 
                        nome_id = char_atual
                        estado = 24

                    elif re.match("[0-9]", char_atual):
                        nome_id = char_atual
                        estado = 26

                    elif char_atual == "}": estado = 35
                    elif char_atual == "{": estado = 36
                    elif char_atual == ")": estado = 37
                    elif char_atual == "(": estado = 38

                    elif char_atual == ':':  estado = 39
                    elif char_atual == ';':  estado = 40
                    elif char_atual == ',':  estado = 41

                    elif char_atual != "":
                        return("ERRO", "Token não reconhecido: '" + char_atual + "'", (linha,coluna))

                    elif char_atual == "":
                        return ("EOF", "-", (linha, coluna))
                    
                # =======================
                # operadores relacionais
                case 2:
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if print_estados == 1 : print("Entrou no estado 2 com o char", char_atual)
                    if char_atual == "=":
                        estado = 4
                    else: # char_atual != "="
                        estado = 3

                case 3: # = (atribuição)
                    if print_estados == 1 : print("Entrou no estado 3 com o char", char_atual)
                    if not final:
                        lookahead()
                        coluna -= 1
                    return ("=", "-", (linha, coluna_comeco_token))

                case 4: # ==
                    if print_estados == 1 : print("Entrou no estado 4 com o char", char_atual) 
                    return ("oprel", "EQ", (linha, coluna_comeco_token))

                case 5:
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if print_estados == 1 : print("Entrou no estado 5 com o char", char_atual)
                    if char_atual == ">":
                        estado = 6
                    elif char_atual == "=":
                        estado = 7
                    else: # char_atual != ">" and char_atual != "="
                        estado = 8

                case 6: # <>
                    if print_estados == 1 : print("Entrou no estado 6 com o char", char_atual)    
                    return ("oprel", "NE", (linha, coluna_comeco_token))
                
                case 7: # <=
                    if print_estados == 1 : print("Entrou no estado 7 com o char", char_atual)    
                    return ("oprel", "LE", (linha, coluna_comeco_token))

                case 8: # <
                    if print_estados == 1 : print("Entrou no estado 8 com o char", char_atual)
                    if not final:
                        lookahead()
                        coluna -= 1
                    return ("oprel", "LT", (linha, coluna_comeco_token))

                case 9:
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluana += 1
                    if print_estados == 1 : print("Entrou no estado 9 com o char", char_atual)
                    if char_atual == "=":
                        estado = 10
                    else: # char_atual != "="
                        estado = 11
                
                case 10: # >=
                    if print_estados == 1 : print("Entrou no estado 10 com o char", char_atual)    
                    return ("oprel", "GE", (linha, coluna_comeco_token))

                case 11: # >
                    if print_estados == 1 : print("Entrou no estado 11 com o char", char_atual)
                    if not final:
                        lookahead()
                        coluna -= 1
                    return ("oprel", "GT", (linha, coluna_comeco_token))
                
                # =======================
                # soma, subtração, multiplicação, expoente
                case 12: # +
                    if print_estados == 1 : print("Entrou no estado 12 com o char", char_atual)    
                    return ("somasub", "soma", (linha, coluna_comeco_token))
                case 13: # -
                    if print_estados == 1 : print("Entrou no estado 13 com o char", char_atual)    
                    return ("somasub", "sub", (linha, coluna_comeco_token))
                case 14: # *
                    if print_estados == 1 : print("Entrou no estado 14 com o char", char_atual)    
                    return ("multdiv", "mult", (linha, coluna_comeco_token))
                case 15: # ^
                    if print_estados == 1 : print("Entrou no estado 15 com o char", char_atual)    
                    return ("expo", "-", (linha, coluna_comeco_token))
                
                # =======================
                # comentario e divisão
                case 16: # divisão: estado final com lookahead e retorno
                    if print_estados == 1 : print("Entrou no estado 16")
                    if not final:
                        lookahead()
                        coluna -= 1
                    return ("multdiv", "div", (linha, coluna_comeco_token))
                
                case 17:
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1
                    if print_estados == 1 : print("Entrou no estado 17 com o char", char_atual)     
                    if char_atual == '*':
                        estado = 18
                    else: # char_atual != '*'
                        estado = 16
                
                case 18: 
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1
                    if print_estados == 1 : print("Entrou no estado 18")

                    if char_atual != '*':
                        estado = 18
                    else: # char_atual == '*'
                        estado = 19
                
                case 19:
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1 
                    if print_estados == 1 : print("Entrou no estado 19")

                    if char_atual == '*':
                        estado = 19
                    elif char_atual == '/':
                        estado = 20
                    else: # char_atual != '*' and char_atual != '/'
                        estado = 18

                case 20: # fim do comentário
                    if print_estados == 1 : print("Entrou no estado 20")
                    estado = 1

                # =======================
                # caractere
                case 21:
                    if print_estados == 1 : print("Entrou no estado 21")
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if char_atual != "'":
                        nome_id = char_atual
                        estado = 22
                    else:
                        return ("ERRO", "caractere vazio", (linha, coluna))


                case 22:
                    if print_estados == 1 : print("Entrou no estado 22")
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha, coluna))
                    coluna += 1

                    if char_atual == "'":
                        estado = 23
                    else:
                        return ("ERRO", "char ultrapassou o máximo de 1 caractere", (linha, coluna))

                case 23:
                    if print_estados == 1 : print("Entrou no estado 23")
                    estado = 1
                    return setChar()

                # =======================
                # id
                case 24: 
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    if print_estados == 1 : print("Entrou no estado 24")
                    coluna += 1

                    if re.match("[A-Za-z_0-9]", char_atual):
                        nome_id += char_atual
                        estado = 24
                    else:
                        estado = 25

                case 25: # estado final com lookahead
                    if print_estados == 1 : print("Entrou no estado 25")
                    
                    if not final:
                        lookahead()
                        coluna -= 1
                    estado = 1
                    return setID()

                # =======================
                # numero
                case 26:
                    if print_estados == 1 : print("Entrou no estado 26 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 26
                    elif char_atual == ".":
                        nome_id += char_atual
                        estado = 27
                    elif char_atual == "E":
                        nome_id += char_atual
                        estado = 29
                    else:
                        estado = 32

                case 27:
                    if print_estados == 1 : print("Entrou no estado 27 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 28
                    else:
                        return ("ERRO", "nenhum dígito após o ponto (.)", (linha, coluna))
                    
                case 28:
                    if print_estados == 1 : print("Entrou no estado 28 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 28
                    elif char_atual == "E":
                        nome_id += char_atual
                        estado = 29
                    else:
                        estado = 33

                case 29:
                    if print_estados == 1 : print("Entrou no estado 29 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[\+\-]", char_atual):
                        nome_id += char_atual
                        estado = 30
                    elif re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 31
                    else:
                        return ("ERRO", "nenhum dígito após o exponencial (E)", (linha, coluna))
                    
                case 30:
                    if print_estados == 1 : print("Entrou no estado 30 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 31
                    else:
                        return ("ERRO", "nenhum dígito após o sinal (+ ou -)", (linha, coluna))
                    
                case 31:
                    if print_estados == 1 : print("Entrou no estado 31 com o char", char_atual)
                    if getCharVerifica(): return("ERRO", "Fim de arquivo", (linha,coluna))
                    coluna += 1

                    if re.match("[0-9]", char_atual):
                        nome_id += char_atual
                        estado = 31
                    else:
                        estado = 34

                case 32:
                    if print_estados == 1 : print("Entrou no estado 32")
                    if not final:
                        lookahead()
                        coluna -= 1
                    return setInt()
                
                case 33:
                    if print_estados == 1 : print("Entrou no estado 33")
                    if not final:
                        lookahead()
                        coluna -= 1
                    return setFrac()
                
                case 34:
                    if print_estados == 1 : print("Entrou no estado 34")
                    if not final:
                        lookahead()
                        coluna -= 1
                    return setExp()

                # =======================
                # parênteses e chaves
                case 35: # }
                    if print_estados == 1 : print("Entrou no estado 35 com o char", char_atual)    
                    return ("fecha_chave", "-", (linha, coluna_comeco_token))
                case 36: # {
                    if print_estados == 1 : print("Entrou no estado 36 com o char", char_atual)    
                    return ("abre_chave", "-", (linha, coluna_comeco_token))
                case 37: # )
                    if print_estados == 1 : print("Entrou no estado 37 com o char", char_atual)    
                    return ("fecha_parentese", "-", (linha, coluna_comeco_token))
                case 38: # (
                    if print_estados == 1 : print("Entrou no estado 38 com o char", char_atual)    
                    return ("abre_parentese", "-", (linha, coluna_comeco_token))
                
                # =======================
                # pontuação
                case 39:
                    if print_estados == 1 : print("Entrou no estado 39 com o char", char_atual)    
                    return ("pontuacao", "DP", (linha, coluna_comeco_token))
                case 40:
                    if print_estados == 1 : print("Entrou no estado 40 com o char", char_atual)    
                    return ("pontuacao", "PV", (linha, coluna_comeco_token))
                case 41:
                    if print_estados == 1 : print("Entrou no estado 41 com o char", char_atual)    
                    return ("pontuacao", "VR", (linha, coluna_comeco_token))
                
                # =======================
                # ws
                case 42:
                    if final: return("ERRO", "fim de arquivo",(linha, coluna))
                    char_atual = arquivo.read(1)
                    coluna += 1
                    
                    if char_atual == "":
                        final = True

                    if print_estados == 1 : print("Entrou no estado 42")

                    if re.match(" |\t|\n", char_atual):
                        if char_atual == "\n":
                            coluna = 0
                            linha += 1
                        estado = 42
                    else:
                        estado = 43 # lookahead
                
                case 43: # estado final com lookahead
                    if print_estados == 1 : print("Entrou no estado 43")
                    
                    if not final:
                        lookahead()
                        coluna -= 1
                    estado = 1 # achou alguma coisa diferente de ws

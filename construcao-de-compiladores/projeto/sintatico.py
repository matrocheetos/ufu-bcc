import lex as lex
import tabela as t

def step(token):

    if t.pilha[-1] in t.lista_terminais:
        if token == t.pilha[-1]:
            print("Tirou terminal da pilha: ", t.pilha[-1])
            t.pilha.pop()
            print("Pilha atual: ", t.pilha)
        else:
            print("Erro sintatico! Token encontrado não esperado: ", t.pilha[-1])
            exit(1)

    else: # não é terminal
        for i in t.tabela_preditiva:
            if i[0] == t.pilha[-1] and i[1] == token:
                #print("Não-terminal:", i[0], "Terminal:", i[1])
                print("Tirou não terminal da pilha: ", t.pilha[-1])
                t.pilha.pop()
                for j in range(len(i[2])-1, -1, -1):
                    t.pilha.append(i[2][j])
                print("Pilha atual: ", t.pilha)
                
                #chama step recursivamente até encontrar um terminal
                step(token)

def identificaToken(nome, tipo):
    if nome == "oprel":
        match tipo:
            case "EQ":
                return "="
            case "NE":
                return "<>"
            case "LE":
                return "<="
            case "LT":
                return "<"
            case "GE":
                return ">="
            case "GT":
                return ">"
            
    elif nome == "somasub":
        match tipo:
            case "soma":
                return "+"
            case "sub":
                return "-"
    elif nome == "multdiv":
        match tipo:
            case "mul":
                return "*"
            case "div":
                return "/"
    elif nome == "expo":
        return "^"
    
    elif nome == "fecha_chave":
        return "}"
    elif nome == "abre_chave":
        return "{"
    elif nome == "fecha_parentese":
        return ")"
    elif nome == "abre_parentese":
        return "("
    
    elif nome == "pontuacao":
        match tipo:
            case "DP":
                return ":"
            case "PV":
                return ";"
            case "VR":
                return ","

    elif nome in  ["int", "float", "char"]:
        return "tipo"

    # elif nome == "tipo":
    #     return tipo

    # elif nome == "id":
    #     return tipo

    # elif nome == "caractere":
    #     return tipo

    # elif nome == "numero":
    #     return tipo
    
    else:
        return nome

lex.abre_arquivo("arquivo.txt")
while(1):
    token = lex.getToken()
    # print("<" + token[0] + "," + token[1] + ">" + " l:" + str(token[2][0]) + " c:" + str(token[2][1]))
    if token[0] == "EOF":
        break
    if token[0] == "ERRO":
        break
    
    token_atual = identificaToken(token[0], token[1])
    
    print(token_atual)
    step(token_atual)
    # print(t.pilha)
    

# print(s.tabela.get("int"))
# s.tabela["nome"] = ("id", "-", "-")
# print(s.tabela)

if lex.arquivo != None:
    lex.arquivo.close()



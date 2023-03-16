import random
import string
import numpy as np
from os import path, remove

# implementação de junção utilizando Hash Join

arquivo_alunos = "C://trabalhoGBD//alunos.txt"
arquivo_curso = "C://trabalhoGBD//curso.txt"

N = 3

tam_cod_curso = 3
tam_nome_aluno = 33
tam_nome_curso = 17

class aluno:
    seq_aluno: np.int32
    codigo_curso: str
    nome_aluno: str

class curso:
    seq_curso: np.int32
    codigo_curso: str
    nome_curso: str

def geraRegistros(qtd_registros):
    arq_tab1 = open(arquivo_alunos, 'w+')
    arq_tab2 = open(arquivo_curso, 'w+')

    for i in range(0, qtd_registros):
        seq = np.int32(i)
        codigo_curso = ''.join(random.choices(string.ascii_uppercase, k=tam_cod_curso))
        nome_aluno = ''.join(random.choices(string.ascii_uppercase, k=tam_nome_aluno))
        nome_curso = ''.join(random.choices(string.ascii_uppercase, k=tam_nome_curso))
        registro_aluno = "%d %s %s\n" % (seq, codigo_curso, nome_aluno)
        registro_curso = "%d %s %s\n" % (seq, codigo_curso, nome_curso)
        arq_tab1.write(registro_aluno)
        arq_tab2.write(registro_curso)

    arq_tab1.seek(0)
    arq_tab1.close()
    arq_tab2.seek(0)
    arq_tab2.close()


# le cada linha de um arquivo como uma tabela
def carregaTabela(arquivo):
    linhas = list()
    with open(arquivo, 'r') as f:
        linha = f.readline()
        while linha:
            linhas.append(linha.rstrip('\n'))
            linha = f.readline()
    return linhas


# insere uma entrada lida no hash
def insereHash(arquivo, entrada):
    with open(arquivo, 'a') as arquivo:
        arquivo.write(entrada)
        arquivo.write('\n')


# faz o hash da entrada e armazena em um arquivo
def funcaoHash(relacao, indice):

    for r in relacao:

        # indice incorreto:
        if (indice > len(r) - 1) or (indice < 0):
            return

        # hash f(k) = k mod N:
        k = r[indice]
        resultado = int(k) % N

        # guarda a entrada em um arquivo do hash correspondente
        arquivo_hash = str(resultado) + '.txt'

        insereHash(arquivo_hash, r)


# hash join de acordo com os indices de aluno e curso
def hashJoin(tabela, indice_aluno, indice_curso):
    #to count if the are no results
    nro_iteracoes = 0

    # compara entradas da tabela com o hash e mostra o resultado da juncao
    for r in tabela:
        # indice incorreto:
        if int(indice_curso) > len(r)-1 or indice_curso < 0:
            return

        # hash para encontrar entrada compativel
        k = r[indice_curso]
        resultado = int(k) % N
        arquivo_hash = str(resultado) + '.txt'

        if path.exists(arquivo_hash):
            with open(arquivo_hash) as f:
                linha = f.readline()
                while linha:
                    if r[indice_curso] == linha[indice_aluno]:
                        nro_iteracoes += 1
                        resultado_juncao = '[(' + linha + ')' + ',' + '(' + r + ')' + ']'
                        print(resultado_juncao)
                    linha = f.readline()
    if not nro_iteracoes:
        print('Entradas não compatíveis')


# execucao:

# remove arquivos de hash anteriores:
if path.exists("0.txt"):
    remove("0.txt")
if path.exists("1.txt"):
    remove("1.txt")
if path.exists("2.txt"):
    remove("2.txt")


# carrega tabelas
tab_aluno = carregaTabela('alunos.txt')
tab_curso = carregaTabela('curso.txt')
nro_registros = 10

# menu:
print("Juncao com Hash Join\n")
while (True):
    print(
        "1) Gera e carrega tabelas\n2) Junção por indice\n3) Sair\nOpcao: ")
    opcao = input()
    if (opcao == '1'):
        # gera registros e carrega tabelas
        geraRegistros(nro_registros)
        tab_aluno = carregaTabela('alunos.txt')
        tab_curso = carregaTabela('curso.txt')
        print("Tabelas carregadas\n")
    elif (opcao == '2'):
        # juncao por indice
        indice_aluno = input("indice aluno: ")
        indice_curso = input("indice curso: ")
        funcaoHash(tab_aluno, int(indice_aluno) - 1)
        hashJoin(tab_curso, int(indice_curso) - 1, int(indice_aluno) - 1)
    elif (opcao == '3'):
        break
    else:
        print("Opcao invalida\n")

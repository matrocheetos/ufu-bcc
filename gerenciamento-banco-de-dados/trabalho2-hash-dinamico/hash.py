import random
import string
import numpy as np

# IMPLEMENTE AS OPERAÇÕES DE BUSCA, INSERÇÃO E REMOÇÃO
# DE REGISTROS TENDO COMO ENTRADA UMA CHAVE

# localização arquivos:
arquivo_registros = "C://trabalhoGBD//registros.txt"
arquivo_buckets = "C://trabalhoGBD//buckets.txt"

# Hash Linear:
NIVEL = 0  # funcao de hash atual
NEXT = 0  # bucket que deve ser dividido
RODADA_M = 1
MAX_RODADA = 2 ** RODADA_M
NRO_BUCKETS = MAX_RODADA
TAM_PAGINA = 4

# especificação do registro:
tam_text = 46
class registro:
    nseq: np.int32
    text: str


# gera registros aleatórios dado uma quantidade na entrada e escreve em "arquivo_registros"
# não são os registros em bucket
def gera_registros(qtd_registros):
    arq_registro = open(arquivo_registros, 'w+')

    for i in range(0, qtd_registros):
        nseq = np.int32(i)
        text = ''.join(random.choices(string.ascii_uppercase, k=tam_text))
        registro = "%d %s\n" % (nseq, text)
        arq_registro.write(registro)

    arq_registro.seek(0)
    arq_registro.close()


# h tamanho (chave)
def funcao_hash(chave, tamanho):
    return (np.mod(chave, tamanho))
    #return (chave % 2 ** tamanho)


# insere dados no bucket e verifica overflow
def insere_bucket(dados, rehash=False):
    global RODADA_M
    global NEXT

    # calcula endereço do bucket
    chave = dados.nseq
    if (rehash == True):
        bucket_id = funcao_hash(chave, RODADA_M + 1)
    else:
        bucket_id = funcao_hash(chave, RODADA_M)
        if (bucket_id < NEXT):
            bucket_id = funcao_hash(chave, RODADA_M)

    # insere no bucket
    offset = calcula_offset(bucket_id)
    indice = open(arquivo_buckets, 'wb+')
    indice.seek(offset, 0)
    indice.write(dados.nseq)
    indice.write(dados.text.encode('utf-8'))
    indice.close()

    # verifica overflow
    qtd_bucket = tamanho_bucket(bucket_id)
    if (qtd_bucket > TAM_PAGINA):
        if (rehash == False):
            split()
            funcao_rehash(NEXT)
            NEXT = NEXT + 1
            if (NEXT == 2 ** RODADA_M):
                NEXT = 0
                RODADA_M = RODADA_M + 1


# duplica o numero de buckets
def split():
    global NRO_BUCKETS
    NRO_BUCKETS = NRO_BUCKETS * 2


# recalcula o hash apos o split
def funcao_rehash(NEXT):
    global RODADA_M


# retorna quantidade de entradas em um bucket
def tamanho_bucket(bucket_id):
    indice = open(arquivo_buckets, 'r+')
    indice.seek(0, 0)
    tam_bucket = len((indice.readlines())[bucket_id]) - 1
    indice.close()
    return tam_bucket / 50


# calcula e retorna o offset a partir de uma chave
def calcula_offset(bucket_id):
    offset = 0
    indice = open(arquivo_buckets, 'rb')
    indice.seek(0, 0)
    entradas = indice.readlines()
    indice.close()

    i = 0
    while(i <= bucket_id):
        print(len(entradas))
        if (len(entradas) > bucket_id):
            offset = offset + len(entradas[i])
            i += 1
        else:
            add_linha = open(arquivo_buckets, 'ab')
            add_linha.write("\n".encode('utf-8'))
            add_linha.close()
            print("antes: ", entradas)
            indice = open(arquivo_buckets, 'rb')
            indice.seek(0, 0)
            entradas = indice.readlines()
            indice.close()
            print("depois: ", entradas)
            offset = offset + 1

    print("offset %d" % offset)
    return offset-1


# faz uma busca no índice dado uma chave
def busca_chave(chave):
    # encontra hash da chave:
    chave = np.int32(chave)
    chave_hash = funcao_hash(chave, RODADA_M)

    indice = open(arquivo_buckets, 'r')
    pagina = indice.readlines()[chave_hash]
    indice.close()
    print("Conteúdo da página: %s" % pagina)


# remove um registro dado uma chave
def remove_registro(chave):
    chave = np.int32(chave)
    chave_hash = funcao_hash(chave, RODADA_M)

    offset = calcula_offset(chave_hash)
    indice = open(arquivo_buckets, 'wb+')
    indice.seek(offset, 0)
    indice.write(" ".encode('utf-8'))
    indice.close()


# insere um registro
def insere_registro(nseq, text):
    dados.nseq = np.int32(nseq)
    dados.text = text
    insere_bucket(dados, rehash=False)


# insere todos os registros de um arquivo
def insere_arquivo_registros(arquivo):
    entradas = open(arquivo, 'r+')
    entradas.seek(0, 0)
    registros = entradas.readlines()
    entradas.close()
    for i in range(0, len(registros)):
        linha = registros[i].split(" ", 2)
        dados.nseq = np.int32(linha[0])
        dados.text = str(linha[1][:-1])
        insere_bucket(dados, rehash=False)



# execução
# limpa arquivo buckets:
indice = open(arquivo_buckets, "wb")
indice.write("\n".encode('utf-8'))
indice.close()

dados = registro()
print(NRO_BUCKETS)

print("Hash Dinâmico Linear em disco\n")
while (True):
    print(
        "1) Insere registro único\n2) Insere arquivo de registros\n3) Busca registro\n4) Remove registro\n5) Sair\nOpcao: ")
    opcao = input()
    if (opcao == '1'):
        print("Chave a ser inserida: ")
        nseq = input()
        text = ''.join(random.choices(string.ascii_uppercase, k=tam_text))
        insere_registro(nseq, text)
        print("Registro inserido no bucket\n")
    elif (opcao == '2'):
        print("Quantidade de registros a ser gerado: ")
        qtd_registros = input()
        gera_registros(int(qtd_registros))
        print("Arquivo em '%s' atualizado\n" % arquivo_registros)
        insere_arquivo_registros(arquivo_registros)
    elif (opcao == '3'):
        print("Chave do registro a ser buscado: ")
        nseq = input()
        busca_chave(nseq)
    elif (opcao == '4'):
        print("Chave do registro a ser removido: ")
        nseq = input()
        remove_registro(nseq)
        print("Registro removido\n")
    elif (opcao == '5'):
        break
    else:
        print("Opcao invalida\n")

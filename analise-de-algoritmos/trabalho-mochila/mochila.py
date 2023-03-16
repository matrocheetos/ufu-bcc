import gc
import os
import psutil
import random
import timeit

import numpy as np
from matplotlib import pyplot as plt

PESO = 0
VALOR = 1

def mochilaExponencial(k, coisas, n):
    if n == 0:
        if coisas[n][PESO] <= k:
            return coisas[n][VALOR]
        return 0
    valorCom = -1
    if (k - coisas[n][PESO]) >= 0:
        valorCom = mochilaExponencial(k - coisas[n][PESO], coisas, n - 1) + coisas[n][VALOR]
    valorSem = mochilaExponencial(k, coisas, n - 1)
    return max(valorCom, valorSem)


def mochilaMemo(k, coisas, n):
    memo = {}
    def mochilaMemoizada(k, coisas, n):
        if n == 0:
            if coisas[n][PESO] <= k:
                return coisas[n][VALOR]
            return 0

        if coisas[n][PESO] in memo:
            return memo[coisas[n][PESO]]

        valorCom = -1
        if (k - coisas[n][PESO]) >= 0:
            valorCom = mochilaMemoizada(k - coisas[n][PESO], coisas, n - 1) + coisas[n][VALOR]
        valorSem = mochilaMemoizada(k, coisas, n - 1)
        memo[coisas[n][PESO]] = max(valorCom, valorSem)
        return memo[coisas[n][PESO]]

    return mochilaMemoizada(k, coisas, n)


def mochilaPD(k, coisas):
    # tabela 'pequena':
    A = [[0 for _ in range(k + 1)] for _ in range(len(coisas) + 1)]
    for i in range(1, len(coisas) + 1):
        for c in range(k + 1):
            if coisas[i - 1][PESO] > c:
                A[i][c] = A[i - 1][c]
            else:
                menorSem = A[i - 1][c]
                menorCom = A[i - 1][c - coisas[i - 1][PESO]] + coisas[i - 1][VALOR]
                A[i][c] = max(menorSem, menorCom)

    return A[-1][-1]


# aproximacao deve ser float entre 0 e 1
def mochilaAprox(k, coisas, aproximacao):

    # aproximacao padrao (0.5) para valores invalidos:
    if(aproximacao >= 1 or aproximacao <= 0):
        aproximacao = 0.5

    novaCapacidade = int(float(k) * aproximacao)
    novaCoisas = [(round(float(peso) * aproximacao), valor) for peso, valor in coisas]

    return mochilaPD(novaCapacidade, novaCoisas)


# =====================
# testes
# =====================

# parametros:
minObjetos = 5
maxObjetos = 30
maxValor = 30   # 30
maxPeso = 20    # 20
aproximacao = 0.5  # epsilon entre 1 e 0

# seed para testes consistentes:
random.seed(12345)

# matplotlib:
tabela_exponencial = []
tabela_memoizada = []
tabela_pd = []
tabela_aprox75 = []
tabela_aprox50 = []
tabela_aprox25 = []
tabela_tamanho_entrada = []


def media(lista):
    return sum(lista) / len(lista)


# testes:
def testeTempo():

    # timeit:
    t1 = lambda: (mochilaExponencial(k, coisas, n))
    t2 = lambda: (mochilaMemo(k, coisas, n))
    t3 = lambda: (mochilaPD(k, coisas))
    t4 = lambda: (mochilaAprox(k, coisas, aproximacaoT))

    for S in range(minObjetos, maxObjetos):
        # S = qtd de objetos
        print(S)
        tempo_exponencial, tempo_memoizada, tempo_pd, tempo_aprox75, tempo_aprox50, tempo_aprox25 = [], [], [], [], [], []

        for i in range(5):
            coisas = [(random.randint(1, maxPeso), random.randint(1, maxValor)) for _ in range(S)]
            k = int(30 * S * 0.25)
            n = len(coisas) - 1

            tempo_exponencial.append(timeit.timeit(stmt=t1, number=1))
            tempo_memoizada.append(timeit.timeit(stmt=t2, number=1))
            tempo_pd.append(timeit.timeit(stmt=t3, number=1))
            aproximacaoT = 0.75
            tempo_aprox75.append(timeit.timeit(stmt=t4, number=1))
            aproximacaoT = 0.5
            tempo_aprox50.append(timeit.timeit(stmt=t4, number=1))
            aproximacaoT = 0.25
            tempo_aprox25.append(timeit.timeit(stmt=t4, number=1))

        tabela_tamanho_entrada.append(S)
        tabela_exponencial.append(media(tempo_exponencial))
        tabela_memoizada.append(media(tempo_memoizada))
        tabela_pd.append(media(tempo_pd))
        tabela_aprox75.append(media(tempo_aprox75))
        tabela_aprox50.append(media(tempo_aprox50))
        tabela_aprox25.append(media(tempo_aprox25))

    plt.plot(tabela_tamanho_entrada, tabela_exponencial, label="recursiva")
    plt.plot(tabela_tamanho_entrada, tabela_memoizada, label="memoizada")
    plt.plot(tabela_tamanho_entrada, tabela_pd, label="PD")
    plt.plot(tabela_tamanho_entrada, tabela_aprox75, label="aproximada 0.75")
    plt.plot(tabela_tamanho_entrada, tabela_aprox50, label="aproximada 0.50")
    plt.plot(tabela_tamanho_entrada, tabela_aprox25, label="aproximada 0.25")
    plt.ylabel('tempo (s)')
    plt.xlabel('tamanho entrada')
    plt.title('implementações da mochila')
    plt.xticks(np.arange(5, max(tabela_tamanho_entrada), step=1))
    plt.grid(True)
    plt.legend()
    plt.show()




process = psutil.Process(os.getpid())
def testeMemoria():

    process = psutil.Process(os.getpid())
    if gc.isenabled():
        gc.disable()

    for S in range(minObjetos, maxObjetos):
        # S = qtd de objetos
        print(S)

        for i in range(5):
            coisas = [(random.randint(1, maxPeso), random.randint(1, maxValor)) for _ in range(S)]
            k = int(30 * S * 0.25)
            n = len(coisas) - 1

            memoria_pd = process.memory_full_info().uss
            mochilaPD(k, coisas)
            memoria_pd = process.memory_info().vms - memoria_pd

            print(memoria_pd)

    if not gc.isenabled():
        gc.enable()


def testeCorretude():
    for S in range(minObjetos, maxObjetos):
        print(S)
        for _ in range(5):
            coisas = [(random.randint(1, maxPeso), random.randint(1, maxValor)) for _ in range(S)]
            k = int(30 * S * 0.25)
            n = len(coisas) - 1

            m_exp = mochilaExponencial(k, coisas, n)

            m_memo = mochilaMemo(k, coisas, n)

            m_pd = mochilaPD(k, coisas)

            m_aprox1 = mochilaAprox(k, coisas, 0.75)
            m_aprox2 = mochilaAprox(k, coisas, 0.5)
            m_aprox3 = mochilaAprox(k, coisas, 0.25)

            print(" m_exp:", m_exp, " m_memo:", m_memo, " m_pd:", m_pd)
            print(coisas)
            print("")

            print("PD:", m_pd, " aprox 0.75:", m_aprox1, " aprox 0.5:", m_aprox2, " aprox 0.25:", m_aprox3)


testeTempo()
testeMemoria()
testeCorretude()

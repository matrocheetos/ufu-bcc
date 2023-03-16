import random

def randomizaEstado(estado):
    for i in range(len(estado)):
        estado[i] = random.randint(0, len(estado)-1)
    return estado

def geraEstadoRandomizado(n):
    return randomizaEstado([0]*n)

def getCusto(estado):
    custo = 0

    for i in range(0, len(estado)):
        for j in range(i+1, len(estado)):
            if estado[i] == estado[j] or abs(estado[i] - estado[j]) == j-i:
                custo += 1

    return custo

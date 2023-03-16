from trab1.solucoes import *
from math import *

# permite mov aleatorio mas depende da prob_aceitacao pro aleatorio ser aceito
def recristalizacaoSimulada(estado, max_iteracoes, temperatura, resfriamento):

    custo_a_superar = getCusto(estado)
    mov_count = 0

    print('Custo inicial: ', custo_a_superar)
    print('Estado: ', estado)

    for i in range(0, max_iteracoes):
        if not custo_a_superar > 0:
            break

        estado = movimenta(estado, custo_a_superar, temperatura)
        custo_a_superar = getCusto(estado)
        temperatura = max(temperatura * resfriamento, 0.01) # menor temp possivel é 0.01
        mov_count += 1
        #print("estado: ", estado)
        #print("temp: ",temperatura)

    print("Solucao: ", estado)
    print("Moveu ", mov_count, " vezes")
    return custo_a_superar if custo_a_superar == 0 else None

# gera aleatorio ate achar um melhor ou algum que seja aceito
def movimenta(estado, custo_a_superar, temperatura):
    n = len(estado)

    while(True):
        nCol = random.randint(0, n-1)
        nLinha = random.randint(0, n-1)

        tempLinha = estado[nCol]
        estado[nCol] = nLinha

        custo = getCusto(estado)
        if(custo < custo_a_superar): # superou custo
            return estado

        delta = custo_a_superar - custo
        prob_aceitacao = min(1, exp(delta / temperatura)) # maior temperatura, menor delta, maior aceitacao

        if(random.random() < prob_aceitacao):
            return estado

        estado[nCol] = tempLinha

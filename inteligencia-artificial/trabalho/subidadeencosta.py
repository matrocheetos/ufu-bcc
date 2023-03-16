from trab1.solucoes import *

def subidaDeEncosta(estado, max_iteracoes):
    n = len(estado)
    custo_a_superar = getCusto(estado)
    rand_count = 0
    mov_count = 0

    print('Custo inicial: ', custo_a_superar)
    print('Estado: ', estado)
    #input()

    for x in range(0, max_iteracoes):
        if not custo_a_superar > 0:
            break

        flag = True # se ja fez movimento
        temp_custo_inicial = custo_a_superar
        for col in range(0,n):
            if not flag:
                break

            for linha in range(0,n):
                if linha == estado[col]:
                    continue # vai para prox iteracao de for

                estado_copia = estado.copy()
                estado_copia[col] = linha
                custo = getCusto(estado_copia)

                if custo_a_superar > custo: # superou custo
                    estado[col] = linha
                    custo_a_superar = custo
                    flag = False
                    break

        if(temp_custo_inicial == custo_a_superar): # parou em minimo local
            estado = geraEstadoRandomizado(n)
            rand_count += 1

        mov_count += 1

    print("Solucao: ", estado)
    print("Randomizou ", rand_count, " vezes")
    print("Moveu ", mov_count, " vezes")
    return custo_a_superar if custo_a_superar == 0 else None

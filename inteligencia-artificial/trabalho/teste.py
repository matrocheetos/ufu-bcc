import timeit
from trab1.recristalizacaosimulada import recristalizacaoSimulada
from trab1.subidadeencosta import subidaDeEncosta


# === testes ===

def testes(estado, max_iteracoes, temperatura, resfriamento, nro_testes):
    e1 = estado.copy()
    e2 = estado.copy()
    t1 = lambda: subidaDeEncosta(e1, max_iteracoes)
    t2 = lambda: recristalizacaoSimulada(e2, max_iteracoes, temperatura, resfriamento)

    tempo_sde = timeit.timeit(stmt=t1, number=nro_testes)
    tempo_sde = 0
    tempo_rs = timeit.timeit(stmt=t2, number=nro_testes)

    return tempo_sde, tempo_rs, e1, e2

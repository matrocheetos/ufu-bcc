import timeit

import numpy as np
from tabulate import tabulate
from matplotlib import pyplot as plt
from trab1.solucoes import geraEstadoRandomizado
from trab1.teste import testes

# === parametros ===
n = 19
max_iteracoes = 50000
tabelan, tabela_sde, tabela_rs, tabela_problema, tabela_sde_solucao, tabela_rs_solucao = [], [], [], [], [], []

# === recristalizacao simulada ===
temperatura = 1
resfriamento = 0.8

# === testes ===
nro_testes = 1  # testes timeit

aumento_n = 30  # qtd de aumentos de n
tabela_media_sde, tabela_media_rs = [], []
for i in range(0, aumento_n):
    n = n + 1
    tabela_media_sde.append(0)
    tabela_media_rs.append(0)
    for j in range(0, 5):
        estado = geraEstadoRandomizado(n)

        tempo_sde, tempo_rs, solucao_sde, solucao_rs = testes(estado, max_iteracoes, temperatura, resfriamento,
                                                              nro_testes)

        tabelan.append(n)
        tabela_sde.append(tempo_sde)
        tabela_rs.append(tempo_rs)
        tabela_problema.append(str(estado))
        tabela_sde_solucao.append(str(solucao_sde))
        tabela_rs_solucao.append(str(solucao_rs))
        tabela_media_sde[i] = tabela_media_sde[i] + tempo_sde
        tabela_media_rs[i] = tabela_media_rs[i] + tempo_rs
    tabela_media_sde[i] = tabela_media_sde[i] / n
    tabela_media_rs[i] = tabela_media_rs[i] / n

# === tabela ===

tabela_tempo = []
tabela_tempo.append(["n-rainhas"] + tabelan)
tabela_tempo.append(["r[coluna] = linha"] + tabela_problema)
tabela_tempo.append(["subida de encosta"] + tabela_sde)
tabela_tempo.append(["solucao sde"] + tabela_sde_solucao)
tabela_tempo.append(["recristalizacao simulada"] + tabela_rs)
tabela_tempo.append(["solucao rs"] + tabela_rs_solucao)

print(tabulate(tabela_tempo, headers='firstrow', tablefmt='fancy_grid'))
print("media sde: "+str(tabela_media_sde))
print("media rs: "+str(tabela_media_rs))

# === grafico ===

plt.figure(figsize=(10, 5))
plt.plot(list(set(tabelan)), tabela_media_sde, label="subida de encosta")
plt.plot(list(set(tabelan)), tabela_media_rs, label="recristalizacao simulada")
plt.ylabel('tempo (s)')
plt.xlabel('rainhas (n)')
plt.xticks(np.arange(4, max(tabelan), step=1))
plt.grid(True)
plt.title("algoritmos n-rainhas")
plt.legend()
plt.show()

# Trabalho 2

## Enunciado

Este segundo trabalho consiste em usar o pacote Evolutionary.jl da Julia para realizar a otimização de uma função escolhida por você a partir daquelas disponíveis no arquivo anexo.

- [Documentação do pacote Evolutionary.jl](https://wildart.github.io/Evolutionary.jl/dev/)

- [Documentação do pacote Metaheuristics.jl](https://juliapackages.com/p/metaheuristics)

Para este trabalho, você usará tanto o algoritmo genético (GA) quanto o PSO dos pacotes para otimizar a função escolhida com as seguintes dimensões: 16, 24, 32 e 64. Ajuste os parâmetros dos dois algoritmos para encontrar um conjunto deles que seja melhor adaptado a seu problema. Varie os vários operadores disponíveis tanto para cruzamento, mutação ou seleção para ver quais são melhores para o seu problema.

## Função de Levy

$$levy(x) = sin^2(πw_1) + \sum_{i=1}^{d−1}  (wi−1)^2[1 + 10 sin^2(πw_i+ 1)] + (w_d−1)^2[1 + sin^2(2πw_d)]$$

com $w_i = 1 + \frac{x_i − 1}{4}$ para todo $i= 1,...,d$

- Mínimo global: $levy(x∗) = 0$ quando $x∗ = (1,...,1)$

- Domínio: $x_i∈[−10,10]$, para todo $i = 1, ... , d$
- Fonte: https://www.sfu.ca/~ssurjano/levy.html

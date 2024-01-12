using Base.MathConstants
# import Pkg; Pkg.add("Metaheuristics")
using Metaheuristics
using Random


dimensions = [16, 24, 32, 64]

function levy_modified(x)
    dimensions = length(x)
    first_term = sin(pi * w_modified(x, 1))^2

    summation = 0
    for i in 1:dimensions-1
        term1 = (w_modified(x, i) - 1)^2
        term2 = 1 + 10 * (sin(pi * w_modified(x, i) + 1)^2)
        term3 = (w_modified(x, dimensions) - 1)^2
        term4 = 1 + sin(2 * pi * w_modified(x, dimensions) + 1)^2

        summation += term1 * term2 + term3 * term4
    end

    return first_term + summation
end

function w_modified(x, i)
    return 1 + (x[i] - 1) / 4
end

function generate_initial_set_LevyInf(dimensions)
    # Coloca semente pra controlar a bagunça
    Random.seed!(1234)

    # Cria o vetor de -10 a 10
    random_numbers = -20.0 .+ 0 * rand(Float64, dimensions)

    return random_numbers
end

function generate_initial_set_LevySup(dimensions)
    # Coloca semente pra controlar a bagunça
    Random.seed!(1234)

    # Cria o vetor de -10 a 10
    random_numbers = -0 .+ 20 * rand(Float64, dimensions)

    return random_numbers
end

# Função para realizar a Otimização por Enxame de Partículas para as dimensoes
for dim in dimensions
    println("Resultado para dimensão: $dim")
    println("===============================================================")

    # Define a função objetivo Levy, nesse caso
    funcao_objetivo(z) = levy_modified(z)

    # Gera conjuntos iniciais para limites inferior e superior
    limites_inferiores = generate_initial_set_LevyInf(dim)
    limites_superiores = generate_initial_set_LevySup(dim)

    # Cria restrições de caixa usando os limites gerados
    restricoes = boxconstraints(lb = limites_inferiores, ub = limites_superiores)

    # Realiza a otimização usando PSO
    resultado_otimizacao = optimize(funcao_objetivo, restricoes, PSO())

    # Imprime o resultado da otimização
    println(resultado_otimizacao)
end













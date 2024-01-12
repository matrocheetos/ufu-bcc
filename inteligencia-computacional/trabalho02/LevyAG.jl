using Base.MathConstants
using Evolutionary
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

function generate_initial_set_Levy(dimension)
    Random.seed!(1234)

    # Cria o vetor float de -10 a 10
    random_numbers = -10 .+ 20.0 * rand(Float64, dimension)

    return random_numbers
end

function genetic_algorithm_optimization(dimension, sel, mut, cross)
    initial_population = generate_initial_set_Levy(dimension)

    result = Evolutionary.optimize(x -> levy_modified(x), initial_population,
                                    GA(populationSize = 500,
                                        selection = sel,
                                        crossover = cross,
                                        mutation = mut),
                                        Evolutionary.Options(iterations=2000))

    return result
end



# Loop sobre as dimensões e realiza a Otimização por Enxame de Partículas e Algoritmo Genetico
for d in dimensions

    # roleta, roletainversa
    selection = [Evolutionary.roulette, Evolutionary.rouletteinv]
    # uniforme, gaussiana
    mutation = [Evolutionary.uniform(), Evolutionary.gaussian()]
    # uniforme, inverso, aritmetico
    crossover = [Evolutionary.UX, Evolutionary.DC, Evolutionary.AX]

    melhor_resultado = Inf
    melhor_config = []

    for sel in selection
        mut_str = "uniform"
        for mut in mutation
            for cross in crossover
                result = genetic_algorithm_optimization(d, sel, mut, cross)

                # println("Dimensão: $(d)")
                # println("Minimizado: $(result.minimizer)")
                # println("Iterações: $(result.iterations)")
                # println("Operadores: $(sel), $(mut_str), $(cross)")
                # println("*******************************")

                if result.minimum < melhor_resultado
                    melhor_resultado = result.minimum
                    melhor_config = [sel, mut_str, cross, result.minimizer, minimum(abs.(result.minimizer)), result.iterations]
                end
            end
            mut_str = "gaussian"
        end
    end

    println()
    println("Para d = $(d)")
    println("Melhores operadores: $(melhor_config[1]), $(melhor_config[2]), $(melhor_config[3])")
    println("$(melhor_config[4])")
    println("Solução: $(melhor_config[5])")
    println("Iterações: $(melhor_config[6])")
    println("=====================================================================================")
    sleep(10)
    println()
end

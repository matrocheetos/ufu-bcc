function fatoresPrimos(numero::Integer)
    if numero <= 1
        return []
    end
    
    fatores = []
    divisor = 2     # divisor inicial
    
    while numero > 1
        while numero % divisor == 0
            push!(fatores, divisor)
            numero /= divisor
        end
        divisor += 1
    end
    
    return fatores
end

# exemplos
println(fatoresPrimos(1))
println(fatoresPrimos(2))
println(fatoresPrimos(9))
println(fatoresPrimos(12))
println(fatoresPrimos(901255))

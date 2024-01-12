function éPermutacao(matriz)
    n = size(matriz, 1)

    # se matriz não é quadrada
    if size(matriz, 2) != n
        return false
    end

    # se matriz tem apenas 0's e 1's e apenas um 1 por linha e coluna
    for i in 1:n
        row_sum = sum(matriz[i, :])
        col_sum = sum(matriz[:, i])
        if row_sum != 1 || col_sum != 1 || any(x -> x != 0 && x != 1, matriz[i, :]) || any(x -> x != 0 && x != 1, matriz[:, i])
            return false
        end
    end

    return true
end

# exemplos
matriz = [1 0 0; 0 0 1; 0 1 0]
matrizF = [0 1 0; 0 1 0; 0 0 1]

println(éPermutacao(matriz))    # true
println(éPermutacao(matrizF))   # false

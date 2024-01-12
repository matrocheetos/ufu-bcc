function media(matriz)
    n, m = size(matriz)
    soma = 0.0
    elementos = 0
    
    for i in 1:n
        for j in 1:m
            if i > j
                soma += matriz[i, j]
                elementos += 1
            end
        end
    end
    
    if elementos == 0
        return 0.0
    else
        return soma / elementos
    end
end

# exemplo
matriz = [1.0 2.0 3.0; 4.0 5.0 6.0; 7.0 8.0 9.0]
media = media(matriz)
println("Média aritmética dos elementos abaixo da diagonal principal:", media)

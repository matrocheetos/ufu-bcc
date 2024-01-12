function encontraMinimax(matriz)
    n = size(matriz, 1)
    l = 1
    c = 1
    
    # max = maximum(matriz)
    l = argmax(matriz)[1]
    for i in 1:n
        if matriz[n*l*i] < minimax
            minimax = matriz[n*l*i]
            c = i
        end
    end
    
    return minimax, (l, c)
end

# Exemplo de uso
matriz = [5 3 9; 2 7 6; 1 8 4]

mm, (l, c) = encontraMinimax(matriz)
println("Elemento minimax:", mm)
println("Linha:", l)
println("Coluna:", c)

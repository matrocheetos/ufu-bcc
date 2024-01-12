struct Distância
    m::Integer
    cm::Integer
end

function distanciaEmCentímetros(dist::Distância)
    return dist.m*100 + dist.cm
end

function comparar(dist1::Distância, dist2::Distância)
    dist1_cm = distanciaEmCentímetros(dist1)
    dist2_cm = distanciaEmCentímetros(dist2)

    if dist1_cm > dist2_cm
        return "Distância 1 é maior"
    elseif dist2_cm > dist1_cm
        return "Distância 2 é maior"
    else
        return "As distâncias são iguais"
    end
end

function somar(dist1::Distância, dist2::Distância)
    soma = distanciaEmCentímetros(dist1) + distanciaEmCentímetros(dist2)
    metros = div(soma, 100)
    centímetros = soma % 100

    return Distância(metros, centímetros)

end

function subtrair(dist1::Distância, dist2::Distância)
    diferença = abs(distanciaEmCentímetros(dist1) - distanciaEmCentímetros(dist2))
    metros = div(diferença, 100)
    centímetros = diferença % 100

    return Distância(metros, centímetros)
end

# exemplos
dist1 = Distância(5, 40)
dist2 = Distância(7, 25)
println(comparar(dist1, dist2))
println("somar: ", somar(dist1, dist2))
println("subtrair: ", subtrair(dist1, dist2))

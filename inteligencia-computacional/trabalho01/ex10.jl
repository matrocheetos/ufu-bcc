struct Distância
    m::Integer
    cm::Integer
end

function distanciaEmCentímetros(dist::Distância)
    return dist.m*100 + dist.cm
end

struct Salto
    distância::Distância
    nome::String
    país::String
    data::String
    cidade::String
end

function formataData(data)
    partes = split(data, " ")
    mês_map = Dict("janeiro"=> "01",
                    "fevereiro"=> "02",
                    "março"=> "03",
                    "abril"=> "04",
                    "maio"=> "05",
                    "junho"=> "06",
                    "julho"=> "07",
                    "agosto"=> "08",
                    "setembro"=> "09",
                    "outubro"=> "10",
                    "novembro"=> "11",
                    "dezembro"=> "12")
    return partes[1] * "/" * mês_map[partes[2]] * "/" * partes[3]
end

saltos_arquivo = readlines("saltos.txt")
saltos = []

for linha in saltos_arquivo
    campos = split(linha, ",")
    distância = Distância(parse(Int, split(campos[1], ".")[1]), parse(Int, split(campos[1], ".")[2]))
    nome = campos[2]
    país = campos[3]
    data = formataData(campos[4])
    cidade = campos[5]
    push!(saltos, Salto(distância, nome, país, data, cidade))
end

sort!(saltos, rev=true, by=s -> distanciaEmCentímetros(s.distância))

for salto in saltos
    println("Salto: ", salto.distância.m, "m ", salto.distância.cm, "cm, Nome: ", salto.nome)
end
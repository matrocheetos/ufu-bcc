function romano(natural::Integer)
    if natural <= 0
        return "erro! número nagativo ou zero"
    end

    naturais = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    romanos = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    romano = ""

    # converte percorrendo o vetor 'naturais', do maior para o menor, e substituindo por 'romanos'
    i = 1
    while natural > 0
        if natural >= naturais[i]
            romano *= romanos[i]
            natural -= naturais[i]
        else
            i += 1
        end
    end

    return romano
end

# exemplos
println(romano(21))
println(romano(800))
println(romano(2021))
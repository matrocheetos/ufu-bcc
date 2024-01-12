function acronimo(sentenca::String)
    palavras = split(sentenca)
    acronimo = ""
    
    for palavra in palavras
        if isuppercase(first(palavra))
            acronimo *= first(palavra)
        end
    end
    
    return acronimo
end

# exemplos
# obs: acrônimo será formado apenas pelas palavras que iniciam em letra maiúscula
println(acronimo("National Aeronautics and Space Administration"))
println(acronimo("Cadastro Nacional de Estabelecimentos de Sa ́ude"))
println(acronimo("Organização do Tratado do Atlântico Norte"))

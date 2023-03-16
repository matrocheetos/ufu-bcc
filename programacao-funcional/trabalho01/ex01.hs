analisa_raizes :: Int -> Int -> Int -> String
analisa_raizes a b c
    | a == 0 = "4-equacao degenerada"
    | b^2 > 4*a*c = "1-possui duas raizes reais"
    | b^2 == 4*a*c = "2-possui uma raiz real"
    | b^2 < 4*a*c = "3-nenhuma raiz real"
    
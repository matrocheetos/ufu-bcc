type Data = (Int, Int, Int)

precede :: Data -> Data -> Bool
precede (dia1,mes1,ano1) (dia2,mes2,ano2)
    | ano1<ano2 = True
    | ano1==ano2 && mes1<mes2 = True
    | ano1==ano2 && mes1==mes2 && dia1<dia2 = True
    | otherwise = False
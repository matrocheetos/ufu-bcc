-- resto da divisao m/n
resto_div :: Int -> Int -> Int
resto_div m n
    | n>m = m
    | m==0 = 0
    | otherwise = resto_div (m-n) n


-- quociente da divisao m/n
div_inteira :: Int -> Int -> Int
div_inteira m n = div m n
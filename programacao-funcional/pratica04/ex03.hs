-- (a) --
listaA :: Int -> Int -> [Int]
listaA a b
    | a == b = [a]
    | a > b = []
    | otherwise = [a..b]

-- (b) --
listaB :: Int -> Int -> [Int]
listaB a b
    | a == b || a > b = []
    | mod a 2 == 0 = [a,a+2..b]
    | otherwise = [a+1,a+3..b]
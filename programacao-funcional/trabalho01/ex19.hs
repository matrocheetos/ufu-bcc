-- valores de notas disponiveis para troco
disponiveis :: [Int]
disponiveis = [1,2,5,10,20,50,100]

-- retorna todas as combinacoes de notas possiveis para devolver o troco
notasTroco :: Int -> [[Int]]
notasTroco x
    | x < minimum disponiveis = [[]]
    | otherwise =   [ as | a <- disponiveis, a <= x,
                    as <- [ a:b | b <- notasTroco (x-a) ],
                    sum as == x ]

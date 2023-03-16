-- retorna o produto dos elementos de uma lista numerica
produtorio :: Num a => [a] -> a
produtorio [] = 1
produtorio (x:r) = x * produtorio r

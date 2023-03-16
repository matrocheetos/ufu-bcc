-- retorna a qtd de pares em uma lista
npares :: [Int] -> Int
npares [] = 0
npares (x:r) =  if (even x)
                then 1 + npares r
                else npares r

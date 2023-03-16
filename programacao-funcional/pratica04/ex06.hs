seleciona_impares :: [Int] -> [Int]
seleciona_impares a = [ x | x <- a, not even x ]
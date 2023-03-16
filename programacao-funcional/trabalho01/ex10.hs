seleciona_multiplos :: Int -> [Int] -> [Int]
seleciona_multiplos n lista = [ x | x<-lista, mod x n == 0 ]
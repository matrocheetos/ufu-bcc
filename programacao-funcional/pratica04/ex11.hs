uniaoNRec :: [Int] -> [Int] -> [Int]
uniaoNRec a b = [ x | x <- a++[ y | y <- b, not (elem y a) ] ]
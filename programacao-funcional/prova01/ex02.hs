seleciona :: [[Int]] -> [[Int]]
seleciona [[]] = [[]]
seleciona (x:xs) = [ tail y | y <- (x:seleciona xs), head x < 4 ]

{-
-- gabarito:
seleciona :: [[Int]] -> [[Int]]
seleciona lista = [y | (x:y) <- lista, x<4]
-}
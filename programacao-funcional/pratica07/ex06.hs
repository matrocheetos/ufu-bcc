solucoes :: [Int] -> [Int]
solucoes l = filter (\x -> ((5*x+6) < (x*x))) l

-- ghci> solucoes [3,4,5,6,7,8,9]
-- [7,8,9]
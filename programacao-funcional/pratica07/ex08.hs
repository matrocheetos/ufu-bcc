menor_min10 :: [Int] -> Int
menor_min10 l = foldr min 10 l

-- ghci> menor_min10 [4,5,2,1]
-- 1
-- ghci> menor_min10 [14,21]
-- 10
maior :: [Int] -> Int
maior [] = 0
maior l = foldr1 max l

-- ghci> maior [4,5,2,1]
-- 5
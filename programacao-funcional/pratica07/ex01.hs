paridade :: [Int] -> [Bool]
paridade l = map (even) l

-- ghci> paridade [1,2,3,4]
-- [False,True,False,True]
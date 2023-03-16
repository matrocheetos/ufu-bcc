menores10 :: [Int] -> ([Int],Int)
menores10 l = (x, length x)
    where x = [x | x<-l, x<10]

-- ghci> menores10 [1,34,6,3,21]
-- ([1,6,3],3)
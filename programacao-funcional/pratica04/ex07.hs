tabuada :: Int -> [Int]
tabuada a = [ x | x <- [a..a*10], mod x a == 0 ]
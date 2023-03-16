-- (a) --
contaPosM3 :: [Int] -> Int
contaPosM3 a = length( [ x | x<-a, x>0, mod x 3 == 0 ] )

-- (b) --
extraiPosM3 :: [Int] -> [Int]
extraiPosM3 a = [ x | x<-a, x>0, mod x 3 == 0 ]
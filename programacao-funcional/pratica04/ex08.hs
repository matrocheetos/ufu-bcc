bissextos :: [Int] -> [Int]
bissextos a = [ x | x<-a, mod x 100 /= 0 && mod x 4 == 0 || mod x 400 == 0 ]
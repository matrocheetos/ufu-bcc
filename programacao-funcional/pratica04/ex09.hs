sublistas :: [[Int]] -> [Int]
sublistas a = [ x | x <- (concat a) ]
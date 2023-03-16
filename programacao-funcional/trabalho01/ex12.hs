intercala :: [a] -> [a] -> [a]
intercala [] [] = []
intercala x [] = x
intercala [] y = y
intercala (x:xs) (y:ys) = [x,y]++(intercala xs ys)

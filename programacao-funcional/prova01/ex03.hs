remove_varios :: Eq a => [a] -> [a] -> [a]
remove_varios [] _ = []
remove_varios [x] [] = [x]
remove_varios (x:xs) (y:ys)
    | x == y = remove_varios xs (y:ys)
    | otherwise = x:(remove_varios xs (y:ys))

{- ANULADA -}
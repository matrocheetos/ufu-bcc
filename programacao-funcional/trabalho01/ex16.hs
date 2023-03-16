-- insere o elemento 'x' em uma lista ordenada crescente
insere_ord :: Ord a => a -> [a] -> [a]
insere_ord x [] = [x]
insere_ord x (y:ys)
    | x < y = (x:y:ys)
    | otherwise = y:(insere_ord x ys)

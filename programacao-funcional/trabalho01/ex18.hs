-- retorna uma lista sem elementos repetidos
elimina_repet :: [a] -> [a]
elimina_repet [] = []
elimina_repet (x:xs)
    | elem x xs = elimina_repet xs
    | otherwise = x:elimina_repet xs

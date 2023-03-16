busca_elem :: Eq a => a -> [a] -> (Bool,Int)
busca_elem _ [] = (False, 0)
busca_elem i l = (encontra_bool i l,comparacoes)
    where comparacoes = (length l) - (length (encontra_lista i l))

encontra_bool :: Eq a => a -> [a] -> Bool
encontra_bool _ [] = False
encontra_bool i (x:xs)
    | x == i = True
    | otherwise = encontra_bool i xs

encontra_lista :: Eq a => a -> [a] -> [a]
encontra_lista _ [] = []
encontra_lista i (x:xs)
    | x == i = xs
    | otherwise = encontra_lista i xs

-- ghci> busca_elem 1 [5,4,1,6,3,2]
-- (True,3)
-- ghci> busca_elem 7 [5,4,1,6,3,2]
-- (False,6)
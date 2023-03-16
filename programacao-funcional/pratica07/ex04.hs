-- definicao da funcao "filter":

filtrar :: (a -> Bool) -> [a] -> [a]
filtrar p [] = []
filtrar p (x:xs)
    | p x = x : filtrar p xs
    | otherwise = filtrar p xs

filtrar_compreensao :: (a -> Bool) -> [a] -> [a]
filtrar_compreensao p [] = []
filtrar_compreensao p l = [x | x<-l, p x]

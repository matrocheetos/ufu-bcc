import ListasTeste

{- SELECTION SORT -}
-- codigo original com contador de trocas:

selecaoContador :: (Ord a) => [a] -> Int -> ([a],Int)
selecaoContador [] i = ([],i)
selecaoContador xs i = ( ([x] ++ seleciona),j )
    where   x = minimo xs
            (seleciona,j) = selecaoContador (remove x xs) (i+1)

selecao :: (Ord a) => [a] -> ([a],Int)
selecao [] = ([],0)
selecao lista = selecaoContador lista 0

remove :: (Ord a) => a -> [a] -> [a]
remove a [] = []
remove a (x:xs)
    | a == x = xs
    | otherwise = x:(remove a xs)

minimo :: (Ord a) => [a] -> a
minimo [] = undefined
minimo [x] = x
minimo (x:xs)
    | x <= minimo xs = x
    | otherwise = minimo xs


-- variacao 1:

selecaoContador1 :: (Ord a) => [a] -> Int -> ([a],Int)
selecaoContador1 [] i = ([],i)
selecaoContador1 xs i = ( ([menor] ++ seleciona),j )
    where   (seleciona,j) = selecaoContador1 lstRemove (i+1)
            (lstRemove,menor) = remove_menor xs

selecao1 :: (Ord a) => [a] -> ([a],Int)
selecao1 [] = ([],0)
selecao1 lista = selecaoContador1 lista 0

-- remove_menor :: lista -> (lista, menor)
remove_menor :: (Ord a) => [a] -> ([a],a)
remove_menor [] = ([],undefined)
remove_menor [x] = ([],x)
remove_menor (x:xs)
    | x <= menor = ( xs,x )
    | otherwise = ( x:remover,menor )
        where (remover,menor) = remove_menor xs

-- variacao 2:

selecaoContador2 :: (Ord a) => [a] -> [a]
selecaoContador2 [] = []
selecaoContador2 lista = foldr (\x y -> x:y) (selecaoContador2 lst) [menor]
    where (lst,menor) = remove_menor lista

selecao2 :: (Ord a) => [a] -> ([a],Int)
selecao2 [] = ([],0)
selecao2 lista = ((selecaoContador2 lista),(length lista))

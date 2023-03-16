import ListasTeste

{- BUBBLE SORT -}
-- codigo original com contador de trocas:

bolha :: (Ord a) => [a] -> ([a],Int)
bolha [] = ([],0)
bolha lista = bolhaOrd lista 0 (length lista)

bolhaOrd :: (Ord a) => [a] -> Int -> Int -> ([a],Int)
bolhaOrd lista i 0 = (lista,i)
bolhaOrd lista i n = bolhaOrd lst j (n-1)
    where (lst,j) = trocas (lista,i)

trocas :: (Ord a) => ([a],Int) -> ([a],Int)
trocas ([x],i) = ([x],i)
trocas ((x:y:zs),i)
    | x > y = ((y:lst1),j1)
    | otherwise = ((x:lst2),j2)
        where   (lst1,j1) = trocas((x:zs),(i+1))
                (lst2,j2) = trocas((y:zs),(i))


-- variacao 1:

bolha1 :: (Ord a) => [a] -> ([a],Int)
bolha1 [] = ([],0)
bolha1 lista =
    if parada lista
    then (lista,0)
    else bolhaOrd1 lista 0 (length lista)

bolhaOrd1 :: (Ord a) => [a] -> Int -> Int -> ([a],Int)
bolhaOrd1 lista i 0 = (lista,i)
bolhaOrd1 lista i n = bolhaOrd1 lst j (n-1)
    where (lst,j) = trocas1 (lista,i)

trocas1 :: (Ord a) => ([a],Int) -> ([a],Int)
trocas1 ([x],i) = ([x],i)
trocas1 ((x:y:zs),i)
    | x > y = ((y:lst1),j1)
    | otherwise = ((x:lst2),j2)
        where   (lst1,j1) = trocas1((x:zs),(i+1))
                (lst2,j2) = trocas1((y:zs),(i))

parada :: (Ord a) => [a] -> Bool
parada [] = True
parada [x] = True
parada (x:y:zs)
    | x > y = False
    | otherwise = parada (y:zs)


-- variacao 2:

bolha2 :: (Ord a) => [a] -> ([a],Int)
bolha2 [] = ([],0)
bolha2 lista = bolhaOrd2 lista 0 (length lista)

bolhaOrd2 :: (Ord a) => [a] -> Int -> Int -> ([a],Int)
bolhaOrd2 lista i 0 = (lista,i)
bolhaOrd2 lista i n = bolhaOrd2 lst j (n-1)
    where (lst,j) = trocas2 (lista,i)

trocas2 :: (Ord a) => ([a],Int) -> ([a],Int)
trocas2 ([x],i) = ([x],i)
trocas2 ((x:y:zs),i)
    | x > y = if parada (x:zs) then ((y:x:zs),i+1) else ((y:lst1),j1)
    | otherwise = if parada (y:zs) then ((x:y:zs),(i)) else ((x:lst2),j2)
        where   (lst1,j1) = trocas2((x:zs),(i+1))
                (lst2,j2) = trocas2((y:zs),(i))

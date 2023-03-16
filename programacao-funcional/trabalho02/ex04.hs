import ListasTeste

{- QUICK SORT -}
-- codigo original com contador de comparacoes:
quicksortContador :: (Ord a) => [a] -> Int -> ([a],Int)
quicksortContador [] i = ([],i)
quicksortContador (s:xs) i = 
    ( (lst1 ++ [s] ++ lst2),(j1+j2) )
        where   (lst1,j1) = quicksortContador [ x | x <- xs, x<s ] (i+1)
                (lst2,j2) = quicksortContador [ x | x <- xs, x>=s ] (i+1)

quicksort :: (Ord a) => [a] -> ([a],Int)
quicksort [] = ([],0)
quicksort lista = quicksortContador lista 0


-- variacao 1:

quicksortContador1 :: (Ord a) => [a] -> Int -> ([a],Int)
quicksortContador1 [] i = ([],i)
quicksortContador1 (s:xs) i =
    ( (lst1 ++ [s] ++ lst2),j1+j2 )
        where   (lst1,j1) = quicksortContador1 lstMenor (i+1)
                (lst2,j2) = quicksortContador1 lstMaior (i+1)
                (lstMenor,lstMaior) = divide s xs

quicksort1 :: (Ord a) => [a] -> ([a],Int)
quicksort1 [] = ([],0)
quicksort1 lista = quicksortContador1 lista 0

divide :: (Ord a) => a -> [a] -> ([a],[a]) -- ([lstMenor],[lstMaior])
divide s [] = ([],[])
divide s xs = ((filter (<s) xs),(filter (>=s) xs))


-- variacao 2:

quicksortContador2 :: (Ord a) => [a] -> Int -> ([a],Int)
quicksortContador2 [] i = ([],i)
quicksortContador2 (s:xs) i = 
    ( (lst1 ++ [p] ++ lst2),j1+j2 )
        where   (lst1,j1) = quicksortContador1 lstMenor (i+1)
                (lst2,j2) = quicksortContador1 lstMaior (i+1)
                (lstMenor,lstMaior) = divide p ps
                (p:ps) = pivo (s:xs)

quicksort2 :: (Ord a) => [a] -> ([a],Int)
quicksort2 [] = ([],0)
quicksort2 lista = quicksortContador2 lista 0

pivo :: (Ord a) => [a] -> [a]
pivo [] = []
pivo [x] = [x]
pivo [x,y] = [x,y]
pivo (x:y:z:ss)
    | x>y = pivo (y:x:z:ss)
    | y>z = pivo (x:z:y:ss)
    | otherwise = (y:x:z:ss)

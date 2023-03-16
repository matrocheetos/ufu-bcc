import ListasTeste

{- MERGE SORT -}
-- implementacao com contador de comparacoes:

merge :: (Ord a) => Int -> [a] -> [a] -> ([a],Int)
merge i [] ys = (ys,i)
merge i xs [] = (xs,i)
merge i xs@(x:xt) ys@(y:yt)
    | x <= y    = ((x : lst1),j1)
    | otherwise = ((y : lst2),j2)
        where (lst1,j1) = merge (i+1) xt ys
              (lst2,j2) = merge (i+1) xs yt

split :: (Ord a) => [a] -> ([a],[a])
split (x:y:zs) = let (xs,ys) = split zs in (x:xs,y:ys)
split [x]      = ([x],[])
split []       = ([],[])

mergeSortContador :: (Ord a) => Int -> [a] -> ([a],Int)
mergeSortContador i []  = ([],i)
mergeSortContador i [x] = ([x],i)
mergeSortContador i xs  =
    let (as,bs) = split xs
        (lst1,_) = mergeSortContador i as
        (lst2,_) = mergeSortContador i bs
    in merge i lst1 lst2

mergeSort :: (Ord a) => [a] -> ([a],Int)
mergeSort [] = ([],0)
mergeSort lst = mergeSortContador 0 lst

import ListasTeste

{- INSERTION SORT -}
-- codigo original com contador de comparacoes:

insercaoContador :: (Ord a) => [a] -> Int -> ([a],Int)
insercaoContador [] i = ([],i)
insercaoContador (x:xs) i = insereOrd x insere i
    where (insere,_) = insercaoContador xs i

insercao :: (Ord a) => [a] -> ([a],Int)
insercao [] = ([],0)
insercao lista = insercaoContador lista 0


insereOrd :: (Ord a) => a -> [a] -> Int -> ([a],Int)
insereOrd x [] i = ([x],i)
insereOrd x (y:ys) i
    | x <= y = ( (x:y:ys),j )
    | otherwise = ( y:insere,j ) 
        where (insere,j) = insereOrd x ys (i+1)


-- variacao 1:
            
insercaoContador1 :: (Ord a) => [a] -> [a]
insercaoContador1 = foldr insereOrd1 []

insercao1 :: (Ord a) => [a] -> ([a],Int)
insercao1 [] = ([],0)
insercao1 lista = ((insercaoContador1 lista),(length lista)-1)

insereOrd1 :: (Ord a) => a -> [a] -> [a]
insereOrd1 x [] = [x]
insereOrd1 x (y:ys)
    | x <= y = (x:y:ys)
    | otherwise = y:(insereOrd1 x ys)

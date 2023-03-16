{- ex01 -}

quicksort3 ::(Ord a) => [a] -> ([a],Int)
quicksort3 [] = ([],0)
quicksort3 lista = quicksort3Contador lista 0

quicksort3Contador::(Ord a) => [a] -> Int -> ([a],Int)
quicksort3Contador [] i = ([],i)
quicksort3Contador [x] i = ([x],i)
quicksort3Contador (s:xs) i = ( (lst4 ++ [s] ++lst3),(j+j1+j2) )
    where (lst1,lst2,j) = divide s xs i
          (lst3,j1) = quicksort3Contador lst1 j
          (lst4,j2) = quicksort3Contador lst2 j

divide:: (Ord a) => a -> [a] -> Int -> ([a],[a],Int)
divide p [] i = ([],[],i)
divide p [x] i = ([],[],i)
divide p (x:xs) i = if (x < p) then (x:l1,l2,j) else (l1,x:l2,j)
    where (l1,l2,j) = divide p xs (i+1)


{- ex03 -}

data ArvoreBinInt = Nulo | No Int ArvoreBinInt ArvoreBinInt
    deriving (Show,Eq)

type Tipo = String

buscaMult3 :: ArvoreBinInt -> Tipo -> Int
buscaMult3 Nulo _ = -1
buscaMult3 arvore tipo =
    if mod (last busca) 3 == 0
    then last busca
    else -1
        where lista = (buscaMult3Aux arvore tipo)
              busca = buscaMult3Aux2 lista

buscaMult3Aux :: ArvoreBinInt -> Tipo -> [Int]
buscaMult3Aux Nulo _ = []
buscaMult3Aux (No x esq dir) tipo
    | tipo == "pre" = [x] ++ (buscaMult3Aux esq tipo) ++ (buscaMult3Aux dir tipo)
    | tipo == "sim" = (buscaMult3Aux esq tipo) ++ [x] ++ (buscaMult3Aux dir tipo)
    | otherwise = []

buscaMult3Aux2 :: [Int] -> [Int]
buscaMult3Aux2 [] = []
buscaMult3Aux2 (x:xs) =
    if mod x 3 == 0
    then [x]
    else buscaMult3Aux2 xs

arvEx :: ArvoreBinInt
arvEx = (No 7 (No 3 (No 6 Nulo Nulo) (No 1 (No 4 Nulo Nulo) Nulo)) (No 10 Nulo (No 14 Nulo Nulo)))


{- extra -}
-- substitui exercicio 2

{- a -}

data Horario = AntesMD Hora Minuto Segundo | AposMD Hora Minuto Segundo
    deriving (Show)
type Hora = Int
type Minuto = Int
type Segundo = Int

{- b -}

maisTarde :: Horario -> Horario -> Horario
maisTarde (AntesMD h1 m1 s1) (AposMD h2 m2 s2) = (AposMD h2 m2 s2)
maisTarde (AposMD h1 m1 s1) (AntesMD h2 m2 s2) =  (AposMD h1 m1 s1)
maisTarde (AntesMD h1 m1 s1) (AntesMD h2 m2 s2) =
    if (h1>h2) || (h1==h2 && m1>m2) || (h1==h2 && m1==m2 && s1>s2)
    then (AntesMD h1 m1 s1)
    else (AntesMD h2 m2 s2)
maisTarde (AposMD h1 m1 s1) (AposMD h2 m2 s2) =
    if (h1>h2) || (h1==h2 && m1>m2) || (h1==h2 && m1==m2 && s1>s2)
    then (AposMD h1 m1 s1)
    else (AposMD h2 m2 s2)
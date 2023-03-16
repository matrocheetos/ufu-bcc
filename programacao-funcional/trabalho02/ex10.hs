{- árvore binária de inteiros -}
data ArvBinInt =
    Nulo
    | No Int ArvBinInt ArvBinInt
    deriving (Eq,Show)

{- percurso em pré-ordem -}
folhas :: ArvBinInt -> [Int]
folhas Nulo = []
folhas (No x esq dir) =
    if (esq == Nulo) && (dir == Nulo) -- se não possuir filhos
    then [x] ++ (folhas esq) ++ (folhas dir)
    else (folhas esq) ++ (folhas dir)

{- percurso em pós-ordem -}
somaNosInternos :: ArvBinInt -> Int
somaNosInternos Nulo = 0
somaNosInternos arvore = sum (somaNosInternosAux arvore)

somaNosInternosAux :: ArvBinInt -> [Int]
somaNosInternosAux Nulo = []
somaNosInternosAux (No x esq dir) = 
    if (esq /= Nulo) || (dir /= Nulo) -- se possuir pelo menos um filho
    then (somaNosInternosAux esq) ++ (somaNosInternosAux dir) ++ [x]
    else (somaNosInternosAux esq) ++ (somaNosInternosAux dir)

{- percurso em ordem simétrica -}
pertence :: Int -> ArvBinInt -> Bool
pertence n Nulo = False
pertence n arvore = elem n (pertenceAux arvore)

pertenceAux :: ArvBinInt -> [Int]
pertenceAux Nulo = []
pertenceAux (No x esq dir) = (pertenceAux esq) ++ [x] ++ (pertenceAux dir)

{- árvore para testes -}
arvEx :: ArvBinInt
arvEx = (No 2  (No 7    (No 2 Nulo Nulo)
                        (No 6   (No 5 Nulo Nulo)
                                (No 11 Nulo Nulo)))
                (No 5   Nulo
                        (No 9   (No 4 Nulo Nulo)
                                Nulo)))

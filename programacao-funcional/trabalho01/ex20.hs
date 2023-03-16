{-
> N rainhas
> tabuleiro N x N
> nenhuma rainha pode capturar outra rainha em um unico movimento
> sabe-se que cada rainha fica em uma coluna (1a rainha -> 1a coluna, 2a rainha -> 2a coluna, ...)
> funcao deve retornar todas as possiveis combinacoes
>> combinacoes sao organizadas em uma lista de N elementos
>>> esses elementos correspondem a posicao de linha da rainha 
-}

-- funcao "permutations" importada para gerar as diferentes combinacoes
-- recebe uma lista e retorna suas permutacoes
import Data.List (permutations)

-- funcao principal
nRainhas :: Int -> [[Int]]
nRainhas 0 = [[]]
nRainhas n = [ xs | xs <- permutations [1..n], valida n xs ]


-- valida se a posicao das rainhas nao se interferem
-- tamanho do tabuleiro -> lista de posicoes -> Bool
valida :: Int -> [Int] -> Bool
valida n [] = True                  -- se chegar na ultima coluna
valida n (x:xs)
    | elem x xs = False             -- se estiverem na mesma linha
    | diagonais n (x:xs) 1 = False  -- se estiverem na mesma diagonal
    | otherwise = valida n xs       -- muda de coluna no tabuleiro


-- verifica se há outra rainha nas diagonais de uma rainha
-- nao funciona !!
diagonais :: Int -> [Int] -> Int -> Bool
diagonais n [] c = False
diagonais n (x:xs) c = and [x/=c+1, x/=x-1, diagonais n xs (c+1)]

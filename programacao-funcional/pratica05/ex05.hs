-- retorna qtd de elementos em uma lista polimorfica
tamanho :: [a] -> Int
tamanho [] = 0
tamanho (x:r) = 1 + tamanho r

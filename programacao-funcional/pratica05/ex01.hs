-- conta elementos em lista tipo 'char'
conta_ch :: [Char] -> Int
conta_ch [] = 0
conta_ch (_:resto) = 1 + conta_ch resto

-- conta elementos em lista de qualquer tipo
conta :: [a] -> Int
conta [] = 0
conta (_:r) = 1 + conta r

-- encontra o maior elemento em uma lista de inteiros
maior :: [Int] -> Int
maior [x] = x
maior (x:y:resto)
    | x>y = maior (x:resto)
    | otherwise = maior (y:resto)

-- encontra os N primeiros elementos em uma lista
primeiros :: Int -> [a] -> [a]
primeiros 0 _ = []
primeiros _ [] = []
primeiros n (x:xs) = x:(primeiros (n-1) xs)

-- verifica se um elemento pertence a uma lista
pertence :: Eq a => a -> [a] -> Bool
pertence e [] = False
pertence e (x:z) = if (e == x) then True else pertence e z

-- une os elementos de duas listas 
uniaoR :: Eq a => [a] -> [a] -> [a]
uniaoR [] lista = lista
uniaoR (x:xs) lista =   if pertence x lista
                        then uniaoR xs lista
                        else x:(uniaoR xs lista)

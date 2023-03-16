-- Pessoa = (nome, altura, idade, estado civil)
type Pessoa = (String, Float, Int, Char)

pessoas :: [Pessoa]
pessoas = 
    [ ("Rosa", 1.66, 27,'F'),
    ("João", 1.85, 26, 'C'),
    ("Maria", 1.55, 62, 'S'),
    ("Jose", 1.78, 42, 'C'),
    ("Paulo", 1.93, 25, 'S'),
    ("Clara", 1.70, 33, 'C'),
    ("Bob", 1.45, 21, 'C'),
    ("Rosana", 1.58,39, 'S'),
    ("Daniel", 1.74, 72, 'S'),
    ("Jocileide", 1.69, 18, 'S') ]

{- funcoes auxiliares -}
nome :: Pessoa -> String
nome (n,_,_,_) = n

altura :: Pessoa -> Float
altura (_,a,_,_) = a

idade :: Pessoa -> Int
idade (_,_,i,_) = i

estado_civil :: Pessoa -> Char
estado_civil (_,_,_,ec) = ec
{- -- --- ---- --- -- -}

{- altura media entre todas as pessoas -}
altura_media :: [Pessoa] -> Float
altura_media [] = 0
altura_media p = soma_altura p / fromIntegral (length p)

soma_altura :: [Pessoa] -> Float
soma_altura [] = 0
soma_altura [p] = altura p
soma_altura (p:ps) = altura p + (soma_altura ps)


{- idade da pessoa mais nova -}
menor_idade :: [Pessoa] -> Int
menor_idade [] = 0
menor_idade [p] = idade p
menor_idade (p1:p2:ps)
    | idade p1 > idade p2 = menor_idade (p2:ps)
    | idade p1 < idade p2 = menor_idade (p1:ps)
    | idade p1 == idade p2 = menor_idade (p1:ps)


{- nome e estado civil da pessoa mais velha -}
mais_velha :: [Pessoa] -> (String, Char)
mais_velha p = (nome (maior_idade p), estado_civil (maior_idade p))

maior_idade :: [Pessoa] -> Pessoa
maior_idade [p] = p
maior_idade (p1:p2:ps)
    | idade p1 >= idade p2 = maior_idade (p1:ps)
    | idade p1 < idade p2 = maior_idade (p2:ps)


{- todos os dados de cada pessoa com 50 anos ou mais -}
mais_de_50 :: [Pessoa] -> [Pessoa]
mais_de_50 [] = []
mais_de_50 (p:ps)
    | (idade p) >= 50 = [p] ++ mais_de_50 (ps)
    | otherwise = mais_de_50 (ps)


{- numero de pessoas casadas com idade superior a 'i' -}
casadas :: Int -> [Pessoa] -> Int
casadas i [] = 0
casadas i (p:ps)
    | (idade p) > i = 1 + (casadas i ps)
    | otherwise = (casadas i ps)


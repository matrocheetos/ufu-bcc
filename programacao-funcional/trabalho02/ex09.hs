{- a -}
data Estudante =
    Universitario Universidade Curso MatriculaU Altura Idade
    | Colegial Colegio Ano MatriculaC Altura Peso
    deriving (Show)

data Universidade = UFU | UNITRI | UNA deriving (Show)
data Curso = Computacao | Medicina | Direito | Musica deriving (Show)
type MatriculaU = Int
type Altura = Float
type Idade = Int

data Colegio = Nacional | Olimpo | Gabarito deriving (Show)
data Ano = Primeiro | Segundo | Terceiro deriving (Show)
type MatriculaC = String
type Peso = Float

baseDeEstudantes :: [Estudante]
baseDeEstudantes =
    [(Universitario UFU Computacao 43215678 1.71 19),
    (Universitario UFU Medicina 88065521 1.64 23),
    (Universitario UFU Direito 92939495 1.91 22),
    (Universitario UFU Musica 59291029 1.67 22),
    (Universitario UNITRI Computacao 23334678 1.95 18),
    (Universitario UNITRI Direito 34448690 1.82 20),
    (Universitario UNITRI Direito 34558604 1.85 21),
    (Universitario UNA Medicina 10992932 1.59 26),
    (Universitario UNA Medicina 11992478 1.75 22),
    (Universitario UNA Direito 21092283 1.72 27),
    (Colegial Nacional Primeiro "NAACB" 1.82 89),
    (Colegial Nacional Primeiro "NAUBP" 1.64 72),
    (Colegial Nacional Segundo "NAPTJ" 1.71 69),
    (Colegial Nacional Terceiro "NAGKL" 1.67 75),
    (Colegial Olimpo Segundo "OLMFD" 1.91 93),
    (Colegial Olimpo Terceiro "OLSSE" 1.85 80),
    (Colegial Gabarito Primeiro "GAPLK" 1.59 67),
    (Colegial Gabarito Segundo "GANMC" 1.95 84),
    (Colegial Gabarito Segundo "GAXZS" 1.72 75),
    (Colegial Gabarito Terceiro "GAMNE" 1.75 72)]

{- b -}
data Nebuloso = Verdadeiro | Falso | Talvez deriving (Show)
type Talvez = Float

verifica_alto :: Float -> Nebuloso
verifica_alto x
    | alto <= 0 = Falso
    | alto >= 1 = Verdadeiro
    | otherwise = Talvez
        where alto = (x - 1.7) / 0.2

descobre_alto :: [Estudante] -> [(Int,Nebuloso)]
descobre_alto [] = []
descobre_alto (e:es) = ( (matricula e),(verifica_alto (altura e))  ):(descobre_alto es)

matricula :: Estudante -> Int
matricula (Universitario _ _ x _ _ ) = x
matricula (Colegial _ _ x _ _ ) = x
{-
    tipo de matricula do Colegial é "String",
    enunciados dos ex 'a' e 'b' estão em conflito
-}

altura :: Estudante -> Float
altura  (Universitario _ _ _ x _ ) = x
altura  (Colegial _ _ _ x _ ) = x

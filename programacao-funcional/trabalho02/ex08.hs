{- a -}
data Nebuloso = Verdadeiro | Falso | Talvez deriving (Show)
type Talvez = Float

{- b -}
fuzzifica :: Float -> Nebuloso
fuzzifica x
    | x <= 0 = Falso
    | x >= 1 = Verdadeiro
    | otherwise = Talvez

{- c -}
verifica_alto :: Float -> Nebuloso
verifica_alto x
    | alto <= 0 = Falso
    | alto >= 1 = Verdadeiro
    | otherwise = Talvez
        where alto = (x - 1.7) / 0.2

{- d -}
verifica_barato :: Float -> Nebuloso
verifica_barato x
    | barato <= 0 = Falso
    | barato >= 1 = Verdadeiro
    | otherwise = Talvez
        where barato = (50000 - x) / 20000

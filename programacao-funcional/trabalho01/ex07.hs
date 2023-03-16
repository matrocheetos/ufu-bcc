-- funcao de maximo divisor comum auxilia na funcao de minimo multiplo comum
mdc :: Int -> Int -> Int
mdc a 0 = a
mdc a b = mdc b (mod a b)

-- calcula o minimo multiplo comum de tres inteiros
mmc :: Int -> Int -> Int -> Int
mmc a b c
    | a < b = mmc b a c
    | b < c = mmc a c b
    | otherwise = div (a*b) (mdc a (div (b*c) (mdc b c)))
-- mmc eh igual ao produto de dois inteiros dividido pelo mdc desses inteiros

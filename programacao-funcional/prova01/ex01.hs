figura :: Int -> Int -> Int -> String
figura a b c
    | a==b && b==c = "equilatero"
    | a==90 = "retangulo"
    | a>90 = "obtuso"
    | otherwise = "simples"

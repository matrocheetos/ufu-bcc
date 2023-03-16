type Data = (Int, Int, Int)

bissexto2 :: Data -> Bool
bissexto2 (dia,mes,ano)
    | (mod ano 100 /= 0) && (mod ano 4 == 0) = True
    | (mod ano 400 == 0) = True
    | otherwise = False

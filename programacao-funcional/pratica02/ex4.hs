bissexto :: Int -> Bool
bissexto ano
    | (mod ano 100 /= 0) && (mod ano 4 == 0) = True
    | mod ano 400 == 0 = True
    | otherwise = False
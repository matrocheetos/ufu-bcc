-- (a) --
prodIntervalo :: Int -> Int -> Int
prodIntervalo m n
    | m==n = n
    | m>0 && n>0 && m<n = m * prodIntervalo (m+1) n
    | otherwise = 0

-- (b) --
fatorial :: Int -> Int
fatorial n
    | n==0 = 1
    | n>0 = n * prodIntervalo 1 (n-1)
    | otherwise = 0
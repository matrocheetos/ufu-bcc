fatorial_guardas :: Int -> Int
fatorial_guardas n
    | n==0 = 1
    | n/=0 = n * fatorial_guardas (n-1)


fatorial_casamento :: Int -> Int
fatorial_casamento 0 = 1
fatorial_casamento n = n * fatorial_casamento (n-1)
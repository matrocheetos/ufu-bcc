binomial_guardas :: Int -> Int -> Int
binomial_guardas n k
    | k==0 = 1
    | k==n = 1
    | 0<k && k<n = binomial_guardas(n-1) k + binomial_guardas(n-1) (k-1)


binomial_casamento :: Int -> Int -> Int
binomial_casamento n 0 = 1
binomial_casamento n n = 1
binomial_casamento n k = binomial_casamento(n-1) k + binomial_casamento(n-1) (k-1)
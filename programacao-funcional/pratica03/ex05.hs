n_tri :: Int -> Int
n_tri n
    | n==0 = 0
    | n==1 = 1
    | otherwise = n + n_tri(n-1)
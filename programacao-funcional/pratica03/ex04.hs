fibo :: Int -> Int
fibo n
    | n==0 = 0
    | n==1 = 1
    | otherwise = fibo(n-2) + fibo(n-1)
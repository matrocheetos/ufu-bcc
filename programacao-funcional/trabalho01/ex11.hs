unica_ocorrencia :: Int -> [Int] -> Bool
unica_ocorrencia n (x:xs)
    | not (elem n (x:xs)) = False           -- [x,y..]
    | n == x && elem n xs = False           -- [n,n..]
    | n == x && not (elem n xs) = True      -- [n,x,y]
    | otherwise = unica_ocorrencia n xs     -- [x,n,y], n /= x

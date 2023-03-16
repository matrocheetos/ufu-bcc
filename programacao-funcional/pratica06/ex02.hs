-- (a) --

type Data = (Int,Int,Int)

verifica :: Data -> Bool
verifica (dia,mes,ano)
    | dia>=1 && dia<=31 &&
    (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) = True
    | dia>=1 && dia<=30 &&
    (mes==4 || mes==6 || mes==9 || mes==11) = True
    | dia>=1 && dia<=28 && mes==2 = True
    | dia>=1 && dia<=29 && mes==2 &&
    let x = mod ano 100 in x /= 0 &&
    let y = mod ano 4 in y == 0 = True
    | dia>=1 && dia<=29 && mes==2 &&
    let z = mod ano 400 in z == 0 = True
    | otherwise = False

-- (b) --

bissextos :: [Int] -> [Int]
bissextos a = 
    [ b | b<-a,
    let x = mod b 100 in x /= 0 &&
    let y = mod b 4 in y == 0 ||
    let z = mod b 400 in z == 0 ]

-- (c) --

type Emprestimo = (String, String, Data, Data, String)
type Emprestimos = [Emprestimo]

bdEmprestimo :: Emprestimos
bdEmprestimo =
    [("H123C9","BSI945",(12,9,2009),(20,09,2009),"aberto"),   
    ("L433C5","BCC021",(01,9,2009),(10,09,2009),"encerrado"),   
    ("M654C3","BCC008",(04,9,2009),(15,09,2009),"aberto")]


pegaData :: Emprestimo -> Data
pegaData (_,_,_,(ddev,mdev,adev),_) = (ddev,mdev,adev)

atrasados :: Emprestimos -> Data -> Emprestimos
atrasados emprestimo datual = 
    [ x | x<-emprestimo, let dlimite = pegaData x in datual > dlimite ]

-- (d) --

fibStep :: (Int,Int) -> (Int,Int)
fibStep (x,y) = let z = x+y in (y,z)

fibPair :: Int -> (Int,Int)
fibPair 1 = (1,1)
fibPair n = let m = n-1 in fibStep (fibPair m)

fibo2 :: Int -> Int
fibo2 n = fst(fibPair n)

-- (e) --

prodIntervalo :: Int -> Int -> Int
prodIntervalo m n
    | m==n = n
    | m>0 && n>0 && m<n = let x = prodIntervalo (m+1) n in m * x
    | otherwise = 0

fatorial :: Int -> Int
fatorial n
    | n==0 = 1
    | n>0 = let x = prodIntervalo 1 (n-1) in n * x
    | otherwise = 0

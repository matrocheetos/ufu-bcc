-- (a) --

type Data = (Int,Int,Int)

verifica :: Data -> Bool
verifica (dia,mes,ano)
    | dia>=1 && dia<=31 &&
    (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) = True
    | dia>=1 && dia<=30 &&
    (mes==4 || mes==6 || mes==9 || mes==11) = True
    | dia>=1 && dia<=28 && mes==2 = True
    | dia>=1 && dia<=29 && mes==2 && x /= 0 && y == 0 = True
    | dia>=1 && dia<=29 && mes==2 && z == 0 = True
    | otherwise = False
        where x = mod ano 100; y = mod ano 4; z = mod ano 400

-- (b) --

bissextos :: [Int] -> [Int]
bissextos a = [ b | b<-a, mod b x /= 0 && mod b y == 0 || mod b z == 0 ]
    where x = 100; y = 4; z = 400

-- (c) --

type Emprestimo = (String, String, Data, Data, String)
type Emprestimos = [Emprestimo]

bdEmprestimo :: Emprestimos
bdEmprestimo =
    [("H123C9","BSI945",(12,9,2009),(20,09,2009),"aberto"),   
    ("L433C5","BCC021",(01,9,2009),(10,09,2009),"encerrado"),   
    ("M654C3","BCC008",(04,9,2009),(15,09,2009),"aberto")]


pegaData :: Emprestimo -> Data
pegaData (_,_,_,(ddev,mdev,adev),_) = (dia,mes,ano)
    where dia = ddev; mes = mdev; ano = adev

atrasados :: Emprestimos -> Data -> Emprestimos
atrasados emprestimo datual = 
    [ x | x<-emprestimo, datual > pegaData x ]

-- (d) --

fibStep :: (Int,Int) -> (Int,Int)
fibStep (x,y) = (y,z)
    where z = x+y

fibPair :: Int -> (Int,Int)
fibPair 1 = (1,1)
fibPair n = fibStep (fibPair m)
    where m = n-1

fibo2 :: Int -> Int
fibo2 n = fst(fibPair n)

-- (e) --

prodIntervalo :: Int -> Int -> Int
prodIntervalo m n
    | m==n = n
    | m>0 && n>0 && m<n = m * prodIntervalo x n
    | otherwise = 0
        where x = (m+1)

fatorial :: Int -> Int
fatorial n
    | n==0 = 1
    | n>0 = n * prodIntervalo 1 x
    | otherwise = 0
        where x = (n-1)

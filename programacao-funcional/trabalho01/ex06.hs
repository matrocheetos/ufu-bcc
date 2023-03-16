fatores :: Int -> [Int]
fatores x = [ f | f<-[1..x], (mod x f)==0 ]

primos :: Int -> Int -> [Int]
primos x y = [ p | p<-[x..y], p>x, p<y, (fatores p)==[1,p] ]
-- lista de inteiros entre x e y
-- sejam os divisores dos inteiros da lista somente 1 e o proprio inteiro
{- a -}
data Exp = 
    Val Int -- um numero
    | Add Exp Exp -- soma de duas expressoes
    | Sub Exp Exp -- subtração de duas expressoes
    | Mult Exp Exp -- multiplicação
    | Div Exp Exp -- divisão

avalia :: Num a => Exp -> a
avalia (Val x) = (fromIntegral x)
avalia (Add exp1 exp2) = (avalia exp1) + (avalia exp2)
avalia (Sub exp1 exp2) = (avalia exp1) - (avalia exp2)
avalia (Mult exp1 exp2) = (avalia exp1) * (avalia exp2)
avalia (Div exp1 exp2) = fromIntegral (div (avalia exp1) (avalia exp2))

{- b -}
{- e1 = (3+12)*(15-5)/(1*3) e2 = -((6+8-5+1)*(2+6/2)) -}
e1,e2,e3 :: Exp
e1 = (Div (Mult (Add (Val 3) (Val 12)) (Sub (Val 15) (Val 5))) (Mult (Val 1) (Val 3)))
e2 = (Mult (Sub (Val 0) (Val 1)) (Mult (Add (Sub (Add (Val 6) (Val 8)) (Val 5)) (Val 1)) (Add (Val 2) (Div (Val 6) (Val 2)))))
e3 = (Div (Mult (Sub (Add (Val 1) (Val 11)) (Val 2)) (Sub (Val 15) (Val 10))) (Mult (Val 1) (Val 2)))
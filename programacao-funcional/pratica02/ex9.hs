type Data = (Int, Int, Int)
type Emprestimo = (String, String, Data, Data, String)

e1 :: Emprestimo
e1 = ("H123C9","BSI200945",(12,9,2009),(20,9,2009),"aberto")

verifica :: Emprestimo -> Data -> Bool
verifica (codlivro,codaluno,(demp,memp,aemp),(ddev,mdev,adev),situacao) (dia,mes,ano)
    | ano<adev = True
    | ano==adev && mes<mdev = True
    | ano==adev && mes==mdev && dia<=ddev = True
    | otherwise = False
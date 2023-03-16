type Data = (Int, Int, Int)
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
atrasados emprestimo datual = [ x | x<-emprestimo, datual > (pegaData x) ]
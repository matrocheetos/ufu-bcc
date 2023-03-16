type Data = (Int, Int, Int)

idade :: Data -> Data -> Int
idade (dAtual,mAtual,aAtual) (dNasc,mNasc,aNasc)
    | mAtual == mNasc && dAtual >= dNasc = aAtual - aNasc
    | mAtual > mNasc = aAtual - aNasc
    | otherwise = aAtual-1 - aNasc

passagem :: Float -> Data -> Data -> Float
passagem valor_passagem data_atual data_nascimento
    | (idade data_atual data_nascimento) >= 2 && (idade data_atual data_nascimento) <= 10 = 0.40*valor_passagem
    | (idade data_atual data_nascimento) < 2 = 0.15*valor_passagem
    | (idade data_atual data_nascimento) >= 70 = 0.50*valor_passagem
    | otherwise = valor_passagem

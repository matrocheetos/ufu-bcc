-- comprime lista de listas em uma lista
comprime :: [[a]] -> [a]
comprime [l] = l
comprime (x:r) = x++(comprime r)

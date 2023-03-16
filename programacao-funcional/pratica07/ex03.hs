saudacao :: [String] -> [String]
saudacao l = map ("Oi "++) l

-- ghci> saudacao ["Daniel", "Maria","Pedro"]
-- ["Oi Daniel", "Oi Maria","Oi Pedro"]
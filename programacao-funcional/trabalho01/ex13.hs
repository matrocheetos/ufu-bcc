-- recebe duas listas e retorna uma nova listas de sublistas
-- o tamanho da nova lista eh o mesmo da menor das listas recebidas
zipar :: [a] -> [a] -> [[a]]
zipar [] [] = []
zipar x [] = []
zipar [] y = []
zipar (x:xs) (y:ys) = [x,y]:zipar xs ys

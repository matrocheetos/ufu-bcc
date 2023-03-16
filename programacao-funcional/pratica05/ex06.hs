-- lista 1 ++ (lista 2 - elementos ja presentes na lista 1)
uniaoRec2 :: Eq a => [a] -> [a] -> [a]
uniaoRec2 l [] = l
uniaoRec2 l1 (x2:r2) =  if (elem x2 l1)
                        then uniaoRec2 l1 r2
                        else uniaoRec2 (l1++[x2]) r2

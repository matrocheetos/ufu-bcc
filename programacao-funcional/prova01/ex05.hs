dicionario :: [String]
dicionario = ["arara","arreio","haskell", "puxa","peixe","pixar","pixe", "vaca","vacuo","velho","vermelho","vicio"]

representante :: String -> [String] -> [String]
representante [] _ = []
representante _ [] = []
representante (s:ss) (d:ds)
    | elem s d && (representante ss [d]) == [d] = d:(representante (s:ss) ds)
    | otherwise = representante (s:ss) ds

{-
-- gabarito:
representa :: [String] -> String -> [String]
representa [] _ = []
representa (x:xs) padrao =
        if (padrao == eliminavog x)
        then x:(representa xs padrao)
        else (representa xs padrao)

eliminavog :: String -> String
eliminavog [] = []
eliminavog (x:xs) =
    if (x/='a' && x/='e' && x/='i' && x/='o' && x/='u')
    then x:(eliminavog xs)
    else (eliminavog xs)
-}
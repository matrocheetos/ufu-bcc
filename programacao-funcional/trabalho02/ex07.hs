{- a -}
data Jogada = Pedra | Papel | Tesoura
    deriving (Eq, Show)

{- b -}
vence :: Jogada -> Jogada -> Bool
vence Pedra Papel = False
vence Pedra Tesoura = True
vence Papel Tesoura = False
vence Papel Pedra = True
vence Tesoura Pedra = False
vence Tesoura Papel = True
vence _ _ = False

{- c -}
vencedoras :: [(Jogada,Jogada)] -> [Jogada]
vencedoras [] = []
vencedoras ((x,y):zs) =
    if x == y || (vence x y)
    then x:(vencedoras zs)
    else y:(vencedoras zs)

-- (a) --
(||) :: Bool -> Bool -> Bool
True || True = True
False || False = False
_ || _ = True

-- (b) --
ou :: Bool -> Bool -> Bool
ou a b
    if a == True then True else
    if b == True then True else False
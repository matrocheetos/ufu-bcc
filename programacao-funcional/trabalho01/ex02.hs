equacao :: Float -> Float -> Float -> (Float, Float)
equacao a b c
    | a == 0 =  ( (-c)/b, 0 )
    | a /= 0 =  ( ((-b)/(2*a) + sqrt (b*b - 4*a*c) / (2*a)),
                ((-b)/(2*a) - sqrt (b*b - 4*a*c) / (2*a)) )

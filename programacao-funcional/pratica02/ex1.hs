dobro :: Int -> Int
dobro x = 2*x

quad :: Int -> Int
quad x = dobro x + dobro x

hipotenusa :: Float -> Float -> Float
hipotenusa x y = sqrt( x*x + y*y )

distancia :: Float -> Float -> Float -> Float -> Float
distancia x1 x2 y1 y2 = sqrt( (x2-x1)^2 + (y2-y1)^2 )
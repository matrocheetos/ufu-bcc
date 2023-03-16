a = (\x -> x + 3) 5
-- 5 + 3
-- resultado: 8

b = (\x -> \y -> x * y + 5) 3 4
-- 3 * 4 + 5
-- resultado: 17

c = (\(x,y) -> x * y^2) (3,4)
-- 3 * 4^2
-- resultado: 48

d = (\(x,y,_) -> x * y^2) (3,4,2)
-- 3 * 4^2, terceiro elemento é descartado
-- resultado: 48

e = (\xs -> zip xs [1,2,3]) [4,5,6]
-- zip [4,5,6] [1,2,3]
-- resultado: [(4,1),(5,2),(6,3)]

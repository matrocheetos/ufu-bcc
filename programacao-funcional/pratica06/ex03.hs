a = (\x -> 2 * x + 1) 3
-- \x -> 2 * 3 + 1
-- resultado: 81

b = (\x -> \y -> x - y) 5 7
-- \(x,y) -> 5 - 7
-- resultado: (-2)

c = (\y -> \x -> x - y) 5 7
-- \(y,x) -> 7 - 5
-- resultado: 2

d = (\x -> \y -> x - y) (\z -> z / 2)
-- \(z,y) -> z/2 - y

e = (\x -> \y -> x - y) ((\z -> z / 2) 6) 1
-- (\(z,y) -> z/2 - y) (6,1)
-- \(z,y) -> 6/2 - 1
-- resultado: 2

f = (\x -> \y -> x - y) 9 4
-- \xy -> 9 - 4
-- resultado: 5

g = (\x -> x * x) (\y -> y)
-- \y -> y * y

casos :: Int -> String
casos i
    | (mod i 2)==0 && (mod i 3)==0 = "FizzBuzz"
    | mod i 2 == 0 = "Fizz"
    | mod i 3 == 0 = "Buzz"
    | otherwise = "No"

fizzbuzz :: Int -> [String]
fizzbuzz n = [ (casos i) | i<-[1..n] ]
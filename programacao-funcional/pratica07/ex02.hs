prefixos :: [String] -> [String]
prefixos l = map (take 3) l

-- ghci> prefixos ["haskell", "curry"]
-- ["has","cur"]
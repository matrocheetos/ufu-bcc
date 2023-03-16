seque :: Eq a => [a] -> [a] -> Bool
seque [x] [] = True
seque x y
    | reverse (take (length y) (reverse x)) == y = True
    | otherwise = False

-- reverte uma lista polimorfica
reverte :: [a] -> [a]
reverte [] = []
reverte (x:xs) = (reverte xs) ++ [x]

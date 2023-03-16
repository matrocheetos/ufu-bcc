junta_silabas_plural :: [String] -> String
junta_silabas_plural l = foldr (++) "s" l

-- ghci> junta_silabas_plural ["cor","ti","na"]
-- "cortinas"
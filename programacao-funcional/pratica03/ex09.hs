mdc_guardas :: Int -> Int -> Int
mdc_guardas m n
    | n==0 = m
    | n>0 = mdc_guardas n (mod m n)


mdc_casamento :: Int -> Int -> Int
mdc_casamento m 0 = m
mdc_casamento m n = mdc_casamento n (mod m n)
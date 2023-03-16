funcao :: Float -> Int -> Float
funcao x n =
    sum (   
            ([y2/x|y2<- [y1|y1<-[1,3..(fromIntegral n-1)]]])++
            ([x/z2|z2<- [z1|z1<-[2,4..(fromIntegral n)]]])
        )

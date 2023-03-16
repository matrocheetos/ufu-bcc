par(X) :- 0 is mod(X,2).
impar(X) :- 1 is mod(X,2).

assombroso(X) :- X\=0, X\=1, impar(X), X1 is 3*X+1, assombroso(X1);
                 X\=0, X\=1, par(X), X1 is X/2, assombroso(X1);
    			 X==1.
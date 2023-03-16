mult7(X) :- 0 is mod(X,7).

div7(N) :- N>100, Q is N mod 10, R is N-Q*10, N1 is Q-(2*R), mult7(N1).

% multiplos de 7 maiores que 100
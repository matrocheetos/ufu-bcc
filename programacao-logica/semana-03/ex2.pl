digito(0).
digito(1).
digito(2).
digito(3).
digito(4).
digito(5).
digito(6).
digito(7).
digito(8).
digito(9).

somaVaiUm(X,Y,Vem,Z,Vai) :- T is X+Y+Vem, Vai is T//10, Z is mod(T,10).

% A B C
%   A 3
% A C B

criptograma(A,B,C) :-
    digito(A),digito(B),digito(C),
    A>0,
    somaVaiUm(C,3,0,B,V1),
    somaVaiUm(B,A,V1,C,V2),
    somaVaiUm(A,0,V2,A,V3),
    V3 is 1.
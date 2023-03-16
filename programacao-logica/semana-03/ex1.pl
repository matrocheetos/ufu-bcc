somaDigito(X,X) :- X<10.
somaDigito(X,Y) :- X>=10, X1 is X//10, X2 is X mod 10, somaDigito(X1,Y1), Y is Y1+X2.

% conta quantos digitos,
% pega cada digito,
% soma os digitos ate acabar o numero.
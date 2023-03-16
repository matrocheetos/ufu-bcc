% Exercício 4.3 da apostila
% a)
estrada(a, b, 25).
estrada(a, d, 23).
estrada(b, c, 19).
estrada(b, e, 32).
estrada(c, d, 14).
estrada(c, f, 28).
estrada(d, f, 30).
estrada(e, f, 26).

% b)
dist(A, B, D) :- estrada(A, B, D).
dist(A, B, D) :- estrada(A, C, Dd), dist(C, B, Ddd), D is Dd+Ddd.

% consulta:
%  dist(a,f,D).
% resultado:
%  D = 72 ;
%  D = 88 ;
%  D = 83 ;
%  D = 53 ;
%  false.
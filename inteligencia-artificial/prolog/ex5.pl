% Exercício 5.8 da apostila
% a)
estrada(1, a, b).
estrada(2, a, d).
estrada(3, b, c).
estrada(4, c, d).
estrada(5, b, e).
estrada(6, c, f).
estrada(7, d, f).
estrada(8, e, f).

% b)
rota(A, B, R) :- estrada(Rr, A, B), R = [Rr].
rota(A, B, R) :- estrada(Rr, A, C), rota(C, B, Rrr), R=[Rr|Rrr].

% consulta:
%  rota(a,f,R).
% resultado:
%  R = [1, 3, 6] ;
%  R = [1, 3, 4, 7] ;
%  R = [1, 5, 8] ;
%  R = [2, 7] ;
%  false.
% Exercício 3.4 da apostila
% programa considerado:
animal(cao).
animal(canario).
animal(cobra).
animal(morcego).
animal(gaivota).

voa(canario).
voa(morcego).
voa(gaivota).

dif(X,X) :- !, fail.
dif(_,_).
passaro(X) :- animal(X), voa(X), dif(X,morcego).

% consulta:
%  passaro(X).
% resultado:
%  X = canario ;
%  X = gaivota.
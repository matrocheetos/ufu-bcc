% Exercício 1.2 da apostila
% a)
fato(ana, mae).
fato(ivo, pai).
fato(eva, mae).
fato(rai, pai).
fato(bia, mae).
fato(gil, pai).
fato(ary, pai).
fato(lia, mae).

% consultas:
%  fato(P,pai).
%  fato(M,mae).

% ========
% b)
mulher(ana).
mulher(eva).
mulher(bia).
mulher(lia).
mulher(clo).
mulher(gal).

homem(ivo).
homem(rai).
homem(gil).
homem(ary).
homem(noe).

% ========
% c)
gerou(ana, eva).
gerou(ivo, eva).

gerou(bia, rai).
gerou(bia, clo).
gerou(bia, ary).
gerou(gil, rai).
gerou(gil, clo).
gerou(gil, ary).

gerou(eva, noe).
gerou(rai, noe).

gerou(ary, lia).
gerou(lia, gal).

% consultas:
%  gerou(bia, Y).
%  gerou(X, noe).

% ========
% d)
filho(X,Y) :- homem(X), gerou(Y,X).
filha(X,Y) :- mulher(X), gerou(Y,X).
tio(X,Y) :- homem(X), gerou(I,Y), gerou(P,I), gerou(P,X).
tia(X,Y) :- mulher(X), gerou(I,Y), gerou(P,I), gerou(P,X).
primo(X,Y) :- homem(X), gerou(PX,X), gerou(PY,Y), gerou(PP,PX), gerou(PP,PY).
prima(X,Y) :- mulher(X), gerou(PX,X), gerou(PY,Y), gerou(PP,PX), gerou(PP,PY).
avoH(X,Y) :- homem(X), gerou(X,F), gerou(F,Y).
avoM(X,Y) :- mulher(X), gerou(X,F), gerou(F,Y).

% em relação a X:
% I = irmao
% P = pai
% F = filho
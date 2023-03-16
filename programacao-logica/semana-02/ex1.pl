fato(joao,rico).
fato(joao,famoso).
fato(maria,famoso).
fato(pedro,rico).


eh_feliz(X) :- fato(X,rico); fato(X,famoso).
% verifica se 'X' é rico ou famoso
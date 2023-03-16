:- use_module(library(clpb)).

a(A,X) :-   elemento(A,A1), %escolhe um elemento da lista
            sat( X =:= (X=:=A1) ), %verifica elemento
            a(A1,X). %continua a leitura da lista
a([],X). %verificacao tem que parar

% elemento([], []).
% elemento([E|T], [E|T1]) :- elemento(T, T1).
% elemento([_|T], T1) :- elemento(T, T1).
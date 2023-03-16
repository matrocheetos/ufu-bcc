conjunto([], []).
conjunto([H|T], [H|T1]) :- conjunto(T, T1).
conjunto([_|T], T1) :- conjunto(T, T1).

soma([], 0).
soma([X | T], Soma) :- soma(T, Ts), Soma is Ts + X.

sss(Conjunto, Soma, X) :- conjunto(Conjunto, X), soma(X, Soma).








subsetsum(Conjunto, Soma, Resultado) :-
    % Find a subset
    subset(Conjunto, Resultado),
    % Check elements of the subset add up to SUM
    soma(Resultado, Soma).

% sum(LIST, SUM) - sums all numbers in the list
soma([], 0).
soma([X | T], Soma) :-
    soma(T, Tsoma),
    Soma is Tsoma + X.

% subset - finds subsets
subset([], []).
subset([E|T], [E|T1]) :-
    subset(T, T1).
subset([_|T], T1) :-
    subset(T, T1).




subsetsum(SET, SUM, ANSWER) :-
    % Find a subset
    subset(SET, ANSWER),
    % Check elements of the subset add up to SUM
    sum(ANSWER, SUM).

% sum(LIST, SUM) - sums all numbers in the list
sum([], 0).
sum([X | T], SUM) :-
    sum(T, TAILSUM),
    SUM is TAILSUM + X.

% subset - finds subsets
subset([], []).
subset([E|Tail], [E|NTail]) :-
    subset(Tail, NTail).
subset([_|Tail], NTail) :-
    subset(Tail, NTail).
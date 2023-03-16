elemento([], []).
elemento([E|T], [E|T1]) :- elemento(T, T1).
elemento([_|T], T1) :- elemento(T, T1).

soma([], 0).
soma([X | T], Soma) :- soma(T, Tsoma), Soma is Tsoma + X.

somaPar(Elemento, Soma, X) :- elemento(Elemento, X), soma(X, Soma).


??
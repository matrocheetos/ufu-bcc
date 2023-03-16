
soma([], 0).
soma([X | T], Soma) :- soma(T, Tsoma), Soma is Tsoma + X.

super([]).
super([_|T]) :- elemento(T,T1), % pega elementos anteriores da lista
                soma(T1,X),     % soma esses elementos
                % Y é um elemento sucessor a ser verificado,
                Y >= X,         % faz a verificação supercrescente
                super(T1).      % continua a verificacao

elemento([], []).
elemento([H|T], [H|T1]) :- elemento(T, T1).
elemento([_|T], T1) :- elemento(T, T1).
p(1).
p(2).
p(3).
p(4).
p(5).
p(6).


c([L1,C1],[L2,C2]) :-   p(L1),p(L2),p(C1),p(C2), L2 is L1 +1, C2 is C1 +2;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 +1, C2 is C1 -2;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 -1, C2 is C1 +2;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 -1, C2 is C1 -2;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 +2, C2 is C1 +1;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 +2, C2 is C1 -1;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 -2, C2 is C1 +1;
                        p(L1),p(L2),p(C1),p(C2), L2 is L1 -2, C2 is C1 -1.


c_abs([L1,C1],[L2,C2]) :-   p(L1),p(L2),p(C1),p(C2), 1 =:= abs(L1-L2), 2 =:= abs(C1-C2);
                            p(L1),p(L2),p(C1),p(C2), 2 =:= abs(L1-L2), 1 =:= abs(C1-C2).


tamanho([],0).
tamanho([_|T], X) :- tamanho(T,Tx), X is Tx +1.

contem(X, [X|_]).
contem(X, [_|Y]) :- contem(X, Y).

tour([],R) :- tour([[1,1]],R).

tour([H|T],R) :- tamanho([H|T],Tamanho), Tamanho < 36, c(H,N), \+contem(N,T), tour([N|T],R).

tour([H|T],[H|T]) :- tamanho([H|T], Tamanho), Tamanho == 36, c([H|T],T).
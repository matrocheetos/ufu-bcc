intercala(X1, [], X1).
intercala([], Y1, Y1) :- !.
intercala([X|X1], [Y|Y1], [X|R1]) :- X =< Y, intercala(X1, [Y|Y1], R1).
intercala([X|X1], [Y|Y1], [Y|R1]) :- intercala([X|X1], Y1, R1).
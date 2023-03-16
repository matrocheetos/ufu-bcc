get([X|_],1,X) :- !.
get([_|T],A,X) :- A>0, A1 is A-1, get(T,A1,X).
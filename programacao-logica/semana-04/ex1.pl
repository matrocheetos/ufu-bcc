jumpingFrog(_,[_]) :- !.
jumpingFrog(N,[H,H1|T]) :- 
    N>=abs(H-H1),
    jumpingFrog(N,[H1|T]).
%N é tamanho do salto

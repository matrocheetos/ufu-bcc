%remove um numero
a([],[],_). %lista vazia

a([H1|T1],T,A) :-   H1 = ([A,B]),           %se o numero a ser removido estiver em um intervalo,
                    A1 is A+1,              %aumenta o intervalo
                    a([[A1,B]|T1],T,A).     %passa lista sem esse elemento
a([H1|T1],T,A) :-   H1 = ([B,A]),           
    				A1 is A-1,              %diminui o intervalo
                    a([[B,A1]|T1],T,A).

a([H|T1],[H|T2],A) :-   H \= [A,_],     %se o numero nao estiver no intervalo
                        a(T1,T2,A).     %continua a lista
a([H|T1],[H|T2],A) :-   H \= [_,A],
                        a(T1,T2,A).

%exemplo:
%   entrada:	a([[1,3],[5,6],[9,10]], A, 5).
%   saída:		A = [[1, 3], [6, 6], [9, 10]]


% -----------------------


b([],[],[]).    %listas vazias
b([X],[],[X]).  %segunda lista vazia
b([],[Y],[Y]).  %primeira lista vazia

b([[X1,X2]|L1],[[X1,Y2]|L2],L) :-	%[1,X],[1,Y] -> [1,Maior]
    maior(X2,Y2,Maior),
    b(L1,[[X1,Maior]|L2],L).

b([[X1,X2]|L1],[[Y1,X2]|L2],L) :-	%[X,1],[Y,1] -> [Maior,1]
    menor(X1,Y1,Menor),
    b(L1,[[Menor,X2]|L2],L).

b([[X1,X2]|L1],[[Y1,Y2]|L2],L) :-
    X1 < Y1, X2 > Y2,
    b([[X1,X2]|L1],L2,L);				%[1,10],[2,9] -> [1,10]
    Y1 < X1, Y2 > X2,
    b([[Y1,Y2]|L1],L2,L);				%[2,9],[1,10] -> [1,10]
    X1 =:= Y1, maior(X2,Y2,Maior),
    b([[X1,Maior]|L1],L2,L);			%[10,11],[10,13] -> [10,13]
    X2 =:= Y2, menor(X1,Y1,Menor),
    b([[Menor,X2]|L1],L2,L);			%[5,12],[7,12] -> [5,12]
	X2 =:= Y1,
    b([[X1,Y2]|L1],L2,L).				%[5,12],[12,15] -> [5,15]

b([[X1,X2]|L1],[[Y1,Y2]|L2],[[X1,X2]|L]) :-	%[3,X],[5,Y],[3,X]
    X1 < Y1,
    b(L1,[[Y1,Y2]|L2],L).

b([[X1,X2]|L1],[[Y1,Y2]|L2],[[Y1,Y2]|L]) :-	%[X1,X2],[Y1,Y2],[Y1,Y2]
    b([[X1,X2]|L1],L2,L).

maior(A,B,C) :- 
    A>=B, C is A;
    A<B, C is B.

menor(A,B,C) :- 
    A>=B, C is B;
    A<B, C is A.

%exemplo:
%   entrada:    b([[1,3],[5,6]], [[1,10],[10,13]], A).
%   saída:      A = [[1, 13]]
%   entrada:    b([[1,3],[5,9]],[[9,10],[11,13]],A).
%   saída:      A = [[1, 3], [5, 10], [11, 13]]

%ta meio errado! LOL

% -----------------------


c([X1,X2],[[Y1,Y2]|L1],L) :-
    converte([[Y1,Y2]|L1],Z),   %converte os intervalos em uma lista com todos os elementos
    intersecao([X1,X2],Z,L).    %verifica a interseção do intervalo com a lista de intervalos

converte([[Y1,Y2]|L],Z) :-
    Y1=<Y2,                         
    Y3 is Y1+1,
    converte([[Y3,Y2]|L],[Y1|Z]);   %avança o intervalo e adiciona os elementos à lista
    Y1>Y2,                          %quando acaba um intervalo, passa para o prox.
    converte(L,Z).
converte([],_).

intersecao([X|Y],M,[X|Z]) :-
    membrolista(X,M), intersecao(Y,M,Z).
intersecao([X|Y],M,Z) :-
    \+membrolista(X,M), intersecao(Y,M,Z).
intersecao([],_,[]).

membrolista(X,[X|_]).
membrolista(X,[_|T]) :-
    membrolista(X,T).

% a lista nao voltou pra 'c' 
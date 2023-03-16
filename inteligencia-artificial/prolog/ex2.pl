% Exercício 2.2 da apostila
% informações da tabela:
codigo(4, leo).
codigo(5, clo).
codigo(6, gil).

recebe(leo, 2500.35).
recebe(clo, 1800.00).
recebe(gil, 1100.00).

dependente(lia, leo).
dependente(noe, leo).
dependente(eli, clo).

% a)
condicaoA(A) :- recebe(A, X), X > 1500.00, X < 3000.00 .

% b)
condicaoB(B) :- not(dependente(_, B)), recebe(B, Y), Y < 1200.00 .

% c)
condicaoC(C) :- dependente(_, C), recebe(C, X), X > 1700.00 .
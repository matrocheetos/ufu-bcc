
% =================================================
% modulo utilizado para "transpose"
% "transpose" transforma as colunas do tabuleiro em linhas,
% facilitando a impressão do tabuleiro
:- use_module(library(clpfd)).

% =================================================
% "connect4(tabuleiro(T))" recebe um tabuleiro (coluna(7) , linha(6)) vazio/parcialmente preenchido/inteiramente preenchido
% verifica se o tabuleiro está no formato adequado, imprime o tabuleiro inicial na tela e inicia as operações para determinar todas as possíveis soluções
connect4(T) :-
    tabuleiro(T),
    write('Tabuleiro inicial:'),
    imprime(T),
    movimenta(1,T).

% =================================================
% tabuleiro (coluna(7) , linha(6)) p/ facilitar operação de inserção da peça
% deve ser preenchido com: 0(vazio), 1(jogador1) ou 2(jogador2)
tabuleiro([ [_,_,_,_,_,_],
            [_,_,_,_,_,_],
            [_,_,_,_,_,_],
            [_,_,_,_,_,_],
            [_,_,_,_,_,_],
            [_,_,_,_,_,_],
            [_,_,_,_,_,_] ]).


%   TABULEIRO:
%   A1,A2,A3,A4,A5,A6 – coluna A
%   B1,B2,B3,B4,B5,B6 – coluna B
%   C1,C2,C3,C4,C5,C6 – coluna C
%   D1,D2,D3,D4,D5,D6 – coluna D
%   E1,E2,E3,E4,E5,E6 – coluna E
%   F1,F2,F3,F4,F5,F6 – coluna F
%   G1,G2,G3,G4,G5,G6 – coluna G

% colunas possíveis:
coluna(0).
coluna(1).
coluna(2).
coluna(3).
coluna(4).
coluna(5).
coluna(6).

% =================================================
% imprime o tabuleiro na tela

imprime(T) :-
    transpose(T,ImprimeT), nl,
    imprime_linha(ImprimeT), nl.

imprime_linha([]).
imprime_linha([Linha|Linhas]) :-
    write(' '),
    imprime_elemento(Linha), nl,
    imprime_linha(Linhas).

imprime_elemento([]).
imprime_elemento([Elemento|Elementos]) :-
    write(Elemento),
    write(' '),
    imprime_elemento(Elementos).

% =================================================
% verifica se jogador J ganha no tabuleiro T em alguma das condições
% "append" é utilizado para buscar os elementos especificados

% linha:
ganha(J,T) :-
    append(_,[C1,C2,C3,C4|_],T),    %procura 4 colunas conectadas
    append(P1,[J|_],C1),
    append(P2,[J|_],C2),
    append(P3,[J|_],C3),
    append(P4,[J|_],C4),            %procura 4 peças iguais nessas colunas
    length(P1,X), length(P2,X),
    length(P3,X), length(P4,X).     %verifica se as peças estão na mesma linha

% coluna:
ganha(J,T) :-
    append(_,[C|_],T),          %procura uma coluna
    append(_,[J,J,J,J|_],C).    %procura 4 peças seguidas na coluna

% diagonal principal
ganha(J,T) :-
    append(_,[C1,C2,C3,C4|_],T),        %procura 4 colunas conectadas
    append(P1,[J|_],C1),
    append(P2,[J|_],C2),
    append(P3,[J|_],C3),
    append(P4,[J|_],C4),                %procura 4 peças iguais nessas colunas
    length(P1,X1), length(P2,X2),
    length(P3,X3), length(P4,X4),
    X2 is X1+1, X3 is X2+1, X4 is X3+1. %verifica se as peças estão na mesma diagonal

% diagonal secundaria
ganha(J,T) :-
    append(_,[C1,C2,C3,C4|_],T),        %procura 4 colunas conectadas
    append(P1,[J|_],C1),
    append(P2,[J|_],C2),
    append(P3,[J|_],C3),
    append(P4,[J|_],C4),                %procura 4 peças iguais nessas colunas
    length(P1,X1), length(P2,X2),
    length(P3,X3), length(P4,X4),
    X2 is X1-1, X3 is X2-1, X4 is X3-1. %verifica se as peças estão na mesma diagonal

cheio(T) :-
    \+ ( append(_,[C|_],T), append(_,[0|_],C) ).    %tabuleiro está cheio se nenhuma posição for 0 (vazio)

% =================================================
% movimentos:
%movimenta(J,T), J = jogador, T = tabuleiro

% procura empate ou ganhadores
movimenta(_,T) :-
    cheio(T),
    write('Empate!'),nl,
    write('Tabuleiro final:'),
    imprime(T).
movimenta(1,T) :-
    ganha(2,T),
    write('Jogador 2 ganhou!'),nl,
    write('Tabuleiro final:'),
    imprime(T).
movimenta(2,T) :-
    ganha(1,T),
    write('Jogador 1 ganhou!'),nl,
    write('Tabuleiro final:'),
    imprime(T).
% ainda não acabou a partida, faz o movimento
% do jogador 1
movimenta(1,T) :-
    jogador(1,2,T,T1),
    movimenta(2,T1).
% do jogador 2
movimenta(2,T) :-
    jogador(2,1,T,T1),
    movimenta(1,T1).

% =================================================
% comportamento do jogador (computador):

% operações auxiliares:
% verifica se T2 é igual a T com uma nova peça do jogador J na coluna Cj
jogaPeca(J,Cj,T,T2):-
    append(I,[C|F],T),
	length(I,Cj),
	jogaPecaColuna(J,C,C2),
	append(I,[C2|F],T2).


% verifica se Coluna2 é igual a Coluna1 depois do jogador J
%jogaPecaColuna(J,Coluna1,Coluna2)
jogaPecaColuna(J,[0,A|AS],[J,A|AS]):- A \== (0), !.          % joga em cima de outra peça
jogaPecaColuna(J,[0|AS],[0|AS2]):- jogaPecaColuna(J,AS,AS2). % percorre a coluna
jogaPecaColuna(J,[0],[J]):- !.                               % última posição na coluna

%jogador_regras(P,T,C,T2)
%P = jogador, T = tabuleiro, C = coluna, T2 = novo tabuleiro
% verdadeiro se P joga na coluna C do T e consegue ganhar em T2
jogador_regras(P,T,C,T2):-
    findall( (Col,TA),
            (coluna(Col), jogaPeca(P,Col,T,TA), ganha(P,TA)),
            [(C,T2)|_] ).

%--------------------------
%jogador(P1,P2,T,T2)
%P1 = peça do jogador 1, P2 = peça do jogador 2, T = tabuleiro, T2 = novo tabuleiro
% falta 1 para fazer uma sequencia, ganha
jogador(P1,_,T,T2) :-
    jogador_regras(P1,T,_,T2).

% não deixa o jogador 2 ganhar
jogador(P1,P2,T,T2) :-
    findall( (Col,TA),
            (coluna(Col), jogaPeca(P1,Col,T,TA), \+jogador_regras(P2,TA,_,_)),
            [(_,T2)|_] ).

% tenta impedir uma possível sequência do oponente
% somente o jogador 1 considera essa opção
jogador(1,2,T,T2) :-
    jogador_regras(2,T,C,_),
    jogaPeca(1,C,T,T2).

% sem prioridades, joga em qualquer posição
jogador(P1,_,T,T2) :-
    coluna(C),
    jogaPeca(P1,C,T,T2).

% =================================================
% exemplo de entrada:
% connect4([ [0,0,0,0,0,0],
%             [0,0,0,0,0,0],
%             [0,0,0,0,0,0],
%             [0,0,0,0,0,1],
%             [0,0,0,0,0,2],
%             [0,0,0,0,0,0],
%             [0,0,0,0,0,0] ]).
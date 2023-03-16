:- use_module(library(clpb)).

knight(A) :- sat( A =:= (A=:=1) ).

knave(A) :- sat( A \= (A=:=1)). % pode ta certo ou nao= kllklk

% pelo menos um cafajeste, considerando A sendo cavaleiro ou nao
a(A,B,C) :- sat( ( A =:= (A=:=1) + (B=:=0) ) + ( A =:= (A=:=1) + (C=:=0) ) ).


b(A,B,C) :- sat(    ( A =:= (A=:=0) * (B=:=0) * (C=:=0) ) +     % todos cafejestes
                    ( B =:= (A=:=1) * (B=:=0) * (C=:=0) ) +     % dois cafajestes
                    ( B =:= (A=:=0) * (B=:=1) * (C=:=0) ) +     % dois cafajestes
                    ( B =:= (A=:=0) * (B=:=0) * (C=:=1) ) ).    % dois cafajestes


c(A,B,C) :- sat(    (A =:= (A=:=1)*(B=:=0)) +           % A diz que B é cafajeste
                    (B =:= (B=:=1)*(A=:=1)*(C=:=1)) +   % B diz A e C sao do mesmo tipo
                    (B =:= (B=:=1)*(A=:=0)*(C=:=0)) ).  % B diz A e C sao do mesmo tipo
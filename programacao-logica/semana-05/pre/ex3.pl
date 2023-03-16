binary_number(Bin, N) :-
    binary_number(Bin, 0, N).

binary_number([], N, N).
binary_number([Bit|Bits], Acc, N) :-
    Acc1 is Acc*2 + Bit,
    binary_number(Bits, Acc1, N).




binario([],N,N) :- !.
binario([H|T],X,N) :- 
    % X deve comecar em 0
    H1 is X*2+H,
    binario(T,H1,N).
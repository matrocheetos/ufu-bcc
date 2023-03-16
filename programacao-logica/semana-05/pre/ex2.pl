sequencia(P1,P2,P3) :- P1 == P2, P2 == P3.

tabuleiro(L1C1,L1C2,L1C3,L2C1,L2C2,L2C3,L3C1,L3C2,L3C3,V) :- 
    sequencia(L1C1,L1C2,L1C3), L1C1 \= v, V = L1C1;
    sequencia(L2C1,L2C2,L2C3), L2C1 \= v, V = L2C1;
    sequencia(L3C1,L3C2,L3C3), L3C1 \= v, V = L3C1;
    sequencia(L1C1,L2C1,L3C1), L1C1 \= v, V = L1C1;
    sequencia(L1C2,L2C2,L3C2), L1C2 \= v, V = L1C2;
    sequencia(L1C3,L2C3,L3C3), L1C3 \= v, V = L1C3;
    sequencia(L1C1,L2C2,L3C3), L1C1 \= v, V = L1C1;
    sequencia(L1C3,L2C2,L3C1), L1C3 \= v, V = L1C3.

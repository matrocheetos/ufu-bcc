palavras(bala,b,a,l,a).
palavras(cama,c,a,m,a).
palavras(alta,a,l,t,a).
palavras(anta,a,n,t,a).

cruzada(H1,H2,V1,V2) :- palavras(H1,H1L1,H1L2,H1L3,H1L4),
                        palavras(H2,H2L1,H2L2,H2L3,H2L4),
                        palavras(V1,V1L1,V1L2,V1L3,V1L4),
                        palavras(V2,V2L1,V2L2,V2L3,V2L4),
                        H1L2 == V1L2,
                        H1L4 == V2L1,
                        H2L1 == V1L4,
                        H2L3 == V2L3,
                        H1\=H2,H1\=V1,H1\=V2,
                        H2\=V1,H2\=V2,
                        V1\=V2.

% CORRIGIDO:

cruzada(H1,H2,V1,V2) :- palavras(H1,_,H1L2,_,H1L4),
                        palavras(H2,H2L1,_,H2L3,_),
                        palavras(V1,_,V1L2,_,V1L4),
                        palavras(V2,V2L1,_,V2L3,_),
                        H1L2 == V1L2,
                        H1L4 == V2L1,
                        H2L1 == V1L4,
                        H2L3 == V2L3,
                        H1\=H2,H1\=V1,H1\=V2,
                        H2\=V1,H2\=V2,
                        V1\=V2.
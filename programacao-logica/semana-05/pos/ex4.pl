cor(azul).
cor(vermelho).
cor(verde).
cor(amarelo).
cor(preto).
cor(branco).

dica(S,T,B,V) :- brancos(S,T,B), vermelhos(S,T,V).

%cor mas na posicao errado
brancos(S,T,B) :- cor(S), cor(T), S=:=T, \+mesmaposicao(T,S), brancos(S,T,Bx), B is Bx +1.

%cor na posicao certa
vermelhos(S,T,V) :- cor(S), cor(T), mesmaposicao(T,S), vermelhos(S,T,Vx), V is Vx+1.

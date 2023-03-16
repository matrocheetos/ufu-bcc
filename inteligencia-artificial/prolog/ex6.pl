% Exercício 6.4 da apostila
pos(robo, garagem).
pos(tv, sala).

ande(Dest) :- not(pos(robo, Dest)), tell(robo), listing(pos), told.
pegue(Obj) :- pos(robo, LocAtual), pos(Obj, LocAtual).
solte(Obj) :- tell(Obj,pos(robo,_)), listing(pos), told.
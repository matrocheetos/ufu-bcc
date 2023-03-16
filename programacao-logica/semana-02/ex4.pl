ladrao(pedro).
ladrao(marcelo).

gosta(pedro,futebol).
gosta(marcelo,basquete).

gosta(maria,futebol).
gosta(ana,futebol).
% pedro pode roubar maria e ana

gosta(lucas,basquete).
gosta(joao,basquete).
% marcelo pode roubar lucas e joao


poderoubar(X,Y) :- ladrao(X),\+ladrao(Y),gosta(X,Z),gosta(Y,Z).
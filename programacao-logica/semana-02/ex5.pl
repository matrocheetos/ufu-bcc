influencer(pedro).
influencer(ana).

likes(pedro,sorvete).
likes(pedro,tomate).
likes(pedro,abacaxi).
likes(ana,panetone).
likes(ana,tomate).
likes(ana,abacaxi).
likes(maria,sorvete).

gosta(X,A) :- \+influencer(X), % 'X' não é influencer
              influencer(Y),influencer(Z),Y \== Z, % procura dois influencers diferentes
              likes(Y,A),likes(Z,A). % verifica se influencers gostam de 'A'
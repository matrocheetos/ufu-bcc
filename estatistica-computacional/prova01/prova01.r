#questao 1
chicago <- read.csv("chicago.csv")
str(chicago)

#a

doencas_cardio <- chicago$cvd
doencas_cardio

cardio_verao <- chicago$season == "Summer"
cardio_inverno <- chicago$season == "Winter"
cardio_outono <- chicago$season == "Autumn"
cardio_primavera <- chicago$season == "Spring"

verao <- chicago[cardio_verao, -11] #remove coluna 'season'
inverno <- chicago[cardio_inverno, -11]
outono <- chicago[cardio_outono, -11]
primavera <- chicago[cardio_outono, -11]

nrow(verao)
nrow(inverno)
nrow(outono)
nrow(primavera)

menos_violento <- chicago[order(chicago$cvd)[1],]$season
menos_violento
mais_violento <- chicago[order(chicago$cvd)[nrow(chicago)],]$season
mais_violento

estacoes <- c()
estacoes <- list(nrow(verao), nrow(inverno), nrow(outono), nrow(primavera))
menos_violento <- tail(estacoes)
mais_violento <- head(estacoes)

#b
sum(chicago$resp)
chicago[sum(chicago$resp),]$year
resp_ano <- chicago[sum(chicago$resp),]$year
resp_ano

chicago[max(chicago$resp),]$year

#c
#media temp:
mean(verao$temp)
mean(inverno$temp)
mean(outono$temp)
mean(primavera$temp)
#media umidade:
mean(verao$rhum)
mean(inverno$rhum)
mean(outono$rhum)
mean(primavera$rhum)
#boxplot:
boxplot(verao$temp, inverno$temp, outono$temp, primavera$temp, names = c("verao", "inverno", "outono", "primavera"))

#d
plot(chicago$time, chicago$temp, type="p")
points(verao$time, verao$temp, pch=16, col="red")
points(inverno$time, inverno$temp, pch=16, col="blue")
points(outono$time, outono$temp, pch=16, col="yellow")
points(primavera$time, primavera$temp, pch=16, col="green")


#questao 2
#cartas:
#de 1 a 13 = azul
#de 14 a 26 = vermelho
#de 27 a 39 = amarelo
#de 40 a 52 = verde
numera_carta = function(n) {
  if(n>=14 && n<=26){
    n <- n-13
  } else if (n>=27 && n<=39) {
    n <- n-26
  } else if (n>=40 && n<=52) {
    n <- n-39
  }
    n
}
cor_carta = function(n) {
  if(n>=1 && n<=13) {
    n <- "azul"
  }else if(n>=14 && n<=26) {
    n <- "vermelho"
  } else if (n>=27 && n<=39) {
    n <- "amarelo"
  } else if (n>=40 && n<=52) {
    n <- "verde"
  }
  n
}

#a
monteCarlo <- c()
for(i in 1:100000){
  cartas <- sample(1:52, size=3, replace=FALSE)
  #vetor card armazena quais cartas sao verdes:
  card <- c()
  for(j in 1:3) {
    if(cor_carta(cartas[j]) == "verde") {
      card[j] <- TRUE
    } else {
      card[j] <- FALSE
    }
  }
  #qtd de cartas verdes:
  verif <- sum(card, na.rm=TRUE)
  if(verif == 2) {
    monteCarlo[i] <- 1
  } else {
    monteCarlo[i] <- 0
  }
}
probA <- sum(monteCarlo)/100000
probA

#b
monteCarlo <- c()
for(i in 1:100000){
  cartas <- sample(1:52, size=3, replace=FALSE)
  if(numera_carta(cartas[3]) == 8) {
    monteCarlo[i] <- 1
  } else {
    monteCarlo[i] <- 0
  }
}
probB <- sum(monteCarlo)/100000
probB

#c
monteCarlo <- c()
for(i in 1:100000){
  cartas <- sample(1:52, size=3, replace=FALSE)
  c1 <- numera_carta(cartas[1])
  c2 <- numera_carta(cartas[2])
  c3 <- numera_carta(cartas[3])
  if(c1==c2 && c2==c3) {
    monteCarlo[i] <- 1
  } else {
    monteCarlo[i] <- 0
  }
}
probC <- sum(monteCarlo)/100000
probC

#d
monteCarlo <- c()
for(i in 1:100000){
  cartas <- sample(1:52, size=3, replace=FALSE)
  if(cartas[1]>=14 && cartas[1]<=26 && cartas[2]>=14 && cartas[2]<=26) {
    monteCarlo[i] <- 1
  } else {
    monteCarlo[i] <- 0
  }
}
probD <- sum(monteCarlo)/100000
probD

#e
monteCarlo <- c()
for(i in 1:100000){
  carta <- sample(1:52, size=1)
  carta1 <- cor_carta(carta)
  if(carta1 == "verde") {
    #se for verde:
    carta <- sample(1:58, size=1)
  } else {
    #se nao for verde:
    carta <- sample(1:69, size=1)
  }
  #verifica se a segunda carta é amarela:
  if(carta == "amarelo") {
    monteCarlo[i] <- 1
  } else {
    monteCarlo[i] <- 0
  }
}
probE <- sum(monteCarlo)/100000
probE

#f
monteCarlo <- c()
for(i in 1:100000){
  nro_cartas <- 0
  while(1) {
    carta <- sample(1:52, size=1, replace=FALSE)
    nro_cartas <- nro_cartas+1
    if(numera_carta(carta)==3) {
      while(1) {
        carta <- sample(1:52, size=1, replace=FALSE)
        nro_cartas <- nro_cartas+1
        if(numera_carta(carta)==3) {
          monteCarlo[i] <- nro_cartas
          break
        }
      }
      break
    }
  }
}
mediaF <- mean(monteCarlo)
mediaF
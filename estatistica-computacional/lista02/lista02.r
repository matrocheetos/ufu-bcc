# lista 02 - estc

#---exercicio 01---
#a
a1 <- c(1:20) 
a1

#b
b1 <- c(20:1)
b1

#c
c1 <- c(1:20, 19:1) 
c1

#d
d1 <- rep(c(4,6,3), 12)
d1

#e
e1 <- rep(c(4,6,3), 13, length.out = (3 * 13) - 2)
e1 <- c(e1, 4)
e1

#f
f1 <- seq(3,6, by=0.1)
f1 <- exp(f1)*cos(f1)
f1

#---exercicio 02---
#a
fa2 = function(x) {
  x^3 + 4*(x^2)
}
a2 = sum(fa2(c(10:100)))
a2

#b
fb2 = function(x) {
  2^x/x + 3^x/x^2
}
b2 = sum(fb2(10:25))
b2

#---exercicio 03---
xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
a3 = xVec[xVec %% 2 != 0]
a3

#b
b3 = yVec[-1] - xVec[-length(xVec)]
b3

#c
c3 = sin(yVec[-1])/cos(xVec[-length(xVec)])
c3

#d
d3 = c()
for(i in 1:(length(xVec) - 2)) {
  d3[i] = xVec[i] + 2*xVec[i + 1] - xVec[i + 2]
}
d3

#---exercicio 04---
xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
a4 = which(yVec > 600)
a4

#b
b4 = yVec[a4]
b4

#c
c4 = xVec[which(xVec %in% b4)]
c4

#d
d4 = sqrt(abs(xVec - mean(xVec)))
d4

#e
e4 = sum(abs(yVec - max(yVec)) <= 200)
e4

#f
f4 = sum(xVec %% 2 == 0)
f4

#g
g4 = yVec[seq(from=1, to=length(yVec), by=3 )]
g4

#---exercicio 05---
num.impar = function(v) {
  impar = 0
  for(i in v) {
    impar = impar + (i %% 2)
  }
  impar
}
ex5.1 <- num.impar(seq(1, 11, 2))
ex5.1

num.impar2 = function(v) {
  sum(v %% 2)
}
ex5.2 <- num.impar(seq(1, 11, 2))
ex5.2

#---exercicio 06---
fibonacci = function(n) {
  fib = c(1,1)
  tamanho = n
  while(tamanho > 2) {
    fim = length(fib)
    fib = c(fib, fib[fim] + fib[fim - 1])
    tamanho = tamanho - 1
  }
  return(fib[1:n])
}
ex6 <- fibonacci(6)
ex6

#---exercicio 07---
# 1 = cara, 0 = coroa
tamanho.seq = function(p) {
  nro.caras = 0;
  repeat {
    jogada = sample(c(0, 1), size=1, replace=TRUE, prob = c(1-p, p))
    if(!jogada) break
    nro.caras = nro.caras + 1
  }
  nro.caras
}

maior.seq = 0
for(i in 1:100) {
  lancamentos = tamanho.seq(0.5)
  if(lancamentos > maior.seq)
    maior.seq = lancamentos
}
ex7 <- maior.seq
ex7

#---exercicio 08---
reproduz.coelhos = function(n, k) {
  fib = c(1,1)
  tamanho = n
  while(tamanho > 2) {
    fim = length(fib)
    fib = c(fib, fib[fim] + fib[fim - 1]*k)
    tamanho = tamanho - 1
  }
  fib[n]
}
ex8 <- reproduz.coelhos(4, 70)
ex8

#---exercicio 09---
library(stringr)
dna = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGGATT"

#a
?str_detect
?str_replace

#b
sequencia = function(x) {
  dna.a=0; dna.c=0; dna.g=0; dna.t=0
  repeat {
    if(x == "") break
    if(str_detect(x,"A")) {
      x <- str_replace(x,"A","")
      dna.a <- dna.a+1
      }
    if(str_detect(x,"C")) {
      x <- str_replace(x,"C","")
      dna.c <- dna.c+1
    }
    if(str_detect(x,"G")) {
      x <- str_replace(x,"G","")
      dna.g <- dna.g+1
    }
    if(str_detect(x,"T")) {
      x <- str_replace(x,"T","")
      dna.t <- dna.t+1
    }
  }
  saida <- c(dna.a,dna.c,dna.g,dna.t)
  saida
}
b9 <- sequencia(dna)
b9

#c
transforma = function(x) {
  repeat {
    if(str_detect(x,"T")) {
      x <- str_replace(x,"T","U")
    } else break
  }
  x
}
c9 <- transforma(dna)
c9

#---exercicio 10---
library(dslabs)
data("murders")
str(murders)

#a
media.population <- mean(murders$population)
mais.populoso <- murders[murders$population == max(murders$population), ]$state
menos.populoso <- murders[murders$population == min(murders$population), ]$state
media.population;mais.populoso;menos.populoso

#b
rate <- (murders$total/murders$population)*10000
murders$rate <- rate

#c
murders[order(murders$rate), ]$state

#d
inferior <- murders[murders$rate < 0.06, ]$state
superior <- murders[murders$rate > 0.05, ]$state

#e
est.maior.taxa <- murders[order(murders$rate)[length(murders$rate)], ]$state
est.menor.taxa <- murders[order(murders$rate)[1], ]$state

#f
south <- murders[murders$region == "South", ]
media.south <- mean(south$rate)
dp.south <- sd(south$rate)

northCentral <- murders[murders$region == "North Central", ]
media.northCentral <- mean(northCentral$rate)
dp.northCentral <- sd(northCentral$rate)

west <- murders[murders$region == "West", ]
media.west <- mean(west$rate)
dp.west <- sd(west$rate)

northeast <- murders[murders$region == "Northeast", ]
media.northeast <- mean(northeast$rate)
dp.northeast <- sd(northeast$rate)

regioes <- c("South", "North Central", "West", "Northeast")
taxas.max <- c(max(south$rate), max(northCentral$rate), max(west$rate), max(northeast$rate))
taxas.min <- c(min(south$rate), min(northCentral$rate), min(west$rate), min(northeast$rate))
reg.maior.tax <- regioes[taxas.max == max(taxas.max)]
reg.menor.tax <- regioes[taxas.min == min(taxas.min)]
reg.maior.tax; reg.menor.tax

#g
boxplot(south$rate, main = "South", ylim = c(min(rate), max(rate)))
boxplot(northCentral$rate, main = "North Central", ylim = c(min(rate), max(rate)))
boxplot(west$rate, main = "West", ylim = c(min(rate), max(rate)))
boxplot(northeast$rate, main = "Northeast", ylim = c(min(rate), max(rate)))
par(mfrow = c(1,4))
# A região West é a região com a taxa de mortalidade mais dispersa, enquanto a região South tem a maior taxa de mortalidade e é a única que apresenta valores discrepantes. As regiões North Central e Northeast possuem taxas similares porém a North Central possui um limite superior maior.
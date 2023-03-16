# lista 03 - estc

#---exercicio 01---
lanca1 = sample(1:6, size = 100000, replace = TRUE)
lanca2 = sample(1:6, size = 100000, replace = TRUE)
soma = lanca1 + lanca2
mean(soma == 7 | soma == 11)

#---exercicio 02---
urna1 <- c(rep("preta",8), rep("branca",3), rep("vermelha",4))
urna2 <- c(rep("preta",3), rep("branca",5), rep("vermelha",7))
urna3 <- c(rep("preta",4), rep("branca",3), rep("vermelha",2))
urna4 <- c(rep("preta",2), rep("branca",1), rep("vermelha",8))
bolas <- c()
for(i in 1:10000) {
  dado1 <- sample(1:6, size<-1)
  dado2 <- sample(1:6, size<-1)
  soma <- dado1 + dado2
  if(soma < 4) {
    bolas[i] <- sample(urna1, size=1)
  } else if (soma >= 4 && soma < 7) {
    bolas[i] <- sample(urna2, size=1)
  } else if(soma == 7) {
    bolas[i] <- sample(urna3, size=1)
  } else {
    bolas[i] <- sample(urna4, size=1)
  }
}
mean(bolas == "vermelha")

#---exercicio 03---
resultado = c()
for(i in 1:10000) {
  juju = 18
  jorel = 7
  repeat {
    moeda = sample(0:1, size = 1)
    if(moeda) {
      juju = juju+1
      jorel = jorel-1
    } else {
      jorel = jorel+1
      juju = juju-1
    }
    if(juju == 0 || jorel == 0) break
  }
  resultado[i] = (juju == 0)
}
mean(resultado)

#---exercicio 04---
vitoria = c()
for(i in 1:1000000) {
  dado1 = sample(1:6, size=1)
  dado2 = sample(1:6, size=1)
  soma = dado1 + dado2
  if(soma == 7 || soma == 11) {
    vitoria[i] = TRUE
  } else if(soma == 2 || soma == 3 || soma == 12) {
    vitoria[i] = FALSE
  } else {
    soma.inicial = soma
    repeat {
      dado1 = sample(1:6, size = 1)
      dado2 = sample(1:6, size = 1)
      soma = dado1 + dado2
      if(soma == 7) {
        vitoria[i] = FALSE
        break
      } else if(soma == soma.inicial) {
        vitoria[i] = TRUE
        break
      }
    }
  } 
}
mean(vitoria)

#---exercicio 05---
dwight = c(0, 1, 0)
jim = c(0, 0, 1)

vitoria = c()
for(i in 1:100000) {
  sequencia = sample(0:1, size=3, replace=TRUE)
  repeat {
    if(all(sequencia == dwight)) {
      vitoria[i] = FALSE
      break
    } else if(all(sequencia == jim)) {
      vitoria[i] = TRUE
      break
    }
    sequencia = c(sequencia[2:3], sample(0:1, size=1)) 
  }
}
mean(vitoria)

#---exercicio 06---
passos.luke = function(n) {
  posicoes = c()
  for(cases in 1:100000) {
    pos = 0;
    for(i in 1:n) {
      pos = pos + sample(c(-1, 1), size=1)
    }
    posicoes[cases] = pos
  }
  return(mean(posicoes == 0))
}
passos.luke(4)
passos.luke(6)
passos.luke(10)
passos.luke(20)

#---exercicio 07---
#1a integral:
int1 = function(x) {
  (1/sqrt(2*pi))*exp(-x^2/2)
}
mean(int1(runif(1000000, min=-1, max=2)))*3

#2a integral:
int2 = function(x) {
  cos(x)^2
}
mean(int2(runif(1000000, min=0, max=pi)))*pi

# prova 2 - estc

#---exercicio 01---

#a
sorteio <- function(n){
  x <- c()
  u <- runif(n)
  for(j in 1:n){
    if(u[j] <= 3/21){
      x[j] <- 'vermelha'
    }else if(u[j] <= 6/21){
      x[j] <- 'amarela'
    }else if(u[j] <= 10/21){
      x[j] <- 'verde'
    }else if(u[j] <= 15/21){
      x[j] <- 'azul'
    }else{
      x[j] <- 'preta'
    }
  }
  return(x)
}

#b
sorteio_b <- function(){
  tem_vermelha <- FALSE
  tem_amarela <- FALSE
  lista_sorteios <- c()
  repeat{
    x <- sorteio(1)
    lista_sorteios <- c(lista_sorteios,x)
    if(x == 'vermelha'){
      tem_vermelha <- TRUE
    }else if(x == 'amarela'){
      tem_amarela <- TRUE
    }
    if(tem_vermelha && tem_amarela){
      break
    }
  }
  return(length(lista_sorteios))
}
# monte carlo:
mc <- c()
for(j in 1:100000){
  mc[j] <- sorteio_b()
}
mean(mc)


#---exercicio 02---

pinguim <- read.csv(file = "pinguim.csv", header = TRUE, sep = ",")
str(pinguim)

#a
machos <- pinguim[pinguim$sex == "MALE",]
femeas <- pinguim[pinguim$sex == "FEMALE",]

#b
machos_normalizado <- scale(machos[,3:6])
machos_dist <- dist(machos_normalizado, method = "euclidean")
machos_aglomerado <- hclust(machos_dist, method = "ward.D2")
plot(machos_aglomerado,hang = -1)

#c
# O dendograma seria cortado na altura '5', porque dividiria o grafico nos principais aglomerados de tamanho dos pinguins. Foram resultados 5 aglomerados. Foi perceptível que as espécies tendem a estar no mesmo aglomerado.

#d
library(rpart)
library(rpart.plot)
femea_treino <- read.csv(file = "treino.csv", header = TRUE, sep = ",")
femea_teste <- read.csv(file = "teste.csv", header = TRUE, sep = ",")

arvore_decisao <- rpart(species~., data = femea_treino,  parms = list(split = 'gini'))
arvore_plot <- rpart.plot(arvore_decisao)

#e
funcao <- function(culmen_length_mm,culmen_depth_mm,flipper_length_mm,body_mass_g){
  if(!culmen_depth_mm >= 16){
    especie <- "Gentoo"
  }else if(culmen_length_mm < 42){
    especie <- "Adelie"
  }else{
    especie <- "Chinstrap"
  }
  return(especie)
}


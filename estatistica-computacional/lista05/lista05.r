# lista 05 - estc

#---exercicio 01---

#a
papagaios <- read.csv("papagaio.txt", header = TRUE, sep = ",")
head(papagaios)
tail(papagaios)
str(papagaios)
summary(papagaios)

#b
corniculata <- papagaios[papagaios$especie == "corniculata",]
cirrhata <- papagaios[papagaios$especie == "cirrhata",]
arctica <- papagaios[papagaios$especie == "arctica",]

mean(corniculata$peso)
mean(cirrhata$peso)
mean(arctica$peso)
sd(corniculata$peso)
sd(cirrhata$peso)
sd(arctica$peso)
# peso
# media: cirrhata > corniculata > arctica
# desvio padrao: cirrhata > corniculata > arctica

mean(corniculata$tamanho)
mean(cirrhata$tamanho)
mean(arctica$tamanho)
sd(corniculata$tamanho)
sd(cirrhata$tamanho)
sd(arctica$tamanho)
# tamanho
# media: corniculata > cirrhata > arctica
# desvio padrao: corniculata > cirrhata > arctica

mean(corniculata$envergadura)
mean(cirrhata$envergadura)
mean(arctica$envergadura)
sd(corniculata$envergadura)
sd(cirrhata$envergadura)
sd(arctica$envergadura)
# envergadura
# media: cirrhata > corniculata > arctica
# desvio padrao: cirrhata > corniculata > arctica

par(mfrow = c(1, 3))
boxplot(corniculata$peso, main = "Corniculta", ylim = c(min(papagaios$peso),max(papagaios$peso)))
boxplot(cirrhata$peso, main = "Cirrhata", ylim = c(min(papagaios$peso),max(papagaios$peso)))
boxplot(arctica$peso, main = "Arctica", ylim = c(min(papagaios$peso),max(papagaios$peso)))
# o maior destaque é a especie Arctica ter, em media, um peso bem inferior ao das outras especies

#c
papagaios$especie = as.factor(papagaios$especie)

#d
n <- round(nrow(papagaios)*0.8)
treino <- papagaios[1:n,]
teste <- papagaios[(n+1):nrow(papagaios),]

#e
sim <- treino[treino$peso>40,]$especie
nao <- treino[treino$peso<=40,]$especie


gs <- ((sum(sim == "corniculata"))/length(sim))*(1 - (sum(sim == "corniculata"))/length(sim)) + ((sum(sim == "cirrhata"))/length(sim))*(1 - (sum(sim == "cirrhata"))/length(sim)) + ((sum(sim == "arctica"))/length(sim))*(1 - (sum(sim == "arctica"))/length(sim))

gn <- ((sum(nao == "corniculata"))/length(nao))*(1 - (sum(nao == "corniculata"))/length(nao)) + ((sum(nao == "cirrhata"))/length(nao))*(1 - (sum(nao == "cirrhata"))/length(nao)) + ((sum(nao == "arctica"))/length(nao))*(1 - (sum(nao == "arctica"))/length(nao))

g <- ((length(sim))/length(sim)+length(nao))*gs + ((length(nao))/length(nao)+length(sim))*gn
g

#f
library(rpart)
library(rpart.plot)
treino_arvore <- rpart(especie~., data = treino, parms = list(split = "gini"))
rpart.plot(treino_arvore, extra = 101)

#g
previsao <- predict(treino_arvore, newdata = teste, type = "class")
mean(previsao == teste$especie)
table(previsao, teste$especie)
# a taxa de acerto foi alta (~0.77) e é possivel perceber que a especie corniculata é mais dificil de se prever


#---exercicio 02---

#a
papagaios <- read.csv("papagaio.txt", header = TRUE, sep = ",")
corniculata <- papagaios[papagaios$especie == "corniculata",]
cirrhata <- papagaios[papagaios$especie == "cirrhata",]
arctica <- papagaios[papagaios$especie == "arctica",]

#b
coeficiente <- function(x,y){
  n <- length(x)
  numerador <- sum(x*y) - n * mean(x) * mean(y)
  denominador <- sqrt(sum(x*x) - (n * mean(x)*mean(x))) * sqrt(sum(y*y) - n * mean(y)*mean(y))
  return(numerador/denominador)
}

coeficiente(corniculata$tamanho, corniculata$peso)
coeficiente(cirrhata$tamanho, cirrhata$peso)
coeficiente(arctica$tamanho, arctica$peso)
# corniculata é a mais correlacionada linearmente (coeficiente = 0.9025978)

#c
lm(peso ~ tamanho, corniculata)

#d
calculo_peso <- function(x){
  return(-300.59 + x * 24.25)
}
calculo_peso(40) - calculo_peso(40.5) # = -12.125
# uma variacao de 0.5cm no tamanho provocaria variacao de 12.125 no peso da ave. isso se deve ao valor do coeficiente angular dessa relacao

#e
calculo_novo_peso <- function(x){
  if(x < min(corniculata$tamanho) || x > max(corniculata$tamanho)){
    return("erro")
  }
  return(-300.59 + x * 24.25)
}
calculo_novo_peso(18) #erro
calculo_novo_peso(41.01) #693.9025


#---exercicio 03---
azeite = read.csv("olive.txt", header = TRUE, sep = ",")

#a
azeite_normalizado <- scale(azeite[,2:9])
azeite_dist <- dist(azeite_normalizado, method = "euclidean")
azeite_aglomerado <- hclust(azeite_dist, method = "ward.D2")
plot(azeite_aglomerado, labels = azeite$region, hang = -1)

#b
aglomerados <- cutree(azeite_aglomerado, k = 5)

aglomerado1 <- azeite[aglomerados == 1,]
aglomerado2 <- azeite[aglomerados == 2,]
aglomerado3 <- azeite[aglomerados == 3,]
aglomerado4 <- azeite[aglomerados == 4,]
aglomerado5 <- azeite[aglomerados == 5,]

mean(aglomerado1$region == "Southern Italy") #1
mean(aglomerado1$region == "Northern Italy")
mean(aglomerado1$region == "Sardinia")

mean(aglomerado2$region == "Southern Italy") #1
mean(aglomerado2$region == "Northern Italy")
mean(aglomerado2$region == "Sardinia")

mean(aglomerado3$region == "Southern Italy")
mean(aglomerado3$region == "Northern Italy") #1
mean(aglomerado3$region == "Sardinia")

mean(aglomerado4$region == "Southern Italy")
mean(aglomerado4$region == "Northern Italy") #1
mean(aglomerado4$region == "Sardinia")

mean(aglomerado5$region == "Southern Italy")
mean(aglomerado5$region == "Northern Italy")
mean(aglomerado5$region == "Sardinia") #1

#c
azeite_kmeans <- kmeans(x = azeite_normalizado, centers = 5)

azeite_kmeans$centers

plot(azeite_normalizado, type = "n")
points(azeite_normalizado[azeite_kmeans$cluster == 1,], pch = 16, col = "red")
points(azeite_normalizado[azeite_kmeans$cluster == 2,], pch = 16, col = "orange")
points(azeite_normalizado[azeite_kmeans$cluster == 3,], pch = 16, col = "blue")
points(azeite_normalizado[azeite_kmeans$cluster == 4,], pch = 16, col = "green")
points(azeite_normalizado[azeite_kmeans$cluster == 5,], pch = 16, col = "black")

# as regioes tendem a ficar agrupadas 
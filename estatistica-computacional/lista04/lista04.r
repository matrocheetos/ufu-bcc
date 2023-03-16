# lista 04 - estc

#---exercicio 01---

gerador <- function(n){
  x <- c()
  u <- runif(n)
  for(j in 1:n){
    if(u[j] <= 1/3){
      x[j] <- 1
    }else{
      x[j] <- 2
    }
  }
  return(x)
}
proporcao_dois <- function(n){
  resultados <- gerador(n)
  igual_a_dois <- resultados == 2
  return(mean(igual_a_dois))
}

proporcao_dois(100)
proporcao_dois(1000)
proporcao_dois(10000)


#---exercicio 02---

vetor_prob <- function(n){
  y <- c()
  for(j in 1:n){
    y[j] <- j/n
  }
  return(y)
}
# todos valores de X
valores_x <- function(y){
  x <- c()
  x <- y*length(y)
  return(x)
}
# um valor de X
valor_x <- function(y){
  x <- y[1]*length(y)
  return(x)
}

# para vetor tamanho 100:
valores_x(vetor_prob(100))
valor_x(vetor_prob(100))


#---exercicio 03---

# x + x^2 - 2y = 0
# raizes da equacao
# delta = 1^2 - 4*1(-2y) = 1+8y
# x = (-1 + sqrt(1+8y)) /2

inversa <- function(y){
  return((-1 + sqrt(1+8*y))/2)
}
gerador2 <- function(n){
  u <- runif(n)
  return(inversa(u))
}

resultados <- gerador2(10000)
mean(resultados<0.7)

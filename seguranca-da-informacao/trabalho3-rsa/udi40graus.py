import random as R
import hashlib as H

# def modpow(b,e,n):
#     if (e<10): #base
#         return (b**e) % n
#     isodd = ((e%2)==1)
#     meio =  e/2
#     temp = modpow(b,meio,n)
#     if isodd:
#         return temp*temp*b %n
#     return temp*temp %n

def modpow(b, e, n):
    result = 1
    b = b % n
    
    while e > 0:
        if e % 2 == 1:
            result = (result * b) % n
        
        b = (b * b) % n
        e = e // 2
    
    return result

# https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm
def xgcd(b, n):
    x0, x1, y0, y1 = 1, 0, 0, 1
    while n != 0:
        q, b, n = b // n, n, b % n
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return  b, x0, y0

def mulinv(b, n):
    g, x, _ = xgcd(b, n)
    if g == 1:
        return x % n
    return -1

def composto(n):
    i=2
    while (i<n):
        if (n % i) == 0:
            return True
        i+=1
    return False

def primeGen(e,l):
    p = R.randint(l,2*l)
    if p%2==0:
        p+=1
    while composto(p) or not(xgcd(e,p-1)[0]==1):
        p+=2
    return p

# Boneh/Shoup
def rsaGen(e,l):
    p = primeGen(e,l)
    q=p
    while (q==p):
        q = primeGen(e,l)
    n= p*q
    phi = (p-1)*(q-1)
    d= mulinv(e,phi)
    return (d,n)

def testRSA():
    size=1024
    for i in range(10000):
        e=R.choice([3,5,7,11,17,19])
        (d,n) =  rsaGen(e,size)
        plain = R.randint(2,size)
        cipher = modpow(plain, e,n)
        decipher = modpow(cipher,d,n)
        text = R.randint(50,size)
        signed = modpow(text,d,n)
        verify = modpow(signed,e,n)

        print("plain:", plain, "decipher:", decipher, "signed:", signed,
              "verify:", verify, "e:", e, "d:" ,d, "n:", n)
    
        assert plain==decipher , "Erro no RSA"
        assert verify==text , "Erro na assinatura RSA"
    
def smallHash(s):
    return int(H.sha256(s.encode()).hexdigest()[0:9], 16)
    
def exerExemplo(l,size):
    for a in l:
        e=R.choice([3,5,7,11,17,19])
        (d,n) =  rsaGen(e,size)
        text = smallHash(a)
        signed = modpow(text,d,n)
        verify = modpow(signed,e,n)
        print (a, (d,n),text, signed)
        assert verify==text , "Erro na assinatura RSA"

def exer(l,size):
    R.shuffle(l)
    for a in l:
        # Veja como o expoente publico e escolhido!! 
        e=R.choice([3,5,7,11,17,19])
        (d,n) =  rsaGen(e,size)
        text = smallHash(a)
        signed = modpow(text,d,n)
        verify = modpow(signed,e,n)
        print ((d,n), signed)
        assert verify==text , "Erro na assinatura RSA"
       
alunos = ['Atilio',
          'Gabriela Santos',
          'Gustavo Vinicius',
          'Henrique Macarini de',
          'Joao Pedro de Oliveira Martins',
          'Kaio Augusto de',
          'Loredana Romano',
          'Lucas Guerreiro',
          'Mateus Carmo de',
          'Mateus Rocha',
          'Otavio Almeida',
          'Paulo Kiyoshi',
          'Paulo Vitor Costa',
          'Pedro Henrique da Silva',
          'Pedro Henrique Resende',
          'Robson Roberto',
          'Rodrigo de Castro',
          'Tiago da Silva e Souza',
          'Vinicius Pimenta',
          'Vitor Barbosa Lemes',
          'Yan Stivaletti e',
          'Yasmin Marques']

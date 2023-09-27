import socket                          # Import socket module
from time import sleep

s = socket.socket()                    # Create a socket object
host = socket.gethostname()            # Get local machine name
port = 12345                           # Reserve a port for your service.

print('Conectando-se ao servidor...')
s.connect((host, port))
print('Conectado')

while True:
    mensagem = input('Digite mensagem: ')
    s.send(mensagem.encode())
    if mensagem == 'SAIR': break
    print('Mensagem enviada')

    print('Esperando resposta...')
    resposta = s.recv(1024)
    print('Resposta recebida:', resposta.decode())

print('Desconectando.')
s.close()                              # Close the socket when done

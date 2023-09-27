import socket                          # Import socket module
from time import sleep

s = socket.socket()                    # Create a socket object
host = socket.gethostname()            # Get local machine name
port = 12345                           # Reserve a port for your service.

s.connect((host, port))

# tenta receber múltiplos pacotes
# send() do lado do servidor pode enviar mais de um pacote por vez
for i in range(3):
    data = s.recv(1024)
    print(data.decode() + '\n')
    
s.close()                              # Close the socket when done

import socket                               # Import socket module

# socket TCP
s = socket.socket()                         # Create a socket object
host = socket.gethostname()                 # Get local machine name
port = 12345                                # Reserve a port for your service.
s.bind((host, port))                        # Bind to the port

s.listen(5)                                 # Now wait for client connections.

while True:
    print('====================')
    print('Esperando conexão...')
    c, addr = s.accept()                     # Establish connection with client.
    print('Conectado a', addr)

    while True:
        print('Esperando mensagem...')
        mensagem = c.recv(1024)
        if(mensagem.decode() == 'SAIR'): break
        print('Mensagem recebida:', mensagem.decode())

        resposta = input('Digite resposta: ')
        c.send(resposta.encode())
        print('Resposta enviada.')
    
    print('Conexão encerrada.')
    c.close()                                # Close the connection

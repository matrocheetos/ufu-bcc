import socket

# socket UDP
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 12345
s.bind((host, port))

while True:
    print('====================')

    while True:
        print('Esperando mensagem...')
        mensagem, addr = s.recvfrom(1024)
        if(mensagem.decode() == 'SAIR'): break
        print('Mensagem recebida de '+str(addr)+':', mensagem.decode())

        resposta = input('Digite resposta: ')
        sent = s.sendto(resposta.encode(), addr)
        print('Resposta enviada.')
    
    print('Conexão encerrada.')
import socket                          # Import socket module
from time import sleep

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 12345
s_addr= (host,port)

while True:
    mensagem = input('Digite mensagem: ')
    s.sendto(mensagem.encode(), s_addr)
    if mensagem == 'SAIR': break
    print('Mensagem enviada')

    print('Esperando resposta...')
    resposta, addr = s.recvfrom(1024)
    print('Mensagem recebida de '+str(addr)+':', resposta.decode())

print('Desconectando.')
s.close()

import random as R
import hashlib as H
import udi40graus as ex

# testes
#ex.exerExemplo(alunos,99999999)
#ex.testRSA()

# ======================================
# pt1: identificar qual é a assinatura do meu nome

# identifica qual a assinatura do nome
def idAssinatura(nome, lista):
    text = ex.smallHash(nome)
    for aluno in lista:
        (d,n) =  (aluno[0], aluno[1])
        signed = ex.modpow(text,d,n)
        if signed == aluno[2]:
            print(nome, (d,n), text, signed)
            print("encontrou!!!!!!! assinatura:", signed)


# identifica assinatura e descobre expoente público utilizado
# (considerando possíveis expoentes = [3,5,7,11,17,19])
def idAssinaturaExp(nome, lista):
    expoentes = [3,5,7,11,17,19]
    text = ex.smallHash(nome)
    for e in expoentes:
        for aluno in lista:
            (d,n) =  (aluno[0], aluno[1])
            signed = ex.modpow(text,d,n)
            verify = ex.modpow(signed,e,n)
            if signed == aluno[2] and verify == text:
                print(nome, (d,n), text, signed)
                print("encontrou!!!!!!! assinatura:", signed)
                print('expoente público utilizado:', e)


def idTodos(lista):
    for a in lista:
        idAssinaturaExp(a, embaralhada)


embaralhada =  [(18693571199959531, 28040357135002117, 16899482698042476),
                (9083060786453117, 14037457817356793, 13595477329870381),
                (16229616337444075, 18138983234768171, 14327948937557192),
                (2241729623053553, 19054702079298077, 8676081267968085),
                (11626788178315889, 12353462662947331, 8619302786067813),
                (16987045494623667, 25480568566466821, 6867851772928880),
                (30854006232024155, 37710452449876967, 11639101328643508),
                (16102618924300985, 26837698535331473, 4287853157950049),
                (11758299307703021, 14697874381109807, 3954128846733701),
                (22783704777494599, 26580989234740951, 11789359154239635),
                (937268631430111, 17808104272085333, 13222517408667871),
                (14577101728149115, 30773881777243037, 63052402121887),
                (11623839008865987, 17435758777407793, 885034229993339),
                (13493859831624669, 20854147302994081, 8530200238933194),
                (12703012230164651, 19054518626579929, 12846469548816356),
                (9639766056347165, 16066277017439503, 10887229941830764),
                (10144681359381095, 12399055218744757, 5005633278089796),
                (7478111931112819, 20297732669395507, 12261979175267589),
                (10030049019878603, 15761505858709867, 14655693335533908),
                (9770702087264561, 13841828192684033, 7637103648934699),
                (15024551782836811, 22536827978875807, 3697858268886538),
                (5634160913698423, 19719563478845423, 6932186562179903)]


idAssinatura('Mateus Rocha', embaralhada)
#   (11623839008865987, 17435758777407793, 885034229993339)
#   encontrou!!!!!!! assinatura: 885034229993339

idAssinaturaExp('Mateus Rocha', embaralhada)
#   expoente público utilizado: 3

idTodos(ex.alunos)

# ======================================
# pt2: encontrar colisão de smallHash relacionada ao meu nome

# colisões com string aleatória

TAMANHO_HASH = 9

def smallHash2(s):
    return int(H.sha256(s.encode()).hexdigest()[0:TAMANHO_HASH], 16)

def encontraColisoesRandom(space_size, target_name):
    target_hash = smallHash2(target_name)
    print('Buscando colisão...')
    while True:
        name = ''.join(R.choice('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ') for _ in range(space_size))  # Gera nomes aleatórios
        h = smallHash2(name)
        if h == target_hash:
            return name, h
        #print("\033c", end="")
        #print("nome:", name)
        #print("hash:", h)
        #print("hash desejado:", target_hash)


space_size = TAMANHO_HASH*4
target_name = "Mateus Rocha"
encontraColisoesRandom(space_size, target_name)
#   Colisão encontrada:
#   nome: [Mateus Rocha]: 'bHrQqyfvwOByHNPNHjpwSits'
#   hash: [10155844]: '10155844'
#   tamanho hash: 6

# ===================

# colisões com nome randomizado

def randomizaNome(nome):
    nome = nome.lower()
    randNome = ''
    for i in range(len(nome)):
        if nome[i] == ' ':
            randNome += ' '
            continue
        
        if R.random() < 0.5:
            randNome += nome[i]
        else:
            randNome += nome[i].upper()
        
    return randNome


def calculaMaxVariacoes(nome):
    nome = nome.replace(" ", "")
    maxV = 2 ** len(nome)
    return maxV


def printColisoes(chash, nome1, nome2):
    print("Colisão encontrada:")
    print(f"nomes: [{nome1}] - [{nome2}]")
    print(f"hash: [{chash}]")
    print(f"tamanho hash: [{TAMANHO_HASH}]")


def encontraColisoes(nome):
    hashes = {}
    colisoes = []
    nome_hash = ex.smallHash(nome)
    maxV = calculaMaxVariacoes(nome)
    variacoes = 0
    print('Buscando colisão...')
    while True:
        if variacoes == maxV:
            print(f"maximo de variacoes atingido: {len(hashes)}/{variacoes}" )
            print(colisoes)
            return
        colisao_nome = randomizaNome(nome)
        if colisao_nome in hashes.values(): continue  # pula iteração se nome ja foi gerado
        colisao_hash = ex.smallHash(colisao_nome)
        if colisao_hash in hashes:
            if hashes[colisao_hash] != colisao_nome and not (hashes[colisao_hash], colisao_nome) in colisoes:
                # encontrou colisão
                variacoes += 1
                colisoes.append((hashes[colisao_hash], colisao_nome))
                printColisoes(colisao_hash, colisao_nome, hashes[colisao_hash])
                continue  # nao atualiza dicionario
        hashes[colisao_hash] = colisao_nome
        variacoes += 1


encontraColisoes("Mateus Rocha Resende")
#   Buscando colisão...
#   Colisão encontrada:
#   nomes: [mateuS roCha ResEndE] - [matEus RochA rEsEnDE]
#   hash: [56739065348]
#   tamanho hash: [9]
#   maximo de variacoes atingido: 262137/262144
#   [('matEus RochA rEsEnDE', 'mateuS roCha ResEndE'), ('mateuS roCha ResEndE', 'matEus RochA rEsEnDE')]

import udi40graus as ex

def exerMateus(lista):
    text = ex.smallHash('Mateus Rocha')
    for aluno in lista:
        (d,n) =  (aluno[0], aluno[1])
        signed = ex.modpow(text,d,n)
        if signed == aluno[2]:
            print('Mateus Rocha', (d,n), text, signed)
            print("encontrou!!!!!!! assinatura:", signed)

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


# ex.exerExemplo(alunos,99999999)
# ex.testRSA()

exerMateus(embaralhada)
# (11623839008865987, 17435758777407793, 885034229993339)
# Tabela de Símbolos
# Campos: tipo do token, lexema, valor e tipo do dado
# Os 2 últimos campos só serão preenchidos quando aplicável

tabela_de_simbolos = dict()

# lexema: (tipo_token, valor, tipo_dado)

tabela_de_simbolos['function'] = ("function", "-", "-")

tabela_de_simbolos['int'] = ("int", "-", "-")
tabela_de_simbolos['char'] = ("char", "-", "-")
tabela_de_simbolos['float'] = ("float", "-", "-")

tabela_de_simbolos['se'] = ("se", "-", "-")
tabela_de_simbolos['entao'] = ("entao", "-", "-")
tabela_de_simbolos['senao'] = ("senao", "-", "-")

tabela_de_simbolos['enquanto'] = ("enquanto", "-", "-")
tabela_de_simbolos['faca'] = ("faca", "-", "-")
tabela_de_simbolos['repita'] = ("repita", "-", "-")
tabela_de_simbolos['ate'] = ("ate", "-", "-")

# ===========================================

lista_terminais = ["oprel", "somasub", "multdiv", "expo",
                   "tipo", "id", "se", "entao", "senao", 
                   "enquanto", "faca", "repita", "ate",
                   "function", "numero", "caractere",
                   "=", ",", ";", ":", "(", ")", "}","{"]

# ===========================================

# pilha "inversa": append para inserir, pop para remover
# inicia sempre em 'call'
pilha = ["call"]

# ===========================================

# nao_terminal: (terminal, [a,b,c,s])

tabela_preditiva = []
# a
tabela_preditiva.append(['call', 'function', ["function", "id", "(", ")", "{", "bloco", "}"]])
# b
tabela_preditiva.append(['bloco', 'tipo', ['decs', 'cmds']])
tabela_preditiva.append(['bloco', 'id', ['decs', 'cmds']])
tabela_preditiva.append(['bloco', 'se', ['decs', 'cmds']])
tabela_preditiva.append(['bloco', 'enquanto', ['decs', 'cmds']])
tabela_preditiva.append(['bloco', 'repita', ['decs', 'cmds']])
tabela_preditiva.append(['bloco', '}', ['decs', 'cmds']])
# c
tabela_preditiva.append(['decs', 'tipo', ["decs_"]])
tabela_preditiva.append(['decs', 'id', ["decs_"]])
tabela_preditiva.append(['decs', 'se', ["decs_"]])
tabela_preditiva.append(['decs', 'enquanto', ["decs_"]])
tabela_preditiva.append(['decs', 'repita', ["decs_"]])
tabela_preditiva.append(['decs', '}', ["decs_"]])
# d
tabela_preditiva.append(['decs_', 'tipo', ["dec", "decs_"]])
tabela_preditiva.append(['decs_', 'id', ["dec", "decs_"]])
tabela_preditiva.append(['decs_', 'se', ["dec", "decs_"]])
tabela_preditiva.append(['decs_', 'enquanto', ["dec", "decs_"]])
tabela_preditiva.append(['decs_', 'repita', ["dec", "decs_"]])
# d producoes vazias
tabela_preditiva.append(['decs_', 'id', []])
tabela_preditiva.append(['decs_', 'se', []])
tabela_preditiva.append(['decs_', 'enquanto', []])
tabela_preditiva.append(['decs_', 'repita', []])
# e
tabela_preditiva.append(['dec', 'tipo', ["tipo", ":", "lista_ids", ";"]])
# f
tabela_preditiva.append(["lista_ids", "id", ["id", "lista_ids_"]])
# g
tabela_preditiva.append(["lista_ids_", ",", [",", "id", "lista_ids_"]])
tabela_preditiva.append(["lista_ids_", ";", []])
# h
tabela_preditiva.append(["cmds", "id", ["cmds_"]])
tabela_preditiva.append(["cmds", "se", ["cmds_"]])
tabela_preditiva.append(["cmds", "enquanto", ["cmds_"]])
tabela_preditiva.append(["cmds", "repita", ["cmds_"]])
tabela_preditiva.append(["cmds", "}", ["cmds_"]])
# i
tabela_preditiva.append(["cmds_", "id", ["cmd", "cmds_"]])
tabela_preditiva.append(["cmds_", "se", ["cmd", "cmds_"]])
tabela_preditiva.append(["cmds_", "enquanto", ["cmd", "cmds_"]])
tabela_preditiva.append(["cmds_", "repita", ["cmd", "cmds_"]])
tabela_preditiva.append(["cmds_", "}", []])
# j
tabela_preditiva.append(["cmd", "id", ["id", "=", "expr", ";"]])
tabela_preditiva.append(["cmd", "se", ["se", "(", "cond", ")", "entao", "cmd_bloco"]])
tabela_preditiva.append(["cmd", "enquanto", ["enquanto", "(", "cond", ")", "faca", "cmd_bloco"]])
tabela_preditiva.append(["cmd", "repita", ["repita", "cmd_bloco", "ate", "(", "cond", ")"]])
# k
tabela_preditiva.append(["expr", "somasub", ["expr2", "expr_"]])
tabela_preditiva.append(["expr", "id",  ["expr2", "expr_"]])
tabela_preditiva.append(["expr", "(",  ["expr2", "expr_"]])
tabela_preditiva.append(["expr", "caractere",  ["expr2", "expr_"]])
tabela_preditiva.append(["expr", "numero",  ["expr2", "expr_"]])
# l
tabela_preditiva.append(["expr_", "somasub", ["somasub", "expr2", "expr_"]])
tabela_preditiva.append(["expr_", "oprel", []])
tabela_preditiva.append(["expr_", ")", []])
tabela_preditiva.append(["expr_", ";", []])
# m
tabela_preditiva.append(["expr2", "somasub", ["expr3", "expr2_"]])
tabela_preditiva.append(["expr2", "id",  ["expr3", "expr2_"]])
tabela_preditiva.append(["expr2", "(",  ["expr3", "expr2_"]])
tabela_preditiva.append(["expr2", "caractere",  ["expr3", "expr2_"]])
tabela_preditiva.append(["expr2", "numero",  ["expr3", "expr2_"]])
# n
tabela_preditiva.append(["expr2_", "multdiv", ["multdiv", "expr3", "expr2_"]])
tabela_preditiva.append(["expr2_", "somasub", []])
tabela_preditiva.append(["expr2_", "oprel", []])
tabela_preditiva.append(["expr2_", ")", []])
tabela_preditiva.append(["expr2_", ";", []])
# o
tabela_preditiva.append(["expr3", "somasub", ["unario", "expr3_"]])
tabela_preditiva.append(["expr3", "id",  ["unario", "expr3_"]])
tabela_preditiva.append(["expr3", "(",  ["unario", "expr3_"]])
tabela_preditiva.append(["expr3", "caractere",  ["unario", "expr3_"]])
tabela_preditiva.append(["expr3", "numero",  ["unario", "expr3_"]])
# p
tabela_preditiva.append(["expr3_", "expo", ["expo", "unario", "expr3_"]])
tabela_preditiva.append(["expr3_", "multdiv", []])
tabela_preditiva.append(["expr3_", "somasub", []])
tabela_preditiva.append(["expr3_", "oprel", []])
tabela_preditiva.append(["expr3_", ")", []])
tabela_preditiva.append(["expr3_", ";", []])
# q
tabela_preditiva.append(["term", "id", ["id"]])
tabela_preditiva.append(["term", "(", ["(", "expr", ")"]])
tabela_preditiva.append(["term", "caractere", ["caractere"]])
tabela_preditiva.append(["term", "numero", ["numero"]])
# r
tabela_preditiva.append(["cond", "somasub", ["expr", "oprel", "expr"]])
tabela_preditiva.append(["cond", "id", ["expr", "oprel", "expr"]])
tabela_preditiva.append(["cond", "(", ["expr", "oprel", "expr"]])
tabela_preditiva.append(["cond", "caractere", ["expr", "oprel", "expr"]])
tabela_preditiva.append(["cond", "numero", ["expr", "oprel", "expr"]])
# s
tabela_preditiva.append(["cmd_bloco", "id", ["cmd"]])
tabela_preditiva.append(["cmd_bloco", "se", ["cmd"]])
tabela_preditiva.append(["cmd_bloco", "enquanto", ["cmd"]])
tabela_preditiva.append(["cmd_bloco", "repita", ["cmd"]])
tabela_preditiva.append(["cmd_bloco", "{", ["{", "bloco", "}"]])
# t
tabela_preditiva.append(["cmd_bloco_", "senao", ["senao", "cmd_bloco"]])
# t producoes vazias
tabela_preditiva.append(["cmd_bloco_", "id", []])
tabela_preditiva.append(["cmd_bloco_", "se", []])
tabela_preditiva.append(["cmd_bloco_", "senao", []])
tabela_preditiva.append(["cmd_bloco_", "enquanto", []])
tabela_preditiva.append(["cmd_bloco_", "repita", []])
tabela_preditiva.append(["cmd_bloco_", "ate", []])
tabela_preditiva.append(["cmd_bloco_", "{", []])
# u
tabela_preditiva.append(["unario", "somasub", ["somasub", "term"]])
tabela_preditiva.append(["unario", "id", ["term"]])
tabela_preditiva.append(["unario", "(", ["term"]])
tabela_preditiva.append(["unario", "caractere", ["term"]])
tabela_preditiva.append(["unario", "numero", ["term"]])


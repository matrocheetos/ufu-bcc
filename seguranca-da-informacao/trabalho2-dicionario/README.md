# Ataque de Dicionário

## Regras e informações

- Senhas com ao menos 10 caracteres
- Ao menos uma letra maiúscula
- Ao menos um caracter especial ou numérico
- Sabe-se que os funcionários da empresa são fãs de Star Wars
- A primeira senha é "testeteste" e a função de hashing é o SHA256

## Hashcat

Modo de uso do Hashcat para recuperar senhas:

```bash
hashcat -m 1400 -a 0 -o resultado.txt hash.txt dict_sw.txt -r OneRuleToRuleThemAll.rule
```

## Arquivos

- `dict_sw.txt`: dicionário com palavras relacionadas a Star Wars
- `hash.txt`: hash das senhas a serem recuperadas
- `resultado.txt`: senhas decifradas

## Referências
- Wordlist: [Star Wars, EFF](https://www.eff.org/files/2018/08/29/starwars_8k_2018.txt)
- Wordlist: [Star Wars, ‘sbridgens’](https://github.com/sbridgens/starwars_wordlist)
- Regras: [One Rule to Rule Them All](https://notsosecure.com/one-rule-to-rule-them-all)
- Regras: [Hob0Rules](https://github.com/praetorian-inc/Hob0Rules)
- [Hashcat](https://hashcat.net/wiki/)
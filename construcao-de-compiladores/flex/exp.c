#include "lexer.h"
#include "exp.h"

/* Carrega uma string como entrada */
YY_BUFFER_STATE buffer;

void inicializa(char *str) {
	//buffer = yy_scan_string(str);
	
	yyin = fopen(str, "r");
	if(yyin == NULL){
		printf("Arquivo nao encontrado\n");
		exit(-1);
	} else {
		printf("Arquivo aberto\n");
	}
}

Token *proximo_token() {
	return yylex();
}

void imprime_token( Token *tok) {
	if (tok->tipo == -1){
		printf("<%s,%s>\n", "EOF", "-");
	}else{
		printf("<%d,%d>\n", tok->tipo, tok->valor);
	}
}

int main(int argc, char **argv) {
	Token *tok;
	
// Definicao da entrada
	char nome_arquivo[200];
	printf("\nCaminho do arquivo: ");
	scanf("%s", nome_arquivo);
	setbuf(stdin, NULL);
	inicializa(nome_arquivo);

	tok = proximo_token();
	while (tok != NULL){
		imprime_token(tok);
		if(tok->tipo == -1)
	 		break;
		tok = proximo_token();
	}

	return 0;
}



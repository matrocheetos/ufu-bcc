// constantes booleanas
#define TRUE 1
#define FALSE 0

// constantes para nome de token
#define TOK_NUM 0
#define TOK_OP 1
#define TOK_PONT 2
#define TOK_ERRO 3
#define TOK_ID 4
#define TOK_REL 5
#define TOK_IF 6
#define TOK_THEN 7
#define TOK_ELSE 8
#define TOK_EOF -1

// constantes para operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// constantes para parenteses
#define PARESQ 0
#define PARDIR 1

// constantes para operadores relacionais
#define EQ 0
#define LT 1
#define GT 2
#define NE 3
#define LE 4
#define GE 5

// estrutura de um token
typedef struct {
	int tipo;
	int valor;
} Token;

// funcao para criar um token
extern Token *token();

// funcao do analisador lexico
extern Token *yylex();

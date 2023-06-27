%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"

%{ 
#include "exp.h" 
%}


NUM [0-9]+
COMENTARIO \/\*.*\*\/
ID [A-Za-z_][A-Za-z_0-9]*

%%

	/* ignorados: */
[[:space:]] { }
\/n { }
\/t { }
{COMENTARIO} { }

{NUM} { return token(TOK_NUM, atoi(yytext)); }
\+ { return token(TOK_OP, SOMA); }
- {return token(TOK_OP, SUB); }
\* { return token(TOK_OP, MULT); }
\/ { return token(TOK_OP, DIV); }
\( { return token(TOK_PONT, PARESQ); }
\) { return token(TOK_PONT, PARDIR); }

	/* if, then, else e identificadores: */
if { return token(TOK_IF, 0); }
then { return token(TOK_THEN, 0); }
else { return token(TOK_ELSE, 0); }
{ID} { return token(TOK_ID, 0); }

	/* operadores relacionais: */
== { return token(TOK_REL, EQ); }
\< { return token(TOK_REL, LT); }
\> { return token(TOK_REL, GT); }
\<\> { return token(TOK_REL, NE); }
\<= { return token(TOK_REL, LE); }
\>= { return token(TOK_REL, GE); }

	/* fim de arquivo */
<<EOF>> { return token(TOK_EOF, 0); }

. { return token(TOK_ERRO, 0); } 

%%

// variavel global para um token
Token tok;
Token * token (int tipo, int valor) {
	tok.tipo = tipo;
	tok.valor = valor;
	return &tok;
}

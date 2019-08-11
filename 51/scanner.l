%{
# include "parser.tab.h"
# include <stdlib.h>
%}

digit [0-9]
number {digit}+
commentsa "//".*
temp {digit}*
double_number_1 {temp}\.{number} 
double_number_2 {number}\.{temp}
less_than "<"
greater_than ">"
greater_than_equal ">="
less_than_equal "<="
and "&&"
or "||"
not "!"
equal "=="
not_equal "!="
operator [-+*/]
meta_char [,;{}()?:]
integer int
float float
void void
while while
if if
else else
do do
assign [=]
return return
print print
name [a-zA-Z_][a-zA-Z_0-9]*
%%
{void}					{store_token_name("VOID",yytext,yylineno);
						return VOID;}
{print}					{store_token_name("PRINT",yytext,yylineno);
						return PRINT;}
{while}					{store_token_name("WHILE",yytext,yylineno);
						return WHILE;}
{do}					{store_token_name("DO",yytext,yylineno);
						return DO;}
{return}				{yylval.string_value=new string(yytext);
						store_token_name("RETURN",yytext,yylineno);
						return RETURN;}
{if}					{store_token_name("IF",yytext,yylineno);
						return IF;}
{else}					{store_token_name("ELSE",yytext,yylineno);
						return ELSE;}
{equal}					{store_token_name("EQUAL",yytext,yylineno);
						return EQ;}
{not_equal}				{store_token_name("NOT_EQUAL",yytext,yylineno);
						return NEQ;}
{less_than_equal}		{store_token_name("LESS_THAN_EQUAL",yytext,yylineno);
						return LTEQ;}
{greater_than_equal}	{store_token_name("GREATER_THAN_EQUAL",yytext,yylineno);
						return GTEQ;}
{greater_than}			{store_token_name("GREATER_THAN",yytext,yylineno);
						return GT;}
{less_than}				{store_token_name("LESS_THAN",yytext,yylineno);
						return LT;}
{not}					{store_token_name("NOT",yytext,yylineno);
						return NOT;}
{and}					{store_token_name("AND",yytext,yylineno);
						return AND;}
{or}					{store_token_name("OR",yytext,yylineno);
						return OR;}
{integer}				{store_token_name("INTEGER",yytext,yylineno);
						return INTEGER;}
{float}					{store_token_name("FLOAT",yytext,yylineno);
						return FLOAT;}
{assign}				{store_token_name("ASSIGN_OP",yytext,yylineno);
						return ASSIGN;}
{double_number_1}		{yylval.double_value=atof(yytext);
						store_token_name("FNUM",yytext,yylineno);
						return DOUBLE_NUMBER; }
{double_number_2}		{yylval.double_value=atof(yytext);
						store_token_name("FNUM",yytext,yylineno);
						return DOUBLE_NUMBER; }
{number}				{yylval.integer_value=atoi(yytext);
						store_token_name("NUM",yytext,yylineno);
						return INTEGER_NUMBER; }
{operator}				{store_token_name("ARITHOP",yytext,yylineno);
						return yytext[0]; }
{meta_char}				{store_token_name("META CHAR",yytext,yylineno);
						return yytext[0]; }
{name}					{yylval.string_value=new string(yytext);
						store_token_name("NAME",yytext,yylineno);
						return NAME;}
{commentsa}				;
[ \t] 					;
[\n]					;
;;+						;
.						{printf("Error: Line: %d: fatal flex scanner internal error -- no action found\n",yylineno);}
%%
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <iostream>
	#include <string>
	extern "C" void yyerror (char *);
	extern int yylex();
	extern int yylineno;
	Procedure * p;
	Symbol_Table* global_sym_tab;
	map<string, Procedure*> funmap;
	bool err=0;
%}

%union{
	int integer_value;
	double double_value;
	Data_Type data_type;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	list<Symbol_Table_Entry *> * mylist;
}



%type <integer_value> INTEGER_NUMBER
%type <double_value> DOUBLE_NUMBER
%type <data_type> T
%type <string_value> NAME UNDNAME KP
%type <ast> P Expr A stmt I I1 I2 W DOW cndr R F W1 K1 K2 W2 Print N RET F_CALL
%type <symbol_table> D MD LA LB
%type <mylist> L
%type <procedure> X FSTART FD
%type <ast_list> Y body LP LP1

%token ASSIGN NAME FLOAT INTEGER DOUBLE_NUMBER VOID INTEGER_NUMBER IF DO WHILE ELSE PRINT RETURN
%right '='
%right '?'
%left ':'
%left OR
%left AND
%left NOT
%left GT GTEQ LT LTEQ 
%left EQ NEQ
%left '+' '-' 
%left '*' '/'
%right UMINUS


%%

SR:			O PR{
				program_object.set_procedure_map(funmap);
				program_object.set_global_table(*global_sym_tab);
			}

O:			%empty{
				global_sym_tab=new Symbol_Table();
			}

PR:			PR FD{

			}|
			PR D{
				Symbol_Table * temp2=$2;
				temp2->set_table_scope(global);
				global_sym_tab->append_list(*temp2,yylineno);
			}| 
			PR FSTART{
			} |
			%empty{}

FD:			T NAME '(' LA ')' ';' {
				string *str=$2;
				if(*$2=="main" && $1!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main should be defined and it's type should be void\n",yylineno);
					exit(1);
				}
				else if(*$2=="main"){}
				else{
					*str=*str+"_";
				}
				if(funmap.find(*$2)!=funmap.end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Current procedure already defined\n",yylineno);
					exit(1);
				}
				Procedure* p1=new Procedure($1,*str,yylineno);
				Symbol_Table * temp=$4;
				temp->set_table_scope(local);
				p1->set_formal_param_list(*temp);
				funmap[p1->get_proc_name()] = p1;
				$$=p1;
			}

FSTART:		X Y {
				Procedure* temp = $1;
				temp->set_ast_list(*$2);
				$$ = temp;
			}

X: 			T NAME '(' LA ')' '{' MD {
				string * str=$2;
				if(*$2=="main" && $1!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main should be defined and it's type should be void\n",yylineno);
					exit(1);
				}
				else if(*$2=="main"){}
				else{
					*str=*str+"_";
				}

				if(funmap.find(*str)!=funmap.end()){
					if($1!=funmap[*str]->get_return_type()){
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return data types not matching\n",yylineno);
						exit(1);
					}
					list<Symbol_Table_Entry*> param_list = funmap[*str]->get_formal_param_list().get_table();
					list<Symbol_Table_Entry*> l=$4->get_table();
					if(l.size()!=param_list.size()){
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Number of parameters not matching\n",yylineno);
						exit(1);
					}
					list<Symbol_Table_Entry*>::iterator it1=param_list.begin();
					list<Symbol_Table_Entry*>::iterator it2=l.begin();
					for(;it1!=param_list.end();it1++){
						if((*it1)->get_data_type()!=(*it2)->get_data_type()){
							fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Parameters not matching\n",yylineno);
							exit(1);
						}
						if((*it2)->get_variable_name()=="#"){
							fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Parameters not given in function definition\n",yylineno);
							exit(1);
						}
						it2++;
					}

				}
				p=new Procedure($1,*str,yylineno);
				Symbol_Table * temp=$7;
				temp->set_table_scope(local);
				p->set_local_list(*temp);
				Symbol_Table * temp2 = $4;
				temp2->set_table_scope(formal);
				p->set_formal_param_list(*temp2);
				funmap[*str]=p;
				$$=p;
			}

LA:			LB {$$=$1;}|
			%empty {
				Symbol_Table * temp=new Symbol_Table();
				$$= temp;
			}

KP:			UNDNAME{$$=$1;}|
			%empty{
				string * temp=new string("#");
				$$=temp;
			}
LB:			LB ',' INTEGER KP {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*$4, int_data_type, yylineno, fp_ref);
				Symbol_Table* t1=$1;
				t1->push_symbol(temp);
				$$ = t1;
			}|
			LB ',' FLOAT KP {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*$4, double_data_type, yylineno, fp_ref);
				Symbol_Table* t1=$1;
				t1->push_symbol(temp);
				$$ = t1;
			}|
			INTEGER KP{
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*$2, int_data_type, yylineno, fp_ref);
				Symbol_Table* temp2 = new Symbol_Table();
				temp2->push_symbol(temp);
				$$ = temp2;
			}|
			FLOAT KP{
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*$2, double_data_type, yylineno, fp_ref);
				Symbol_Table* temp2 = new Symbol_Table();
				temp2->push_symbol(temp);
				$$ = temp2;
			}

Y:			body '}' {
				if(err){
					exit(1);
				}
				$$=$1;
			}

T:			VOID {$$=void_data_type;} |
			INTEGER {$$=int_data_type;} |
			FLOAT {$$=double_data_type;}

body:		body R {
				list<Ast *> * temp=$1;
				temp->push_back($2);
				$$=temp;	
			} | %empty {
				$$=new list<Ast *>;
			}

stmt: 		I {$$ = $1;} | 
			A {$$ = $1;} | 
			W {$$ = $1;} | 
			DOW {$$ = $1;} |
			Print {$$ = $1;} |
			RET {$$=$1;} |
			F_CALL ';' {$$=$1;}

F_CALL:		NAME '(' LP ')' {
				if((*$1)=="main"){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main is not callable\n",yylineno);
					exit(1);
				}
				string * str=$1;
				*str=*str+"_";
				if(funmap.find(*str)==funmap.end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Function does not exist\n",yylineno);
					exit(1);
				}
				Call_Ast * temp=new Call_Ast(*str,yylineno);
				temp->set_data_type(funmap[*str]->get_return_type());
				temp->set_actual_param_list(*$3);
				temp->set_register(NULL);
				$$=temp;
			}

LP1:		LP1 ',' Expr {
				list<Ast*>* temp=$1;
				temp->push_back($3);
				$$=temp;
			}|
			Expr {
				list<Ast*> *temp=new list<Ast*>;
				temp->push_back($1);
				$$=temp;
			}

LP:			%empty {
				list<Ast*> *temp=new list<Ast*>;
				$$=temp;
			}|
			LP1 {$$=$1;}

RET:		RETURN ';'{
				Return_Ast* temp=new Return_Ast(NULL,p->get_proc_name(),yylineno);
				if(p->get_return_type()!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return value required\n",yylineno);
					exit(1);
				}
				$$=temp;
			}|
			RETURN Expr ';'{
				Return_Ast* temp=new Return_Ast($2,p->get_proc_name(),yylineno);
				if(p->get_return_type()!=$2->get_data_type()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return value does not matc the required\n",yylineno);
					exit(1);
				}
				$$=temp;
			}

Print: 		PRINT N ';'{
				Print_Ast* temp = new Print_Ast($2, yylineno);
				$$ = temp;
			}

K1:			A {$$ = $1;}| DOW {$$ = $1;}| F {$$ = $1;}| W1 {$$ = $1;}| I1 {$$ = $1;}| Print {$$ = $1;}| RET {$$=$1;}| F_CALL ';' {$$=$1;}
K2:			I2 {$$ = $1;}| W2 {$$ = $1;}

W2:			WHILE '(' cndr ')' K2 {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast($3, $5, yylineno,0);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}

W1:			WHILE '(' cndr ')' K1 {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast($3, $5, yylineno,0);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}

F: 			'{' body '}' {
				Sequence_Ast* temp = new Sequence_Ast(yylineno);
				list<Ast*>::iterator it;
				if($2->begin()==$2->end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Empty block\n",yylineno);
					exit(1);
				}
				for(it=$2->begin();it!=$2->end();it++){
					temp->ast_push_back(*it);
				}
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}

R:			F {$$ = $1;} | stmt {$$ = $1;}

I:			I1 {$$ = $1;} | I2 {$$ = $1;}

I1: 		IF '(' cndr ')' K1 ELSE K1 {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast($3, $5, $7,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}
I2:			IF '(' cndr ')' R {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast($3, $5, NULL,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			} | IF '(' cndr ')' K1 ELSE K2 {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast($3, $5, $7,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}

W: 			WHILE '(' cndr ')' R {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast($3, $5, yylineno,0);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}
DOW:        DO R WHILE '(' cndr ')' ';' {
				Iteration_Statement_Ast* temp = new Iteration_Statement_Ast($5, $2,yylineno, 1);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}

cndr: 		Expr GT Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,greater_than,$3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| Expr GTEQ Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,greater_equalto,$3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| Expr LT Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,less_than,$3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| Expr LTEQ Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,less_equalto,$3,yylineno);
				temp->check_ast();
				$$ = temp;
			}| Expr NEQ Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,not_equalto,$3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| Expr EQ Expr{
				Relational_Expr_Ast* temp = new Relational_Expr_Ast($1,equalto,$3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| NOT cndr {
				Logical_Expr_Ast* temp = new Logical_Expr_Ast(NULL, _logical_not, $2,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			}| '(' cndr ')' {
				$$ = $2;
			}| cndr AND cndr {
				Logical_Expr_Ast *temp = new Logical_Expr_Ast($1, _logical_and , $3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			} | cndr OR cndr {
				Logical_Expr_Ast *temp = new Logical_Expr_Ast($1, _logical_or , $3,yylineno);
				if(!temp->check_ast())
					err= 1;
				$$ = temp;
			} 

MD:			D MD {
				Symbol_Table * temp=$1;
				temp->append_list(*$2,yylineno);
				$$=temp;
			} | 
			%empty {
				$$=new Symbol_Table();
			}

D: 			T L ';' {
				if($1==void_data_type){
					yyerror("cs316: Error: error: void datatype for variable not supported\n");
					exit(1);
				}
				list<Symbol_Table_Entry *> * temp=$2;
				list<Symbol_Table_Entry *>::iterator it;
				Symbol_Table * A=new Symbol_Table();
				for(it=temp->begin();it!=temp->end();it++){
					(*it)->set_data_type($1);
					if(A->variable_in_symbol_list_check((*it)->get_variable_name())){
						yyerror("cs316: Error: error: Variable is declared twice\n");
						exit(1);
					}
					A->push_symbol(*it);
				}
				$$=A;
			}

L: 			UNDNAME ',' L {
				list<Symbol_Table_Entry *> *temp=$3;
				temp->push_front(new Symbol_Table_Entry(*$1,int_data_type,yylineno));
				$$=temp;
			} | 
			UNDNAME {
				list<Symbol_Table_Entry *> *temp= new list<Symbol_Table_Entry *>;
				temp->push_front(new Symbol_Table_Entry(*$1,int_data_type,yylineno));
				$$=temp;
			}

A:			UNDNAME ASSIGN Expr ';' {
				Symbol_Table_Entry temp1;
				Name_Ast * temp;
				if(p->variable_in_symbol_list_check(*$1)){
					temp1=p->get_symbol_table_entry(*$1);
					temp=new Name_Ast(*$1,p->get_symbol_table_entry(*$1),yylineno);
					temp->set_data_type(p->get_symbol_table_entry(*$1).get_data_type());
				}
				else{
					if(p->variable_in_formal_list_check(*$1)){
						temp1=p->get_formal_param_entry(*$1);
						temp=new Name_Ast(*$1,p->get_formal_param_entry(*$1),yylineno);
						temp->set_data_type(p->get_formal_param_entry(*$1).get_data_type());
					}
					else if(global_sym_tab->variable_in_symbol_list_check(*$1)){
						temp1=global_sym_tab->get_symbol_table_entry(*$1);
						temp=new Name_Ast(*$1,global_sym_tab->get_symbol_table_entry(*$1),yylineno);
						temp->set_data_type(global_sym_tab->get_symbol_table_entry(*$1).get_data_type());
					}
					else{
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Variable has not been declared\n",yylineno);
						exit(1);
					}
				}
				Assignment_Ast * res=new Assignment_Ast(temp,$3,yylineno);
				if(!res->check_ast()){
					err=1;
				}
				$$=res;
			}

Expr:		
			'(' Expr ')' {
				$$ = $2;
			}|
			'-' Expr %prec UMINUS {
				UMinus_Ast * temp=new UMinus_Ast($2, NULL, yylineno);
				temp->set_data_type($2->get_data_type());
				$$=temp;
			} |
			Expr '*' Expr {
				Mult_Ast * temp=new Mult_Ast($1,$3,yylineno);
				temp->set_data_type($1->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				$$=temp;
			} |
			Expr '-' Expr {
				Minus_Ast * temp=new Minus_Ast($1,$3,yylineno);
				temp->set_data_type($1->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				$$=temp;
			} |
			Expr '/' Expr {
				Divide_Ast * temp=new Divide_Ast($1,$3,yylineno);
				temp->set_data_type($1->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				$$=temp;
			} |
			Expr '+' Expr {
				Plus_Ast * temp=new Plus_Ast($1,$3,yylineno);
				temp->set_data_type($1->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				$$=temp;
			} |
			cndr '?' Expr ':' Expr {
				Conditional_Expression_Ast* temp = new Conditional_Expression_Ast($1, $3, $5, yylineno);
				temp->set_data_type($3->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				$$= temp;
			} |
			P {
				$$=$1;
			}|
			F_CALL{
				if($1->get_data_type()==void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Void data type cannot be used in expression\n",yylineno);
					exit(1);
				}
				Call_Ast* temp=(Call_Ast*) $1;
				temp->set_register(new Register_Descriptor());
				$$=temp;
			}

P: 			N{
				$$ = $1;
			} | 
			INTEGER_NUMBER {
				Number_Ast<int> * temp=new Number_Ast<int>($1,int_data_type,yylineno);
				temp->set_data_type(int_data_type);
				$$=temp;
			} |
			DOUBLE_NUMBER {
				Number_Ast<double> * temp =new Number_Ast<double>($1,double_data_type,yylineno);
				temp->set_data_type(double_data_type);
				$$=temp;
			}

N:			UNDNAME {
				string* str = $1;
				if(p->variable_in_symbol_list_check(*str)){
					Name_Ast * temp = new Name_Ast(*str,p->get_symbol_table_entry(*str),yylineno);
					temp->set_data_type(p->get_symbol_table_entry(*str).get_data_type());
					$$=temp;
				}
				else if(p->variable_in_formal_list_check(*str)){
					Name_Ast * temp = new Name_Ast(*str,p->get_formal_param_entry(*str),yylineno);
					temp->set_data_type(p->get_formal_param_entry(*str).get_data_type());
					$$=temp;
				}
				else{
					if(global_sym_tab->variable_in_symbol_list_check(*str)){
						Name_Ast* temp = new Name_Ast(*str,global_sym_tab->get_symbol_table_entry(*str),yylineno);
						temp->set_data_type(global_sym_tab->get_symbol_table_entry(*str).get_data_type());
						$$=temp;
					}
					else{
						yyerror("cs316: Error: error: variable not declared\n");
						exit(1);
					}
				}
			}

UNDNAME:  	NAME {
				string* str = $1;
				*str = *str + "_";
				$$ = str;
			}
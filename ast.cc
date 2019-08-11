
int Ast::labelCounter = 0;

Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line)
{
	lhs=temp_lhs;
	rhs=temp_rhs;
	ast_num_child=Ast::binary_arity;
	lineno=line;
	node_data_type=void_data_type;
}

Assignment_Ast::~Assignment_Ast(){}

bool Assignment_Ast::check_ast()
{
	if(lhs->get_data_type()==rhs->get_data_type()){
		return 1;
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Assignment statement data type not compatible\n",lineno);
		return 0;
	}
}

void Assignment_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"Asgn:\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

template class Number_Ast<int>;
template class Number_Ast<double>;

template <class T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line){
	constant=number;
	ast_num_child=Ast::zero_arity;
	node_data_type=constant_data_type;
	lineno=line;
}

template <class T>
Number_Ast<T>::~Number_Ast(){

}

template <class T>
Data_Type Number_Ast<T>::get_data_type(){
	return node_data_type;
}

template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt){
	node_data_type=dt;
}

template <class T>
bool Number_Ast<T>::is_value_zero(){
	return constant==0;
}

template <class T>
void Number_Ast<T>::print(ostream & file_buffer){
	file_buffer<<"Num : "<<constant;

}

Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line){
	lhs=l;
	rhs=r;
	node_data_type=lhs->get_data_type();
	ast_num_child=Ast::binary_arity;
	lineno=line;
}

void Minus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MINUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line){
	lhs=l;
	rhs=r;
	node_data_type=lhs->get_data_type();
	ast_num_child=Ast::binary_arity;
	lineno=line;
}

void Divide_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: DIV\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line){
	lhs=l;
	rhs=r;
	node_data_type=lhs->get_data_type();
	ast_num_child=Ast::unary_arity;
	lineno=line;
}

void UMinus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: UMINUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
}

Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line)
{
	variable_symbol_entry = &var_entry;
	lineno = lineno;
	ast_num_child = Ast::zero_arity;
	set_data_type(variable_symbol_entry->get_data_type());
}

Name_Ast::~Name_Ast()
{
	// delete variable_symbol_entry;
}

Data_Type Name_Ast::get_data_type()
{
	return node_data_type;
}

void Name_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

Symbol_Table_Entry & Name_Ast::get_symbol_entry()
{
	return *variable_symbol_entry;
}

void Name_Ast::print(ostream & file_buffer)
{
	file_buffer<<"Name : "<<variable_symbol_entry->get_variable_name();
}

Data_Type Arithmetic_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Arithmetic_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast()
{
	if(lhs== NULL || rhs == NULL)
	{
		return 1;
	}
	if(lhs->get_data_type() == rhs->get_data_type())
	{
		return 1;	
	}
	else
	{
		fprintf(stderr,"cs316: Error: error: Line: %d: Arithmetic statement data type not compatible\n",lineno);
		return 0;
	}
}

Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno= line;
	ast_num_child = Ast::binary_arity;
	set_data_type(l->get_data_type());
}

void Plus_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: PLUS\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno= line;
	ast_num_child = Ast::binary_arity;
	set_data_type(l->get_data_type());
}

void Mult_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MULT\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Return_Ast::Return_Ast(Ast * ret_val, string name, int line){
	lineno= line;
	return_value=ret_val;
	proc_name=name;
}

Return_Ast::~Return_Ast(){}

void Return_Ast::print(ostream & file_buffer){
	file_buffer<<AST_SPACE<<"RETURN ";
	if(return_value==NULL){
		file_buffer<<"<NOTHING>";
	}
	else{
		return_value->print(file_buffer);
	}
}

Data_Type Return_Ast::get_data_type(){
	if(return_value==NULL){
		return void_data_type;
	}
	else{
		return return_value->get_data_type();
	}
}


Ast::Ast(){}
Ast::~Ast(){}

Data_Type Ast::get_data_type(){
	return node_data_type;
}
void Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Ast:: is_value_zero(){
	return 0;
}

bool Ast::check_ast(){
	return 1;
}

Symbol_Table_Entry & Ast::get_symbol_entry(){
	return *(new Symbol_Table_Entry());
}


Logical_Expr_Ast::Logical_Expr_Ast(Ast * lhs, Logical_Op bop, Ast * rhs, int line){
	lhs_op=lhs;
	rhs_op=rhs;
	bool_op=bop;
	ast_num_child=Ast::binary_arity;
	lineno=line;
	node_data_type=rhs->get_data_type();
}

Data_Type Logical_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Logical_Expr_Ast::check_ast()
{
	if(lhs_op==NULL && rhs_op->get_data_type()==int_data_type){
		return 1;
	}
	else if(lhs_op==NULL){
		fprintf(stderr,"cs316: Error: error: Line: %d: Logical Expression \'NOT\' rhs data type not compatible\n",lineno);
		return 0;
	}
	if(lhs_op->get_data_type() == rhs_op->get_data_type() && lhs_op->get_data_type()==int_data_type)
	{
		return 1;
	}
	else
	{
		fprintf(stderr,"cs316: Error: error: Line: %d: Logical Expression data type not compatible\n",lineno);
		return 0;
	}
}

void Logical_Expr_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: ";
	if(bool_op==_logical_not){
		file_buffer<<"NOT";
		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_op->print(file_buffer);
		file_buffer<<")";
		return;
	}
	if(bool_op==_logical_and)
		file_buffer<<"AND";
	else if(bool_op==_logical_or)
		file_buffer<<"OR";
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_op->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_op->print(file_buffer);
	file_buffer<<")";
}

Relational_Expr_Ast::Relational_Expr_Ast(Ast * lhs, Relational_Op rop, Ast * rhs, int line)
{
	lhs_condition = lhs;
	rhs_condition = rhs;
	rel_op = rop;
	lineno= line;
	ast_num_child = Ast::binary_arity;
	node_data_type = lhs->get_data_type();
}

Relational_Expr_Ast::~Relational_Expr_Ast()
{

}

Data_Type Relational_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Relational_Expr_Ast::check_ast()
{
	if(lhs_condition->get_data_type() == rhs_condition->get_data_type())
	{
		return 1;
	}
	else
	{
		printf("sssss\n");
		if(lhs_condition->get_data_type() == int_data_type)
			printf("llll\n");
		fprintf(stderr,"cs316: Error: error: Line: %d: Relational Expression not valid\n",lineno);
		return 0;
	}
}

void Relational_Expr_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: ";
	if(rel_op==less_equalto)
	{
		file_buffer<<"LE";
	}
	else if(rel_op==less_than)
	{
		file_buffer<<"LT";
	}
	else if(rel_op==greater_than)
	{	
		file_buffer<<"GT";
	}
	else if(rel_op== greater_equalto)
	{
		file_buffer<<"GE";
	}
	else if(rel_op == not_equalto)
	{
		file_buffer<<"NE";
	}
	else if(rel_op == equalto)
	{
		file_buffer<<"EQ";
	}
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_condition->print(file_buffer);
	file_buffer<<")\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_condition->print(file_buffer);
	file_buffer<<")";
}

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* c, Ast* l, Ast* r, int line)
{
	lhs = l;
	rhs = r;
	cond = c;
	lineno = line;
	ast_num_child = Ast::ternary_arity;
	node_data_type = lhs->get_data_type();
	labelCounter++;
}

Conditional_Expression_Ast::~Conditional_Expression_Ast()
{

}

void Conditional_Expression_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"Cond:\n"<<AST_NODE_SPACE<<"IF_ELSE";
	cond->print(file_buffer);
	file_buffer<<"\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n"<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Selection_Statement_Ast::Selection_Statement_Ast(Ast * condr,Ast* then_partr, Ast* else_partr, int line){
	cond =condr;
	else_part=else_partr;
	then_part=then_partr;
	lineno=line;
	ast_num_child=Ast::ternary_arity;
	node_data_type=void_data_type;
	labelCounter++;
}

Selection_Statement_Ast::~Selection_Statement_Ast(){}

Data_Type Selection_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Selection_Statement_Ast::check_ast(){
	if(then_part->get_data_type()==void_data_type){
		if(else_part==NULL || else_part->get_data_type()==void_data_type)
			return 1;
		else{
			fprintf(stderr,"cs316: Error: error: Line: %d: IF Condition: Else part: Relational Expression not valid\n",lineno);
			return 0;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: IF Condition: Relational Expression not valid\n",lineno);
		return 0;
	}
}

void Selection_Statement_Ast::print(ostream& file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"IF :\n"<<AST_SPACE<<"CONDITION (";
	cond->print(file_buffer);
	file_buffer<<")\n"<<AST_SPACE<<"THEN (";
	then_part->print(file_buffer);
	file_buffer<<")";
	if(else_part==NULL){
		return;
	}
	file_buffer<<"\n"<<AST_SPACE<<"ELSE (";
	else_part->print(file_buffer);
	file_buffer<<")";

}

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * condr, Ast* bodyr, int line, bool do_form){
	cond=condr;
	body=bodyr;
	lineno=line;
	is_do_form=do_form;
	node_data_type=void_data_type;
	ast_num_child=Ast::binary_arity;
}

Data_Type Iteration_Statement_Ast::get_data_type(){
	return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt){
	node_data_type=dt;
}

bool Iteration_Statement_Ast::check_ast(){
	if(cond!=NULL && body!=NULL){
		return 1;
	}
	return 0;
}

void Iteration_Statement_Ast::print(ostream &file_buffer)
{
	if(is_do_form){
		file_buffer<<"\n"<<AST_SPACE<<"DO (";
		body->print(file_buffer);
		file_buffer<<")\n"<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
	}
	else{
		file_buffer<<"\n"<<AST_SPACE<<"WHILE :";
		file_buffer<<"\n"<<AST_SPACE<<"CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")\n"<<AST_SPACE<<"BODY (";
		body->print(file_buffer);
		file_buffer<<")";
	}
}

Sequence_Ast::Sequence_Ast(int line){
	lineno=line;
	node_data_type=void_data_type;
	ast_num_child=Ast::unary_arity;

}

Sequence_Ast::~Sequence_Ast(){
	int n=statement_list.size();
	for(int i=0;i<n;i++){
		statement_list.pop_front();
	}
}

void Sequence_Ast::ast_push_back(Ast * ast){
	statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream & file_buffer){
	list<Ast*>::iterator it;
	file_buffer<<"\n";
	for(it=statement_list.begin();it!=statement_list.end();it++){
		(*it)->print(file_buffer);
	}
}

Print_Ast::Print_Ast(Ast* v, int line)
{
	var = v;
	lineno = line;
}

Print_Ast::~Print_Ast(){}

void Print_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"Print :\n"<<AST_SUB_NODE_SPACE<<"(";
	var->print(file_buffer);
	file_buffer<<")";
}


Call_Ast::Call_Ast(string name, int line){
	procedure_name = name;
	lineno = line;
	ast_num_child=Ast::unary_arity;
}

Call_Ast::~Call_Ast(){}

Data_Type Call_Ast::get_data_type(){
	return node_data_type;
}
void Call_Ast::set_register(Register_Descriptor * reg){
	return_value_reg = reg;
}

void Call_Ast::check_actual_formal_param(Symbol_Table & formal_param_list){
	list <Symbol_Table_Entry*> t=formal_param_list.get_table();
	if(actual_param_list.size()!=t.size()){
		fprintf(stderr,"cs316: Error: error: Line: %d: Number of parameters don't match\n",lineno);
		exit(1);
	}
	list<Symbol_Table_Entry*>::iterator it1;
	list<Ast*>::iterator it2 = actual_param_list.begin();
	for(it1=t.begin();it1!=t.end();it1++){
		if((*it1)->get_data_type()!=(*it2)->get_data_type()){
			fprintf(stderr,"cs316: Error: error: Line: %d: Data types of parameters don't match\n",lineno);
			exit(1);
		}
		it2++;
	}
}

void Call_Ast::set_actual_param_list(list<Ast *> & param_list){
	actual_param_list = param_list;
}

void Call_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_SPACE<<"FN CALL: "<<procedure_name<<"(";
	if(actual_param_list.size()==0){
		file_buffer<<")";
	}
	else{
		// file_buffer<<"\n";
		list<Ast*>::iterator it;
		for(it=actual_param_list.begin();it!=actual_param_list.end();it++){
			file_buffer<<"\n"<<AST_NODE_SPACE;
			(*it)->print(file_buffer);
		}
		file_buffer<<")";
	}
}

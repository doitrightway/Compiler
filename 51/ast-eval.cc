
Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env){}
void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){}
void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){}

Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &temp = rhs->evaluate(eval_env, file_buffer);
	// printf("%d\n", temp.get_int_value());
	if(!temp.is_variable_defined())
	{
		fprintf(stderr, "cs316: Error: error: Line: %d: Undefined assignment\n",lineno);
		exit(1);
	}
	if(eval_env.does_variable_exist(lhs->get_symbol_entry().get_variable_name()))
	{
		lhs->set_value_of_evaluation(eval_env, temp);
		print(file_buffer);
		file_buffer<<"\n"<<VAR_SPACE;
		lhs->print_value(eval_env, file_buffer);
	}
	else
	{
		lhs->set_value_of_evaluation(interpreter_global_table, temp);
		print(file_buffer);
		file_buffer<<"\n"<<VAR_SPACE;
		lhs->print_value(interpreter_global_table, file_buffer);
	}
	
	Eval_Result_Value_Int *ret=new Eval_Result_Value_Int();
	ret->set_result_enum(void_result);
	ret->set_variable_status(1);
	return *ret;
}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	string nm = variable_symbol_entry->get_variable_name();
	if(eval_env.does_variable_exist(nm))
	{
		if(eval_env.is_variable_defined(nm))
		{
			return *eval_env.get_variable_value(nm);
		}
		else
		{
			fprintf(stderr, "cs316: Error: error: Line: %d: Undefined variable\n",lineno);
			exit(1);
		}
	}
	else if(interpreter_global_table.does_variable_exist(nm))
	{
		return *interpreter_global_table.get_variable_value(nm);
	}
	else
	{
		fprintf(stderr, "cs316: Error: error: Line: %d: Variable not declared\n",lineno);
		exit(1);
	}
}
void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer){
	string nm = variable_symbol_entry->get_variable_name();
	file_buffer<<nm.c_str()<<" : ";
	if(eval_env.get_variable_value(nm)->get_result_enum()==int_result){
		file_buffer<<eval_env.get_variable_value(nm)->get_int_value()<<"\n\n";
	}
	else{
		file_buffer<<eval_env.get_variable_value(nm)->get_double_value()<<"\n\n";
	}
}
Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env){}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result){
	eval_env.put_variable_value(result, variable_symbol_entry->get_variable_name());
}

template class Number_Ast<int>;
template class Number_Ast<double>;


template<class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	if(node_data_type==int_data_type){
		Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
		temp->set_result_enum(int_result);
		temp->set_value(constant);
		temp->set_variable_status(1);
		// Eval_Result* tt=new Eval_Result();

		// printf("%d\n", temp->get_int_value());

		return *temp;
	}
	Eval_Result_Value_Double *temp=new Eval_Result_Value_Double();
	temp->set_result_enum(double_result);
	temp->set_value(constant);
	temp->set_variable_status(1);
	return *temp;
}

Eval_Result & Arithmetic_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		if(t1.get_result_enum()==int_result){
			Eval_Result_Value_Int* temp=new Eval_Result_Value_Int();
			temp->set_variable_status(1);
			temp->set_result_enum(int_result);
			temp->set_value(t1.get_int_value()+t2.get_int_value());
			return *temp;
		}
		else{
			Eval_Result_Value_Double * temp=new Eval_Result_Value_Double();
			temp->set_variable_status(1);
			temp->set_result_enum(double_result);
			temp->set_value(t1.get_double_value()+t2.get_double_value());
			return *temp;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		if(t1.get_result_enum()==int_result){
			Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
			temp->set_variable_status(1);
			temp->set_result_enum(int_result);
			temp->set_value(t1.get_int_value()-t2.get_int_value());
			return *temp;
		}
		else{
			Eval_Result_Value_Double *temp=new Eval_Result_Value_Double();
			temp->set_variable_status(1);
			temp->set_result_enum(double_result);
			temp->set_value(t1.get_double_value()-t2.get_double_value());
			return *temp;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		if(t1.get_result_enum()==int_result){
			if(t2.get_int_value()==0){
				fprintf(stderr,"cs316: Error: error: Line: %d: Divide by 0\n",lineno);
				exit(1);
			}
			Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
			temp->set_variable_status(1);
			temp->set_result_enum(int_result);
			temp->set_value(t1.get_int_value()/t2.get_int_value());
			return *temp;
		}
		else{
			if(t2.get_double_value()==0){
				fprintf(stderr,"cs316: Error: error: Line: %d: Divide by 0\n",lineno);
				exit(1);
			}
			Eval_Result_Value_Double *temp=new Eval_Result_Value_Double();
			temp->set_variable_status(1);
			temp->set_result_enum(double_result);
			temp->set_value(t1.get_double_value()/t2.get_double_value());
			return *temp;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		if(t1.get_result_enum()==int_result){
			Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
			temp->set_variable_status(1);
			temp->set_result_enum(int_result);
			temp->set_value(t1.get_int_value()*t2.get_int_value());
			return *temp;
		}
		else{
			Eval_Result_Value_Double *temp=new Eval_Result_Value_Double();
			temp->set_variable_status(1);
			temp->set_result_enum(double_result);
			temp->set_value(t1.get_double_value()*t2.get_double_value());
			return *temp;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined()){
		if(t1.get_result_enum()==int_result){
			Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
			temp->set_variable_status(1);
			temp->set_result_enum(int_result);
			temp->set_value(t1.get_int_value()*-1);
			return *temp;
		}
		else{
			Eval_Result_Value_Double *temp=new Eval_Result_Value_Double();
			temp->set_variable_status(1);
			temp->set_result_enum(double_result);
			temp->set_value(t1.get_double_value()*-1);
			return *temp;
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=cond->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined()){
		if((bool)t1.get_int_value()){
			return lhs->evaluate(eval_env,file_buffer);
		}
		else{
			return rhs->evaluate(eval_env,file_buffer);
		}
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	if(return_value==NULL){
		print(file_buffer);
		Eval_Result_Value_Int * temp=new Eval_Result_Value_Int();
		return *temp;
	}
	file_buffer<<"\n"<<VAR_SPACE<<"RETURN ";
	return_value->print(file_buffer);
	Eval_Result & ret = return_value->evaluate(eval_env,file_buffer);
	eval_env.put_variable_value(ret, "Return");
	return ret;
	// return *temp;
}
Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result &t1=lhs_condition->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs_condition->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		double a,b;
		if(t1.get_result_enum()==int_result){
			a=t1.get_int_value();
			b=t2.get_int_value();
		}
		else{
			a=t1.get_double_value();
			b=t2.get_double_value();
		}
		Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
		temp->set_result_enum(int_result);
		temp->set_variable_status(1);
		switch(rel_op){
			case less_equalto:temp->set_value((int)(a<=b));break;
			case less_than:temp->set_value((int)(a<b));break;
			case greater_equalto:temp->set_value((int)(a>=b));break;
			case greater_than:temp->set_value((int)(a>b));break;
			case equalto:temp->set_value((int)(a==b));break;
			case not_equalto:temp->set_value((int)(a!=b));break;
		}
		return *temp;
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	if(bool_op==_logical_not){
		Eval_Result &t2=rhs_op->evaluate(eval_env,file_buffer);
		if(t2.is_variable_defined()){
			Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
			temp->set_result_enum(int_result);
			temp->set_variable_status(1);
			temp->set_value(!t2.get_int_value());
			return *temp;
		}
		else{
			fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
			exit(1);
		}
	}
	Eval_Result &t1=lhs_op->evaluate(eval_env,file_buffer);
	Eval_Result &t2=rhs_op->evaluate(eval_env,file_buffer);
	if(t1.is_variable_defined() && t2.is_variable_defined()){
		int a,b;
		if(t1.get_result_enum()==int_result){
			a=t1.get_int_value();
			b=t2.get_int_value();
		}
		else{
			a=t1.get_double_value();
			b=t2.get_double_value();
		}
		Eval_Result_Value_Int *temp=new Eval_Result_Value_Int();
		temp->set_result_enum(int_result);
		temp->set_variable_status(1);
		switch(bool_op){
			case _logical_or:temp->set_value((int)(a || b));break;
			case _logical_and:temp->set_value((int)(a && b));break;
		}
		return *temp;
	}
	else{
		fprintf(stderr,"cs316: Error: error: Line: %d: Variable should be defined before its use\n",lineno);
		exit(1);
	}
}
Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result & temp1 = cond->evaluate(eval_env, file_buffer);
	Eval_Result_Value_Int *ret=new Eval_Result_Value_Int();
	if(!temp1.is_variable_defined())
	{
		fprintf(stderr, "cs316: Error: error: Line: %d: Variable not defined\n",lineno);
		exit(1);
	}
	else if(temp1.get_int_value())
	{
		// printf("rrr\n");
		then_part->evaluate(eval_env, file_buffer);
		// printf("rrrs\n");
	}
	else if(else_part!=NULL)
	{
		else_part->evaluate(eval_env, file_buffer);
	}
	ret->set_result_enum(void_result);
	return *ret;
}
Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// Eval_Result & temp1 = cond->evaluate(eval_env, file_buffer);
	Eval_Result_Value_Int *ret=new Eval_Result_Value_Int();
	// if(!temp1.is_variable_defined())
	// {
	// 	fprintf(stderr, "cs316: Error: error: Line: %d: Variable not defined\n",lineno);
	// 	exit(1);
	// }
	if(is_do_form)
	{
		do
		{
			body->evaluate(eval_env, file_buffer);
			// temp1 =  cond->evaluate(eval_env, file_buffer);
		}while(cond->evaluate(eval_env, file_buffer).is_variable_defined() && 
			cond->evaluate(eval_env, file_buffer).get_int_value() == 1);
	}
	else
	{
		while(cond->evaluate(eval_env,file_buffer).get_int_value() == 1)
		{
			body->evaluate(eval_env, file_buffer);
		}
	}
	ret->set_result_enum(void_result);
	return *ret;
}
Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	list<Ast *>:: iterator it = statement_list.begin();
	Eval_Result_Value_Int *ret=new Eval_Result_Value_Int();
	while(it != statement_list.end())
	{
		(*it)->evaluate(eval_env, file_buffer);
		it++;
	}
	ret->set_result_enum(void_result);
	return *ret;
}


Eval_Result & Call_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Local_Environment* my_env = new Local_Environment();
	Procedure *p = program_object.get_procedure_prototype(procedure_name);
	Symbol_Table local_table = p->get_local_list();
	Symbol_Table formal_table = p->get_formal_param_list();
	list<Symbol_Table_Entry *> local_entry = local_table.get_table();
	list<Symbol_Table_Entry *> formal_entry = formal_table.get_table();
	list<Symbol_Table_Entry *> :: iterator it = formal_entry.begin();
	list<Ast *> :: iterator it2 = actual_param_list.begin();
	while(it!=formal_entry.end())
	{
		Eval_Result& result = (*it2)->evaluate(eval_env, file_buffer);
		my_env->put_variable_value(result, (*it)->get_variable_name());
		it++;
		it2++;
	}
	it = local_entry.begin();
	while(it!=local_entry.end())
	{
		if((*it)->get_data_type() == int_data_type)
		{
			Eval_Result_Value_Int* result = new Eval_Result_Value_Int();
			my_env->put_variable_value(*result, (*it)->get_variable_name());
		}	
		else
		{
			Eval_Result_Value_Double* result = new Eval_Result_Value_Double();
			my_env->put_variable_value(*result, (*it)->get_variable_name());
		}
		it++;
	}
	return p->evaluate(*my_env, file_buffer);
}
Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register){}

Code_For_Ast & Name_Ast::compile()
{
	Mem_Addr_Opd * opd1 = new Mem_Addr_Opd(*variable_symbol_entry);

	Register_Descriptor* rd;
	Register_Addr_Opd * result;
	Move_IC_Stmt * stmt;

	if(variable_symbol_entry->get_data_type()== int_data_type)
	{
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Move_IC_Stmt(load, opd1, result);
	}
	else if(variable_symbol_entry->get_data_type()== double_data_type)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Move_IC_Stmt(load_d, opd1, result);
	}

	Code_For_Ast* temp = new Code_For_Ast();
	temp->append_ics(*stmt);
	temp->set_reg(rd);
	return *temp;
}

Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register){
	Mem_Addr_Opd * result = new Mem_Addr_Opd(*variable_symbol_entry);
	Register_Addr_Opd * opd1 = new Register_Addr_Opd(store_register);
	Move_IC_Stmt * stmt;
	if(variable_symbol_entry->get_data_type()== int_data_type)
	{
		stmt = new Move_IC_Stmt(store, opd1, result);
	}
	else if(variable_symbol_entry->get_data_type()== double_data_type)
	{
		stmt = new Move_IC_Stmt(store_d, opd1, result);
	}
	Code_For_Ast* temp = new Code_For_Ast();
	temp->append_ics(*stmt);
	store_register->reset_register_occupied();
	return *temp;
}

Code_For_Ast & Print_Ast::compile()
{
	Code_For_Ast* temp = new Code_For_Ast();

	Register_Addr_Opd * result1 = new Register_Addr_Opd(machine_desc_object.spim_register_table[v0]);
	Register_Addr_Opd * result2 = new Register_Addr_Opd(machine_desc_object.spim_register_table[a0]);
	Register_Addr_Opd * result3 = new Register_Addr_Opd(machine_desc_object.spim_register_table[f12]);
	Mem_Addr_Opd* mem = new Mem_Addr_Opd(var->get_symbol_entry());
	Move_IC_Stmt * stmt1;
	Move_IC_Stmt * stmt2;
	if(var->get_data_type()== int_data_type)
	{
		Const_Opd<int> * opd1 = new Const_Opd<int>(1);
		stmt1 = new Move_IC_Stmt(imm_load, opd1, result1);
		stmt2 = new Move_IC_Stmt(load, mem, result2);
	}	
	else if(var->get_data_type()== double_data_type)
	{
		Const_Opd<int> * opd1 = new Const_Opd<int>(3);
		stmt1 = new Move_IC_Stmt(imm_load, opd1, result1);
		stmt2 = new Move_IC_Stmt(load_d, mem, result3);
	}

	Print_IC_Stmt* stmt3 = new Print_IC_Stmt();
	temp->append_ics(*stmt1);
	temp->append_ics(*stmt2);
	temp->append_ics(*stmt3);
	return *temp;
}


Code_For_Ast & Assignment_Ast::compile()
{
	Code_For_Ast c1 = rhs->compile();
	Code_For_Ast c2 = lhs->create_store_stmt(c1.get_reg());
	list<Icode_Stmt *> l1 = c1.get_icode_list();
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	Code_For_Ast* temp = new Code_For_Ast(l1, NULL);
	return *temp;
}

Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Plus_Ast::compile()
{
	Code_For_Ast c1 = lhs->compile();
	Code_For_Ast c2 = rhs->compile();
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

	Register_Descriptor* rd;
	Compute_IC_Stmt* stmt;
	Register_Addr_Opd * result;
	if(c1.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(add_d, opd1, opd2, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();	
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(add, opd1, opd2, result);
	}

	c1.get_reg()->reset_register_occupied();
	c2.get_reg()->reset_register_occupied();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	Code_For_Ast* temp = new Code_For_Ast(l1, rd);
	temp->append_ics(*stmt);
	return *temp;
}

Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Minus_Ast::compile()
{
	Code_For_Ast c1 = lhs->compile();
	Code_For_Ast c2 = rhs->compile();
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

	Register_Descriptor* rd;
	Compute_IC_Stmt* stmt;
	Register_Addr_Opd * result;
	if(c1.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(sub_d, opd1, opd2, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();	
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(sub, opd1, opd2, result);
	}

	c1.get_reg()->reset_register_occupied();
	c2.get_reg()->reset_register_occupied();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	Code_For_Ast* temp = new Code_For_Ast(l1, rd);
	temp->append_ics(*stmt);
	return *temp;
}

Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Mult_Ast::compile()
{
	Code_For_Ast c1 = lhs->compile();
	Code_For_Ast c2 = rhs->compile();
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

	Register_Descriptor* rd;
	Compute_IC_Stmt* stmt;
	Register_Addr_Opd * result;
	if(c1.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(mult_d, opd1, opd2, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();	
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(mult, opd1, opd2, result);
	}

	c1.get_reg()->reset_register_occupied();
	c2.get_reg()->reset_register_occupied();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	Code_For_Ast* temp = new Code_For_Ast(l1, rd);
	temp->append_ics(*stmt);
	return *temp;
}

Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Divide_Ast::compile()
{
	Code_For_Ast c1 = lhs->compile();
	Code_For_Ast c2 = rhs->compile();
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

	Register_Descriptor* rd;
	Compute_IC_Stmt* stmt;
	Register_Addr_Opd * result;
	if(c1.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(div_d, opd1, opd2, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();	
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(divd, opd1, opd2, result);
	}

	c1.get_reg()->reset_register_occupied();
	c2.get_reg()->reset_register_occupied();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	Code_For_Ast* temp = new Code_For_Ast(l1, rd);
	temp->append_ics(*stmt);
	return *temp;
}

Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

template class Number_Ast<int>;
template class Number_Ast<double>;

template<class T>
Code_For_Ast & Number_Ast<T>::compile()
{

	Register_Descriptor* rd;
	Move_IC_Stmt * stmt;
	Register_Addr_Opd * result;
	if(node_data_type== int_data_type)
	{
		Const_Opd<int> * opd1 = new Const_Opd<int>(constant);
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Move_IC_Stmt(imm_load, opd1, result);
	}
	else if(node_data_type== double_data_type)
	{
		Const_Opd<double> * opd1 = new Const_Opd<double>(constant);
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Move_IC_Stmt(imm_load_d, opd1, result);
	}
	 
	Code_For_Ast* temp = new Code_For_Ast();
	temp->append_ics(*stmt);
	temp->set_reg(rd);
	return *temp;
}

template<class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & UMinus_Ast::compile()
{
	Code_For_Ast c1 = lhs->compile();
	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());

	Register_Descriptor* rd;
	Compute_IC_Stmt* stmt;
	Register_Addr_Opd * result;

	if(c1.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(uminus_d, opd1, NULL, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();
		result = new Register_Addr_Opd(rd);
		stmt = new Compute_IC_Stmt(uminus, opd1, NULL, result);
	}

	c1.get_reg()->reset_register_occupied();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	Code_For_Ast* temp = new Code_For_Ast(l1, rd);
	temp->append_ics(*stmt);
	return *temp;
}

Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}


Code_For_Ast & Conditional_Expression_Ast::compile()
{
	string label1 = get_new_label();
	Code_For_Ast c1 = cond->compile();

	

	if(c1.get_reg() == NULL || c1.get_reg()==machine_desc_object.spim_register_table[zero])
	{
		list<Icode_Stmt *> l1 = c1.get_icode_list();
		Control_Flow_IC_Stmt *stmt50;
		if(c1.get_reg() == NULL)
		{
		 	stmt50  = new Control_Flow_IC_Stmt(bc1t, NULL, NULL,label1);
		}
		else
		{
			stmt50 = new Control_Flow_IC_Stmt(bc1f, NULL, NULL,label1);
		}
		l1.push_back(stmt50);
		Code_For_Ast c2 = lhs->compile();

		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		

		Register_Addr_Opd* opd1_then = new Register_Addr_Opd(c2.get_reg());
		Move_IC_Stmt * stmt1;

		Register_Descriptor* rd;
		Register_Addr_Opd * result;
		if(c2.get_reg()->get_use_category() == float_reg)
		{
			rd = machine_desc_object.get_new_register<float_reg>();
			result = new Register_Addr_Opd(rd);
			stmt1 = new Move_IC_Stmt(move_d, opd1_then, result);
		}
		else
		{
			rd = machine_desc_object.get_new_register<int_reg>();	
			result = new Register_Addr_Opd(rd);
			stmt1 = new Move_IC_Stmt(mov, opd1_then, result);
		}

		l1.push_back(stmt1);

		string label2 = get_new_label();
		Control_Flow_IC_Stmt *stmt2 = new Control_Flow_IC_Stmt(j, NULL, NULL,label2);
		l1.push_back(stmt2);

		Label_IC_Stmt* stmt3 = new Label_IC_Stmt(label, label1);
		l1.push_back(stmt3);
		Code_For_Ast c3 = rhs->compile();
		list<Icode_Stmt *> l3 = c3.get_icode_list();
		l1.insert(l1.end(), l3.begin(), l3.end());

		Label_IC_Stmt* stmt4 = new Label_IC_Stmt(label, label2);
		l1.push_back(stmt4);

		if(c1.get_reg() != NULL && c1.get_reg()!=machine_desc_object.spim_register_table[zero])
			c1.get_reg()->reset_register_occupied();
		c2.get_reg()->reset_register_occupied();
		c3.get_reg()->reset_register_occupied();

		Code_For_Ast * temp = new Code_For_Ast(l1,rd);
		return *temp;
		
		
	}



	Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
	Control_Flow_IC_Stmt *stmt = new Control_Flow_IC_Stmt(beq, opd1, NULL, label1);

	  ////
	Code_For_Ast c2 = lhs->compile();

	list<Icode_Stmt *> l1 = c1.get_icode_list();
	l1.push_back(stmt);
	list<Icode_Stmt *> l2 = c2.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	
	Register_Addr_Opd* opd1_then = new Register_Addr_Opd(c2.get_reg());
	Register_Addr_Opd* opd2 = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	Compute_IC_Stmt * stmt1;

	Register_Descriptor* rd;
	Register_Addr_Opd * result;
	if(c2.get_reg()->get_use_category() == float_reg)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		result = new Register_Addr_Opd(rd);
		stmt1 = new Compute_IC_Stmt(or_t, opd1_then, opd2, result);
	}
	else
	{
		rd = machine_desc_object.get_new_register<int_reg>();	
		result = new Register_Addr_Opd(rd);
		stmt1 = new Compute_IC_Stmt(or_t, opd1_then, opd2, result);
	}
	  /////////////////

	rd->reset_register_occupied();
	
	string label2 = get_new_label();
	Control_Flow_IC_Stmt *stmt2 = new Control_Flow_IC_Stmt(j, NULL, NULL, label2);
	l1.push_back(stmt1);
	l1.push_back(stmt2);

	Label_IC_Stmt* stmt3 = new Label_IC_Stmt(label, label1);
	l1.push_back(stmt3);
	Code_For_Ast c3 = rhs->compile();
	list<Icode_Stmt *> l3 = c3.get_icode_list();
	l1.insert(l1.end(), l3.begin(), l3.end());

	Register_Addr_Opd* opd1_else = new Register_Addr_Opd(c3.get_reg());
	Register_Addr_Opd* opd2_else = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);
	Compute_IC_Stmt * stmt4 = new Compute_IC_Stmt(or_t, opd1_else, opd2_else, result);
	l1.push_back(stmt4);

	c1.get_reg()->reset_register_occupied();
	c2.get_reg()->reset_register_occupied();
	c3.get_reg()->reset_register_occupied();  /////////////////

	Label_IC_Stmt* stmt5 = new Label_IC_Stmt(label, label2);
	l1.push_back(stmt5);
	Code_For_Ast * temp = new Code_For_Ast(l1,rd);
	return *temp;

}

Code_For_Ast & Relational_Expr_Ast::compile()
{
	if(lhs_condition->get_data_type() == int_data_type)
	{
		Code_For_Ast c1 = lhs_condition->compile();
		Code_For_Ast c2 = rhs_condition->compile();
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
		Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

		Register_Descriptor* rd= machine_desc_object.get_new_register<int_reg>();	
		Register_Addr_Opd * result = new Register_Addr_Opd(rd);
		Compute_IC_Stmt* stmt;
		if(rel_op == less_equalto)
			stmt = new Compute_IC_Stmt(sle, opd1, opd2, result);
		else if(rel_op == less_than)
			stmt = new Compute_IC_Stmt(slt, opd1, opd2, result);
		else if(rel_op== greater_than)
			stmt  = new Compute_IC_Stmt(sgt, opd1, opd2, result);
		else if(rel_op == greater_equalto)
			stmt = new Compute_IC_Stmt(sge, opd1, opd2, result);
		else if(rel_op == equalto)
			stmt = new Compute_IC_Stmt(seq, opd1, opd2, result);
		else if(rel_op == not_equalto)
			stmt = new Compute_IC_Stmt(sne, opd1, opd2, result);
		
		c1.get_reg()->reset_register_occupied();
		c2.get_reg()->reset_register_occupied();

		list<Icode_Stmt *> l1 = c1.get_icode_list();
		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		Code_For_Ast* temp = new Code_For_Ast(l1, rd);
		temp->append_ics(*stmt);
		return *temp;
	}
	else
	{
		Code_For_Ast c1 = lhs_condition->compile();
		Code_For_Ast c2 = rhs_condition->compile();
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
		Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

		Compute_IC_Stmt* stmt;
		Register_Descriptor* temp1;

		if(rel_op == less_equalto)
		{
			stmt = new Compute_IC_Stmt(sle_d, opd1, opd2, NULL);
			temp1 = machine_desc_object.spim_register_table[zero];
		}
		else if(rel_op == less_than)
		{
			stmt = new Compute_IC_Stmt(slt_d, opd1, opd2, NULL);
			temp1 = machine_desc_object.spim_register_table[zero];
		}
		else if(rel_op== greater_than)
		{
			temp1=NULL;
			stmt  = new Compute_IC_Stmt(sgt_d, opd1, opd2, NULL);
		}
		else if(rel_op == greater_equalto)
		{
			temp1=NULL;
			stmt = new Compute_IC_Stmt(sge_d, opd1, opd2, NULL);
		}
		else if(rel_op == equalto)
		{
			temp1=machine_desc_object.spim_register_table[zero];
			stmt = new Compute_IC_Stmt(seq_d, opd1, opd2, NULL);
		}
		else if(rel_op == not_equalto)
		{
			temp1=NULL;
			stmt = new Compute_IC_Stmt(sne_d, opd1, opd2, NULL);
		}
		
		c1.get_reg()->reset_register_occupied();
		c2.get_reg()->reset_register_occupied();

		list<Icode_Stmt *> l1 = c1.get_icode_list();
		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		Code_For_Ast* temp = new Code_For_Ast(l1, temp1);
		temp->append_ics(*stmt);
		return *temp;
	}
	
}

Code_For_Ast & Logical_Expr_Ast::compile()
{
	if(bool_op != _logical_not)
	{
		Code_For_Ast c1 = lhs_op->compile();
		Code_For_Ast c2 = rhs_op->compile();
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
		Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

		Register_Descriptor* rd= machine_desc_object.get_new_register<int_reg>();	
		Register_Addr_Opd * result = new Register_Addr_Opd(rd);
		Compute_IC_Stmt* stmt;
		if(bool_op == _logical_and)
			stmt = new Compute_IC_Stmt(and_t, opd1, opd2, result);
		else if(bool_op == _logical_or)
			stmt = new Compute_IC_Stmt(or_t, opd1, opd2, result);
		
		
		c1.get_reg()->reset_register_occupied();
		c2.get_reg()->reset_register_occupied();

		list<Icode_Stmt *> l1 = c1.get_icode_list();
		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		Code_For_Ast* temp = new Code_For_Ast(l1, rd);
		temp->append_ics(*stmt);
		return *temp;
	}
	else
	{
		Register_Descriptor* rd= machine_desc_object.get_new_register<int_reg>();	
		Register_Addr_Opd * result = new Register_Addr_Opd(rd);
		Const_Opd<int> * opd1 = new Const_Opd<int>(1);
		Move_IC_Stmt* stmt1 = new Move_IC_Stmt(imm_load, opd1, result);

		Code_For_Ast c2 = rhs_op->compile();
		Register_Addr_Opd* opd2 = new Register_Addr_Opd(c2.get_reg());

		Register_Descriptor* rd1= machine_desc_object.get_new_register<int_reg>();	
		Register_Addr_Opd * result1 = new Register_Addr_Opd(rd1);
		Compute_IC_Stmt* stmt;
		stmt = new Compute_IC_Stmt(not_t, opd2, result, result1);
		
		c2.get_reg()->reset_register_occupied();
		rd->reset_register_occupied();

		list<Icode_Stmt *> l1;
		l1.push_back(stmt1);
		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		Code_For_Ast* temp = new Code_For_Ast(l1, rd1);
		temp->append_ics(*stmt);
		return *temp;
	}
	
}

Code_For_Ast & Selection_Statement_Ast::compile()
{
	Code_For_Ast c1 = cond->compile();

	if(c1.get_reg() != NULL && c1.get_reg()!=machine_desc_object.spim_register_table[zero])
	{
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(c1.get_reg());
		
		Code_For_Ast c2 = then_part->compile();
		string label1 = get_new_label();
		Control_Flow_IC_Stmt *stmt = new Control_Flow_IC_Stmt(beq, opd1, NULL,label1);

		list<Icode_Stmt *> l1 = c1.get_icode_list();
		l1.push_back(stmt);
		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		
		
		if(else_part == NULL)
		{
			c1.get_reg()->reset_register_occupied();
			Label_IC_Stmt* stmt1 = new Label_IC_Stmt(label, label1);
			l1.push_back(stmt1);
			Code_For_Ast * temp = new Code_For_Ast(l1,NULL);
			return *temp;
		}
		else
		{
			string label2 = get_new_label();
			Control_Flow_IC_Stmt *stmt1 = new Control_Flow_IC_Stmt(j, NULL, NULL,label2);
			l1.push_back(stmt1);

			Label_IC_Stmt* stmt2 = new Label_IC_Stmt(label, label1);
			l1.push_back(stmt2);
			Code_For_Ast c3 = else_part->compile();
			c1.get_reg()->reset_register_occupied();
			
			list<Icode_Stmt *> l3 = c3.get_icode_list();
			l1.insert(l1.end(), l3.begin(), l3.end());

			Label_IC_Stmt* stmt3 = new Label_IC_Stmt(label, label2);
			l1.push_back(stmt3);
			Code_For_Ast * temp = new Code_For_Ast(l1,NULL);
			return *temp;
		}
	}
	else
	{
		string label1 = get_new_label();
		list<Icode_Stmt *> l1 = c1.get_icode_list();
		Control_Flow_IC_Stmt *stmt50;
		if(c1.get_reg() == NULL)
		{
		 	stmt50  = new Control_Flow_IC_Stmt(bc1t, NULL, NULL,label1);
		}
		else
		{
			stmt50 = new Control_Flow_IC_Stmt(bc1f, NULL, NULL,label1);
		}
		l1.push_back(stmt50);
		Code_For_Ast c2 = then_part->compile();

		list<Icode_Stmt *> l2 = c2.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		
		if(else_part == NULL)
		{
			Label_IC_Stmt* stmt1 = new Label_IC_Stmt(label, label1);
			l1.push_back(stmt1);
			Code_For_Ast * temp = new Code_For_Ast(l1,NULL);
			return *temp;
		}
		else
		{
			string label2 = get_new_label();
			Control_Flow_IC_Stmt *stmt1 = new Control_Flow_IC_Stmt(j, NULL, NULL,label2);
			l1.push_back(stmt1);

			Label_IC_Stmt* stmt2 = new Label_IC_Stmt(label, label1);
			l1.push_back(stmt2);
			Code_For_Ast c3 = else_part->compile();
			list<Icode_Stmt *> l3 = c3.get_icode_list();
			l1.insert(l1.end(), l3.begin(), l3.end());

			Label_IC_Stmt* stmt3 = new Label_IC_Stmt(label, label2);
			l1.push_back(stmt3);
			Code_For_Ast * temp = new Code_For_Ast(l1,NULL);
			return *temp;
		}
	}
	
}

Code_For_Ast & Sequence_Ast::compile()
{
	list<Ast *>:: iterator itr =statement_list.begin();
	list<Icode_Stmt *> l1;
	while(itr!= statement_list.end())
	{
		Code_For_Ast c = (*itr)->compile();
		list<Icode_Stmt *> l2 = c.get_icode_list();
		l1.insert(l1.end(), l2.begin(), l2.end());
		itr++;
	}
	sa_icode_list = l1;
	Code_For_Ast* temp = new Code_For_Ast(l1, NULL);
	return *temp;
}

Code_For_Ast & Iteration_Statement_Ast::compile()
{
	list<Icode_Stmt *> l1;
	string label1 = get_new_label();
	string label2 = get_new_label();
	if(!is_do_form)
	{
		Control_Flow_IC_Stmt *stmt = new Control_Flow_IC_Stmt(j, NULL, NULL, label2);
		l1.push_back(stmt);
	}

	Label_IC_Stmt* stmt1 = new Label_IC_Stmt(label, label1);
	l1.push_back(stmt1);
	

	
	Code_For_Ast c2 = cond->compile();
	Code_For_Ast c1 = body->compile();

	Label_IC_Stmt* stmt2 = new Label_IC_Stmt(label, label2);

	list<Icode_Stmt *> l2 = c1.get_icode_list();
	l1.insert(l1.end(), l2.begin(), l2.end());
	l1.push_back(stmt2);
	list<Icode_Stmt *> l3 = c2.get_icode_list();
	l1.insert(l1.end(), l3.begin(), l3.end());
	
	if(c2.get_reg()!=NULL && c2.get_reg()!=machine_desc_object.spim_register_table[zero]){
		Register_Addr_Opd* opd1 = new Register_Addr_Opd(c2.get_reg());
		Control_Flow_IC_Stmt *stmt3 = new Control_Flow_IC_Stmt(bne, opd1, NULL, label1);
		l1.push_back(stmt3);
		c2.get_reg()->reset_register_occupied();
	}
	else{
		if(c2.get_reg()==NULL){
			Control_Flow_IC_Stmt* stmt3 = new Control_Flow_IC_Stmt(bc1t,NULL, NULL,label1);
			l1.push_back(stmt3);
		}
		else{
			Control_Flow_IC_Stmt* stmt3 = new Control_Flow_IC_Stmt(bc1f,NULL, NULL,label1);
			l1.push_back(stmt3);
		}
		
	}
	Code_For_Ast* temp = new Code_For_Ast(l1, NULL);
	return *temp;

}

Code_For_Ast & Return_Ast::compile(){
	// printf("hdbxjh\n");
	if(return_value==NULL){
		list<Icode_Stmt *> l1;
		Control_Flow_IC_Stmt *stmt1 = new Control_Flow_IC_Stmt(ret_inst, NULL, NULL, "epilogue_" + proc_name);
		l1.push_back(stmt1);
		Code_For_Ast* temp = new Code_For_Ast(l1,NULL);
		return *temp;
	}
	Code_For_Ast c1 = return_value->compile();
	list<Icode_Stmt *> l1 = c1.get_icode_list();
	Move_IC_Stmt* stmt;
	Register_Descriptor* rd;
	Register_Addr_Opd* res;
	if(c1.get_reg()->get_use_category() == float_reg){
		Register_Addr_Opd* opd = new Register_Addr_Opd(c1.get_reg());
		// machine_desc_object.spim_register_table[f0]->reset_register_occupied();
		rd = machine_desc_object.spim_register_table[f0];
		res = new Register_Addr_Opd(machine_desc_object.spim_register_table[f0]);
		stmt = new Move_IC_Stmt(move_d, opd, res);
	}
	else
	{
		Register_Addr_Opd* opd = new Register_Addr_Opd(c1.get_reg());
		// machine_desc_object.spim_register_table[v1]->reset_register_occupied();
		rd = machine_desc_object.spim_register_table[v1];
		res = new Register_Addr_Opd(machine_desc_object.spim_register_table[v1]);
		stmt = new Move_IC_Stmt(mov, opd, res);	
	}
	// printf("hdbxjh\n");
	l1.push_back(stmt);
	c1.get_reg()->reset_register_occupied();
	Control_Flow_IC_Stmt *stmt1 = new Control_Flow_IC_Stmt(ret_inst, NULL, NULL, "epilogue_" + proc_name);
	l1.push_back(stmt1);
	Code_For_Ast* temp = new Code_For_Ast(l1,rd);
	return *temp;
}
Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

Code_For_Ast & Call_Ast::compile(){
	list<Icode_Stmt*> l1;
	Symbol_Table param=program_object.get_procedure_prototype(procedure_name)->get_formal_param_list();
	list<Symbol_Table_Entry*> :: iterator itr1 = param.get_table().end();
	list<Ast *>:: iterator itr = actual_param_list.end();
	if(itr!=actual_param_list.begin()){
		do
		{
			itr--;
			itr1--;
			Code_For_Ast c1 = (*itr)->compile();
			list<Icode_Stmt *> l2 = c1.get_icode_list();
			l1.insert(l1.end(), l2.begin(), l2.end());
			if(c1.get_reg()->get_use_category() == int_reg)
			{
				Register_Addr_Opd* res = new Register_Addr_Opd(c1.get_reg());
				string temp_str=(*itr1)->get_variable_name();
				Symbol_Table_Entry* sym=new Symbol_Table_Entry(temp_str,(*itr1)->get_data_type(),(*itr1)->get_lineno(),sp_ref);
				sym->set_start_offset((*itr1)->get_start_offset()-param.get_size());
				Mem_Addr_Opd* mem = new Mem_Addr_Opd(*sym);
				Move_IC_Stmt* stmt = new Move_IC_Stmt(store, res, mem);
				l1.push_back(stmt);
			}
			else
			{
				Register_Addr_Opd* res = new Register_Addr_Opd(c1.get_reg());
				string temp_str=(*itr1)->get_variable_name();
				Symbol_Table_Entry* sym=new Symbol_Table_Entry(temp_str,(*itr1)->get_data_type(),(*itr1)->get_lineno(),sp_ref);
				sym->set_start_offset((*itr1)->get_start_offset()-param.get_size());
				Mem_Addr_Opd* mem = new Mem_Addr_Opd(*sym);
				Move_IC_Stmt* stmt = new Move_IC_Stmt(store_d, res, mem);
				l1.push_back(stmt);
			}
			c1.get_reg()->reset_register_occupied();
		}while(itr!= actual_param_list.begin());
	}

	Control_Flow_IC_Stmt* stmt1 = new Control_Flow_IC_Stmt(jal,NULL,NULL,procedure_name);
	l1.push_back(stmt1);
	Register_Descriptor* rd = NULL;
	if(program_object.get_procedure_prototype(procedure_name)->get_return_type() == int_data_type)
	{
		rd = machine_desc_object.get_new_register<int_reg>();
		Register_Addr_Opd* res = new Register_Addr_Opd(rd);
		Register_Addr_Opd* res2 = new Register_Addr_Opd(machine_desc_object.spim_register_table[v1]);
		Move_IC_Stmt* stmt2 = new Move_IC_Stmt(mov, res2, res);
		l1.push_back(stmt2);
		machine_desc_object.spim_register_table[v1]->reset_register_occupied();
	}
	else if(program_object.get_procedure_prototype(procedure_name)->get_return_type() == double_data_type)
	{
		rd = machine_desc_object.get_new_register<float_reg>();
		Register_Addr_Opd* res = new Register_Addr_Opd(rd);
		Register_Addr_Opd* res2 = new Register_Addr_Opd(machine_desc_object.spim_register_table[f0]);
		Move_IC_Stmt* stmt2 = new Move_IC_Stmt(move_d, res2, res);
		l1.push_back(stmt2);
		machine_desc_object.spim_register_table[f0]->reset_register_occupied();
	}
	if(return_value_reg==NULL && rd!=NULL){
		rd->reset_register_occupied();
	}
	Code_For_Ast* temp = new Code_For_Ast(l1,rd);
	return *temp;
}

Code_For_Ast & Call_Ast::compile_and_optimize_ast(Lra_Outcome & lra){}

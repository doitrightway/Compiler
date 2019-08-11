int Eval_Result::get_int_value()
{
	return 1;
}

void Eval_Result::set_value(int value)
{
	return;
}

double Eval_Result::get_double_value()
{
	return 1.0;
}

void Eval_Result::set_value(double value)
{
	return;
}

bool Eval_Result::is_variable_defined()
{
	return false;
}

void Eval_Result::set_variable_status(bool def)
{
	return;
}


int Eval_Result_Value::get_int_value()
{
	return 1;
}

void Eval_Result_Value::set_value(int value)
{
	return;
}

double Eval_Result_Value::get_double_value()
{
	return 1.0;
}

void Eval_Result_Value::set_value(double value)
{
	return;
}

Eval_Result_Value_Int::Eval_Result_Value_Int()
{
	value=0;
	defined = false;
}

Eval_Result_Value_Int::~Eval_Result_Value_Int()
{

}

void Eval_Result_Value_Int::set_value(int number)
{
	value = number;
}

void Eval_Result_Value_Int::set_value(double number)
{
	value = (int)number;
}

int Eval_Result_Value_Int::get_int_value()
{
	return value;
}

void Eval_Result_Value_Int::set_variable_status(bool def)
{
	defined = def;
}

bool Eval_Result_Value_Int::is_variable_defined()
{
	return defined;
}

void Eval_Result_Value_Int::set_result_enum(Result_Enum res)
{
	result_type = res;
}
Result_Enum Eval_Result_Value_Int::get_result_enum()
{
	return result_type;
}


Eval_Result_Value_Double::Eval_Result_Value_Double()
{
	value=0;
	defined = false;
}

Eval_Result_Value_Double::~Eval_Result_Value_Double()
{

}

void Eval_Result_Value_Double::set_value(double number)
{
	value = number;
}

void Eval_Result_Value_Double::set_value(int number)
{
	value = (double)number;
}

double Eval_Result_Value_Double::get_double_value()
{
	return value;
}

void Eval_Result_Value_Double::set_variable_status(bool def)
{
	defined = def;
}

bool Eval_Result_Value_Double::is_variable_defined()
{
	return defined;
}

void Eval_Result_Value_Double::set_result_enum(Result_Enum res)
{
	result_type = res;
}
Result_Enum Eval_Result_Value_Double::get_result_enum()
{
	return result_type;
}


Local_Environment::Local_Environment()
{

}
Local_Environment::~Local_Environment()
{

}

void Local_Environment::print(ostream & file_buffer)
{
	map<string, Eval_Result *>::iterator it;
	// printf("ninin\n");
	for(it=variable_table.begin();it!=variable_table.end();it++){
		// printf("ygy%s\n",(*it).first);
		// printf("innn\n");
		// cout<<(*it).first;
		// const char *cstr = (*it).first.c_str();
		file_buffer<<VAR_SPACE<<(*it).first.c_str()<<" : ";
		// printf("bbubub\n");
		// if(it->second==NULL)
		// Eval_Result* tt=(*it).second;
		// 	printf("Edee\n");
		// file_buffer<<tt->is_variable_defined();
		if(it->second->is_variable_defined()){
			// printf("tyye\n");
			switch((*it).second->get_result_enum()){
				case int_result: file_buffer<<it->second->get_int_value();break;
				case double_result: file_buffer<<it->second->get_double_value();break;
			}
		}
		else{
			file_buffer<<"undefined";
		}
		file_buffer<<"\n";
	}
}
bool Local_Environment::is_variable_defined(string name)
{
	if(!does_variable_exist(name))
		return false;
	else
		return variable_table[name]->is_variable_defined();
}
Eval_Result * Local_Environment::get_variable_value(string name)
{
	return variable_table[name];
}
void Local_Environment::put_variable_value(Eval_Result & value, string name)
{
	if(value.get_result_enum()==int_result){
		variable_table[name] = new Eval_Result_Value_Int();
		variable_table[name]->set_value(value.get_int_value());
	}
	else{
		variable_table[name] = new Eval_Result_Value_Double();
		variable_table[name]->set_value(value.get_double_value());
	}
	variable_table[name]->set_result_enum(value.get_result_enum());
	variable_table[name]->set_variable_status(value.is_variable_defined());
	// printf("%shhhhh%d\n",name.c_str(),variable_table[name]->is_variable_defined() );
}

bool Local_Environment::does_variable_exist(string name)
{
	if(variable_table.find(name) == variable_table.end())
		return false;
	return true;
}

void Symbol_Table::create(Local_Environment & local_global_variables_table){
	list<Symbol_Table_Entry *>::iterator it;
	for(it=variable_table.begin();it!=variable_table.end();it++){
		// printf("hhj\n");
		if((*it)->get_data_type()==int_data_type){
			Eval_Result_Value_Int temp;
			temp.set_result_enum(int_result);
			if(scope==global){
				temp.set_value(0);
				temp.set_variable_status(1);
			}
			else{
				temp.set_variable_status(0);
			}
			// cout<<(*it)->get_variable_name()<<"sss\n";
			local_global_variables_table.put_variable_value(temp,(*it)->get_variable_name());
			// printf("%d\n", temp.is_variable_defined());
		}
		else if((*it)->get_data_type()==double_data_type){
			Eval_Result_Value_Double temp;
			temp.set_result_enum(double_result);
			if(scope==global){
				temp.set_value(0);
				temp.set_variable_status(1);
			}
			else{
				temp.set_variable_status(0);
			}
			local_global_variables_table.put_variable_value(temp,(*it)->get_variable_name());
		}
		// printf("hh\n");
	}
}
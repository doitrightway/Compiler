#define ICODE_SUB_SPACE "    	"
#define ICODE_SPACE "	"


Instruction_Descriptor::Instruction_Descriptor(Tgt_Op op, string name, string mnn, string ics, Icode_Format icf, Assembly_Format af)
{
	inst_op = op;
	mnemonic = mnn;
	ic_symbol = name;    /* symbol for printing in intermediate code */
	this->name = ics;
	ic_format = icf; /* format for printing in intemediate code */
	assem_format = af;
}
Instruction_Descriptor::Instruction_Descriptor(){}

Tgt_Op Instruction_Descriptor::get_op()
{
	return inst_op;
}

string Instruction_Descriptor::get_name()
{
	return name;
}
string Instruction_Descriptor::get_mnemonic(){
	return mnemonic;
}
string Instruction_Descriptor::get_ic_symbol(){
	return ic_symbol;
}
Icode_Format Instruction_Descriptor::get_ic_format(){
	return ic_format;
}
Assembly_Format Instruction_Descriptor::get_assembly_format(){
	return assem_format;
}

void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer){
	
}

Register_Descriptor * Ics_Opd::get_reg(){
	return NULL;
}

Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se){
	symbol_entry = &se;
}

void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<symbol_entry->get_variable_name();
}
void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer){
	if((symbol_entry->get_symbol_scope() == local || symbol_entry->get_symbol_scope() == formal) && symbol_entry->get_ref_offset() == fp_ref)
	{
		file_buffer<<symbol_entry->get_start_offset()<<"($fp)";
	}
	else if(symbol_entry->get_ref_offset() == sp_ref)
	{
		file_buffer<<symbol_entry->get_start_offset()<<"($sp)";
	}
	else
	{
		file_buffer<<symbol_entry->get_variable_name();
	}
}

Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs){
	symbol_entry = rhs.symbol_entry;
}


Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd){
	register_description = rd;
}

Register_Descriptor * Register_Addr_Opd::get_reg(){
	return register_description;
}
void Register_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream & file_buffer){
	file_buffer<<"$"<<register_description->get_name();
}

Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd & rhs){
	register_description = rhs.register_description;
}

template class Const_Opd<int>;
template class Const_Opd<double>;

template <class T>
Const_Opd<T>::Const_Opd(T num){
	this->num = num;
}

template <class T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer){
	file_buffer<<num;
}
template <class T>
void Const_Opd<T>::print_asm_opd(ostream & file_buffer){
	file_buffer<<num;
}
template <class T>
Const_Opd<T> & Const_Opd<T>::operator=(const Const_Opd<T> & rhs){
	num = rhs.num;
}	

Instruction_Descriptor & Icode_Stmt::get_op(){}
Ics_Opd * Icode_Stmt::get_opd1(){}
Ics_Opd * Icode_Stmt::get_opd2(){}
Ics_Opd * Icode_Stmt::get_result(){}
void Icode_Stmt::set_opd1(Ics_Opd * io){}
void Icode_Stmt::set_opd2(Ics_Opd * io){}
void Icode_Stmt::set_result(Ics_Opd * io){}

Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * result)
{
	op_desc = *machine_desc_object.spim_instruction_table[inst_op];
	this->opd1 = opd1;
	this->result = result;
}

Move_IC_Stmt & Move_IC_Stmt::operator=(const Move_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	result = rhs.result;
}

Instruction_Descriptor & Move_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Move_IC_Stmt::get_opd1(){
	return opd1;
}
void Move_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}
Ics_Opd * Move_IC_Stmt::get_result(){
	return result;
}
void Move_IC_Stmt::set_result(Ics_Opd * io){
	result= io;
}
void Move_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<":"<<ICODE_SUB_SPACE;
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<"\n";
}
void Move_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_assembly_format() == a_op_r_o1)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
	else if(op_desc.get_assembly_format() == a_op_o1_r)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		result->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
}	

Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, Ics_Opd * result)
{
	op_desc = *machine_desc_object.spim_instruction_table[inst_op];
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->result = result;
} 
Compute_IC_Stmt & Compute_IC_Stmt::operator=(const Compute_IC_Stmt & rhs)
{
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	opd2 = rhs.opd2;
	result = rhs.result;
}

Instruction_Descriptor & Compute_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Compute_IC_Stmt::get_opd1(){
	return  opd1;
}
void Compute_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1  = io;
}

Ics_Opd * Compute_IC_Stmt::get_opd2(){
	return opd2;
}
void Compute_IC_Stmt::set_opd2(Ics_Opd * io){
	opd2 = io;
}
Ics_Opd * Compute_IC_Stmt::get_result(){
	return result;
}
void Compute_IC_Stmt::set_result(Ics_Opd * io){
	result  = io;
}
void Compute_IC_Stmt::print_icode(ostream & file_buffer){
	if(op_desc.get_ic_format() == i_r_op_o1)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<":"<<ICODE_SUB_SPACE;
		result->print_ics_opd(file_buffer);
		file_buffer<<" <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer<<"\n";
	}
	else if(op_desc.get_ic_format() == i_r_o1_op_o2)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<":"<<ICODE_SUB_SPACE;
		result->print_ics_opd(file_buffer);
		file_buffer<<" <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer<<" , ";
		opd2->print_ics_opd(file_buffer);
		file_buffer<<"\n";
	}
	else if(op_desc.get_ic_format() == i_o1_op_o2)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<":"<<ICODE_SUB_SPACE;
		opd1->print_ics_opd(file_buffer);
		file_buffer<<" , ";
		opd2->print_ics_opd(file_buffer);
		file_buffer<<"\n";
	}
}
void Compute_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_assembly_format() == a_op_r_o1)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
	else if(op_desc.get_assembly_format() == a_op_r_o1_o2)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd2->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
	else if(op_desc.get_assembly_format() == a_op_o1_o2)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd2->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
}


Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, string label, int size){
	op_desc = *machine_desc_object.spim_instruction_table[inst_op];
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->offset = label;
	this->actual_param_size = size;
}

Control_Flow_IC_Stmt & Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	opd2 = rhs.opd2;
	offset = rhs.offset;
	actual_param_size = rhs.actual_param_size;
}

Instruction_Descriptor & Control_Flow_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}

Ics_Opd * Control_Flow_IC_Stmt::get_opd1(){
	return opd1;
}
void Control_Flow_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}

Ics_Opd * Control_Flow_IC_Stmt::get_opd2(){
	return opd2;
}

void Control_Flow_IC_Stmt::set_opd2(Ics_Opd * io){
	opd2 = io;
}


string Control_Flow_IC_Stmt::get_Offset(){
	return offset;
}
void Control_Flow_IC_Stmt::set_Offset(string label){
	this->offset = label;
}

void Control_Flow_IC_Stmt::print_icode(ostream & file_buffer){
	if(op_desc.get_ic_format() == i_op_o1_o2_st)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<":"<<ICODE_SUB_SPACE;
		opd1->print_ics_opd(file_buffer);
		file_buffer<<" , zero : goto "<<offset<<"\n";
	}
	else if(op_desc.get_op() == j &&  op_desc.get_ic_format() == i_op_st)
	{
		file_buffer<<ICODE_SPACE<<"goto "<<offset<<"\n";
	}
	else if(op_desc.get_op() == jal)
	{
		file_buffer<<ICODE_SPACE<<"call "<<offset<<"\n";
	}
	else if(op_desc.get_ic_format() == i_op)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<"\n";
	}
	else if(op_desc.get_ic_format() == i_op_st)
	{
		file_buffer<<ICODE_SPACE<<op_desc.get_ic_symbol()<<" "<<offset<<"\n";
	}
}
void Control_Flow_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_assembly_format() == a_op_o1_o2_st){
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", $zero, "<<offset<<"\n";
	}
	else if(op_desc.get_op() == jal){
		Symbol_Table param=program_object.get_procedure_prototype(offset)->get_formal_param_list();
		if(param.get_size()-param.get_start_offset_of_first_symbol()!=0){
			file_buffer<<ICODE_SPACE<<"sub $sp, $sp, "<<param.get_size()-param.get_start_offset_of_first_symbol()<<"\n";
			file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" "<<offset<<"\n";
			file_buffer<<ICODE_SPACE<<"add $sp, $sp, "<<param.get_size()-param.get_start_offset_of_first_symbol()<<"\n";
		}
		else{
			file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" "<<offset<<"\n";
		}
	}
	else if(op_desc.get_assembly_format() == a_op_st){
		file_buffer<<ICODE_SPACE<<op_desc.get_mnemonic()<<" "<<offset<<"\n";
	}
	else if(op_desc.get_assembly_format() == a_op){
		file_buffer<<ICODE_SPACE<<"j "<<offset<<"\n";
	}
}

Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst_op, string label){
	op_desc = *machine_desc_object.spim_instruction_table[inst_op];
	this->label = label;
}
Label_IC_Stmt & Label_IC_Stmt::operator=(const Label_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	label = rhs.label;
}

Instruction_Descriptor & Label_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}
string Label_IC_Stmt::get_label(){
	return label;
}
void Label_IC_Stmt::set_label(string label){
	this->label = label;
}
void Label_IC_Stmt::print_icode(ostream & file_buffer){
	if(op_desc.get_ic_format() == i_op_st)
	{
		file_buffer<<"\n"<<label<<":\n";
	}
}
void Label_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_assembly_format() == a_op_st){
		file_buffer<<"\n"<<label<<":\n";
	}
}


Print_IC_Stmt::Print_IC_Stmt(){}
Print_IC_Stmt::~Print_IC_Stmt(){}
void Print_IC_Stmt::print_icode(ostream & file_buffer){file_buffer<<ICODE_SPACE<<"print\n";}
void Print_IC_Stmt::print_assembly(ostream & file_buffer){file_buffer<<ICODE_SPACE<<"syscall\n";}

Code_For_Ast::Code_For_Ast(){

}
Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> & ic_l, Register_Descriptor * reg){
	ics_list = ic_l;
	result_register = reg;
}
void Code_For_Ast::Code_For_Ast::append_ics(Icode_Stmt & ics){
	ics_list.push_back(&ics);
}
list<Icode_Stmt *> & Code_For_Ast::get_icode_list(){
	return ics_list;
}
Register_Descriptor * Code_For_Ast::get_reg(){
	return result_register;
}
void Code_For_Ast::set_reg(Register_Descriptor * reg){
	result_register = reg;
}
Code_For_Ast & Code_For_Ast::operator=(const Code_For_Ast & rhs){
	ics_list = rhs.ics_list;
	result_register = rhs.result_register;
}	



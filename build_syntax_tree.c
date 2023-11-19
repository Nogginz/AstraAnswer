#include <stdio.h>
#include <setjmp.h>
#include "sillypare.h"
#include "hardcore_northcutt.h"

int get_lexem_list_len(list_type lst);
cmd_link build_syntax_tree(list_type lst,int start_index,int end_index);
list_type create_lexem_list(status *program_status);
void print_lexem_list(list_type lst);
int check_bracket_balance(list_type lst);

int main(int argc,char *argv[]){
	
	
		
		char *str;
		
		status program_status = Success;
		
		cmd_link tree_root = NULL;
	
	
		list_type lexem_list = create_lexem_list(&program_status);
		
		int brackets_balanced= check_bracket_balance(lexem_list);
		if (brackets_balanced == -1){
			return 0;
		}
		int lexem_list_len = get_lexem_list_len(lexem_list);
		tree_root = build_syntax_tree(lexem_list,0,lexem_list_len-1);
		
	
	return 0;
	
}


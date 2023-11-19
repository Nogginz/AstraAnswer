#include <stdio.h>
#include <setjmp.h>
#include "sillypare.h"
#include "hardcore_northcutt.h"

list_type get_lexem_list(status *program_status);

void print_lexem_list(list_type lst);

int get_lexem_list_len(list_type lst);

cmd_link build_syntax_tree(list_type lst,int start_index,int end_index);

void print_syntax_tree(cmd_link cmd_tree_root,int shift);

void rm_syntax_tree(cmd_link tree);

void run_tree(cmd_link tree);

int main(int argc,char *argv[]){

	list_type lexem_list = NULL;
	status program_status = Success;
	lexem_list = get_lexem_list(&program_status);

	return 0;
}

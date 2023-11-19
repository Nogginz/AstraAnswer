#include <stdio.h>
#include "sillypare.h"
#include "hardcore_northcutt.h"

list_type get_lexem_list(status *program_status);

int main(int argc,char *argv[]){

	list_type lexem_list = NULL;
	status program_status = Success;
	lexem_list = get_lexem_list(&program_status);

	return 0;
}

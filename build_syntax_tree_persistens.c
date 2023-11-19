#include <stdio.h>
#include <setjmp.h>
#include "sillypare.h"
#include "hardcore_northcutt.h"


//void print_lexem_list(list_type lst);
int get_lexem_list_len(list_type lst);
cmd_link build_syntax_tree(list_type lst,int start_index,int end_index);
void print_syntax_tree(cmd_link cmd_tree_root,int shift);
void rm_syntax_tree(cmd_link tree);
void run_tree(cmd_link tree);
list_type create_lexem_list(status *program_status, char str[]);
void print_lexem_list(list_type lst);

int check_bracket_balance(list_type lst);

char* concat(char *s1, char *s2) {

        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      

        char *result = malloc(len1 + len2 + 1);

        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }

        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    

        return result;
    }

typedef enum { Start, Word, Pairable_sym} vertex;

__AFL_FUZZ_INIT();

int main(int argc,char *argv[]){
	
	#ifdef __AFL_HAVE_MANUAL_CONTROL
  		__AFL_INIT();
	#endif
	while (__AFL_LOOP(1000)) {
		unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;
		char *endl = "\n";
		char *str = concat(buf, endl);
		
		
		status program_status = Success;
		
		cmd_link tree_root = NULL;
	
	
		list_type lexem_list = create_lexem_list(&program_status, str);
		free(str);
		int brackets_balanced= check_bracket_balance(lexem_list);
		int lexem_list_len = get_lexem_list_len(lexem_list);
		tree_root = build_syntax_tree(lexem_list,0,lexem_list_len-1);
	}
	
       
	
	return 0;
	
}


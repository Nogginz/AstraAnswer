CC=afl-clang-fast
HARNESSES=get_lexem_list.out build_syntax_tree.out build_syntax_tree_persistens.out
FLAGS=-g3 -fsanitize=address
run:
	make build
	./trusty_reflection.out

build: clever_williams.o kirch.o print_kirch.o trusty_reflection.o bhaskara.o
	$(CC) -O0 -g -Wall -o trusty_reflection.out trusty_reflection.o bhaskara.o kirch.o print_kirch.o clever_williams.o
	rm *.o

clever_williams.o: clever_williams.c
	$(CC) -O0 -g -Wall -c -o clever_williams.o clever_williams.c

kirch.o: kirch.c
	$(CC) -O0 -g -Wall -c -o kirch.o kirch.c

print_kirch.o: print_kirch.c
	$(CC) -O0 -g -Wall -c -o print_kirch.o print_kirch.c

trusty_reflection.o: trusty_reflection.c
	$(CC) -O0 -g -Wall -c -o trusty_reflection.o trusty_reflection.c

bhaskara.o: bhaskara.c
	$(CC) -O0 -g -Wall -c -o bhaskara.o bhaskara.c

harnesses: $(HARNESSES)
	rm *.o
	
	
clever_williams_harness.o: clever_williams_harness.c
	$(CC) -O0 -g -Wall -c -o clever_williams_harness.o clever_williams_harness.c
	
get_lexem_list.out: get_lexem_list.o clever_williams.o kirch.o print_kirch.o bhaskara.o
	$(CC) $(FLAGS) -o harnesses/$@ bhaskara.o kirch.o print_kirch.o clever_williams.o $<
	
get_lexem_list.o: get_lexem_list.c
	$(CC) $(FLAGS) -c -o $@ $<


build_syntax_tree.out: build_syntax_tree.o clever_williams.o kirch.o print_kirch.o bhaskara.o
	$(CC) $(FLAGS) -o harnesses/$@ bhaskara.o kirch.o print_kirch.o clever_williams.o $<
	
build_syntax_tree.o: build_syntax_tree.c
	$(CC) $(FLAGS) -c -o $@ $<

build_syntax_tree_persistens.out: build_syntax_tree_persistens.o clever_williams_harness.o kirch.o print_kirch.o bhaskara.o
	$(CC) $(FLAGS) -o harnesses/$@ bhaskara.o kirch.o print_kirch.o clever_williams_harness.o $<
	
build_syntax_tree_persistens.o: build_syntax_tree_persistens.c
	$(CC) $(FLAGS) -c -o $@ $<


clean:
	rm *.o
	rm *.out


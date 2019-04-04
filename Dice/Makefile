all: die_test clear

die_test: die_test.o die.o 
	gcc die_test.o die.o -g -o die_test

die_test.o: die_test.c die.h die.c types.h
	gcc -Wall -ansi -pedantic -g -c die_test.c 

die.o: die.c die.h types.h
	gcc -Wall -ansi -pedantic -g -c die.c

clear:
	rm -f *.o
clean:
	rm -f *.o die_test

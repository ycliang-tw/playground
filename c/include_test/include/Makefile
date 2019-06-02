CC = gcc

all:	test.c include.h include.c
	$(CC) -c test.c -o test.o
	$(CC) -c include.c -o include.o
	$(CC) -o test test.o include.o	
	# will cause error when linking (double definition of 'a')
	# but if declare as "static" can resolve this problem

clean:
	rm -rf *.o test

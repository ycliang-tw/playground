```
gcc hello.c -o hello:
	cpp [option] hello.c -o hello.i 	/ gcc -E hello.c -o hello.i			(preprocess)
	cc1 [option] hello.i -o hello.(s/S)	/ gcc -S hello.c -o hello.S			(compile)
	as  [option] hello.S -o hello.o		/ gcc -c hello.(s/c/S) -o hello.o	(assemble)
	ld  [option] hello.o -o hello	(linking)
```

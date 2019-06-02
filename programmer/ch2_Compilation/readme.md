```
gcc hello.c -o hello:
	cpp [option] hello.c -o hello.i 	/ gcc -E hello.c -o hello.i		(preprocess)	cpp: preprocessor
	cc1 [option] hello.i -o hello.(s/S)	/ gcc -S hello.c -o hello.S		(compile)	cc1: compiler proper
	as  [option] hello.S -o hello.o		/ gcc -c hello.(s/c/S) -o hello.o	(assemble)	as: assembler
	ld  [option] hello.o -o hello	(linking)	ld: dynamic linker/loader
```

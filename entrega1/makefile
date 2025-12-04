all: clean flex compile
compile: flex lex.yy.c
	gcc -lfl lex.yy.c
flex: scanner.l
	flex scanner.l
clean:
	rm -f lex.yy.c
	rm -f a.out


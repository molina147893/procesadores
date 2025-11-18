all: clean compile
compile: flex bison lex parser.tab.c lex.yy.o
	gcc parser.tab.c lex.yy.o -lfl -lm
flex: scanner.l
	flex scanner.l
bison: parser.y
	bison -v -d -t parser.y  
lex: lex.yy.c
	gcc -c lex.yy.c  
clean:
	rm -f lex.yy.c
	rm -f a.out
	rm -f parser.tab.c
	rm -f lex.yy.o

all: clean compile

compile: flex bison lex tablaSimbolos traducciones cuadruplas
	gcc parser.tab.c lex.yy.o tablaSimbolos.o traducciones.o cuadruplas.o -lfl -lm

flex: scanner.l
	flex scanner.l

bison: parser.y
	bison -v -d -t parser.y

lex: lex.yy.c
	gcc -c lex.yy.c

tablaSimbolos:
	gcc -c tablaSimbolos.c

traducciones:
	gcc -c traducciones.c
	
cuadruplas:
	gcc -c cuadruplas.c

clean:
	rm -f lex.yy.c lex.yy.o
	rm -f a.out
	rm -f parser.tab.c parser.tab.h
	rm -f parser.output
	rm -f tablaSimbolos.o
	rm -f traducciones.o
	rm -f cuadruplas.o


AUTORES:
 - Iván Latasa Sancha
 - Alejandro Molina Puyuelo
 GRUPO 2 DE PRÁCTICAS
 
  - USO DEL MAKEFILE:
 $ make all
	rm -f lex.yy.c
	rm -f a.out
	flex scanner.l
	gcc -lfl lex.yy.c
	
 $ make clean
	rm -f lex.yy.c
	rm -f a.out
	

 - EJECUCION:
 $ ./a.out
 
 - DETENER EJECUCION:
 CTRL + D

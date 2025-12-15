algoritmo pruebaError;
ent a, d, c: entero; 
sal r: real; 
{Prec: a = A AND d = D AND c = C}
	var
		t: entero;
		f: caracter;
		bt, bp: booleano;
		cad, cod: cadena;
	fvar;
	bt := bp;
	f := a + a;
	t := a / d;
	c := r;
	r := a mod d;

	si a >= d y a <> c ->
		r := r + r
	[] a < d y d <> c ->
		r := r - r
	[] c > a ->
		continuar
	fsi
{Post: a=A AND d = D AND c= C ...}
falgoritmo.


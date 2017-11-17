program numeros;

uses crt;

var
	num1, num2, suma:integer;
	cociente:real;
	caracter:char;
	
begin
	clrscr;
	writeln('Digita num1: ');
	read(num1);
	writeln('Digita num2: ');
	read(num2);
	writeln(' ');
	suma:=num1+num2;
	cociente:=num1/num2;
	caracter:='t';
	writeln(suma);
	writeln(cociente:1:1);
	writeln(caracter);
end.

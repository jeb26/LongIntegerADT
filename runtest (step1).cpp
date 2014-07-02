#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include "implementation.cpp"
using namespace std;

int main(int agrc, char  **argv)
{
	string a1("2222");
	string b1("99999999");
	string c1("246813575732");
	string d1("180270361023456789");
	string ax1("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	string az1("-98534342983742987342987339234098230498203894209928374662342342342356723423423");

	//INIT THE LONG INTEGERS
	LongInt *a = new LongInt(); //= new LongInt();
	a->initialize(a1);
	LongInt *b = new LongInt();
	b->initialize(b1);
	LongInt *c = new LongInt();
	c->initialize(c1);
	LongInt *d = new LongInt();
	d->initialize(d1);
	LongInt *ax = new LongInt();
	ax->initialize(ax1);
	LongInt *az = new LongInt();
	az->initialize(az1);

	//PRINT THE LONG INTEGERS
	cout << "PRINT THE LONG INTEGERS USING PRINT()" << endl;
	a->print();
	b->print();
	c->print();
	d->print();
	ax->print();
	az->print();

	cout << endl;

	//PRINT THE RESULTS OF COMPARING THE LONG INTEGERS TO EACH OTHER WITH LESS THAN
	cout << "COMPARISON OF LONG INTEGERS WITH LESSTHAN()" << endl;
	
	//COMPARISON OF A
	cout << "a less than b: " << a->lessthan(b) << endl;
	cout << "a less than c: " << a->lessthan(c) << endl;
	cout << "a less than d: " << a->lessthan(d) << endl;
	cout << "a less than ax: " << a->lessthan(ax) << endl;
	cout << "a less than az: " << a->lessthan(az) << endl << endl;
	
	//COMPARISON OF B
	cout << "b less than a: " << b->lessthan(a) << endl;
	cout << "b less than c: " << b->lessthan(c) << endl;
	cout << "b less than d: " << b->lessthan(d) << endl;
	cout << "b less than ax: " << b->lessthan(ax) << endl;
	cout << "b less than az: " << b->lessthan(az) << endl << endl;

	//COMPARISON OF C
	cout << "c less than a: " << c->lessthan(a) << endl;
	cout << "c less than b: " << c->lessthan(b) << endl;
	cout << "c less than d: " << c->lessthan(d) << endl;
	cout << "c less than ax: " << c->lessthan(ax) << endl;
	cout << "c less than az: " << c->lessthan(az) << endl << endl;
	
	//COMPARISON OF D
	cout << "d less than a: " << d->lessthan(a) << endl;
	cout << "d less than b: " << d->lessthan(b) << endl;
	cout << "d less than c: " << d->lessthan(c) << endl;
	cout << "d less than ax: " << d->lessthan(ax) << endl;
	cout << "d less than az: " << d->lessthan(az) << endl << endl;
	
	//COMPARISON OF AX
	cout << "ax less than a: " << ax->lessthan(a) << endl;
	cout << "ax less than b: " << ax->lessthan(b) << endl;
	cout << "ax less than c: " << ax->lessthan(c) << endl;
	cout << "ax less than d: " << ax->lessthan(d) << endl;
	cout << "ax less than az: " << ax->lessthan(az) << endl << endl;

	//COMPARISON OF AZ
	cout << "az less than a: " << az->lessthan(a) << endl;
	cout << "az less than b: " << az->lessthan(b) << endl;
	cout << "az less than c: " << az->lessthan(c) << endl;
	cout << "az less than d: " << az->lessthan(d) << endl;
	cout << "az less than ax: " << az->lessthan(ax) << endl << endl;

	//PRINT THE RESULTS OF COMPARING THE LONG INTEGERS TO EACH OTHER WITH GREATER THAN

	//COMPARISON OF A
	cout << "COMPARISON OF LONG INTEGERS WITH GREATERTHAN()" << endl;
	cout << "a greater than b: " << a->greaterthan(b) << endl;
	cout << "a greater than c: " << a->greaterthan(c) << endl;
	cout << "a greater than d: " << a->greaterthan(d) << endl;
	cout << "a greater than ax: " << a->greaterthan(ax) << endl;
	cout << "a greater than az: " << a->greaterthan(az) << endl << endl;

	//COMPARISON OF B
	cout << "b greater than a: " << b->greaterthan(a) << endl;
	cout << "b greater than c: " << b->greaterthan(c) << endl;
	cout << "b greater than d: " << b->greaterthan(d) << endl;
	cout << "b greater than ax: " << b->greaterthan(ax) << endl;
	cout << "b greater than az: " << b->greaterthan(az) << endl << endl;

	//COMPARISON OF C
	cout << "c greater than a: " << c->greaterthan(a) << endl;
	cout << "c greater than b: " << c->greaterthan(b) << endl;
	cout << "c greater than d: " << c->greaterthan(d) << endl;
	cout << "c greater than ax: " << c->greaterthan(ax) << endl;
	cout << "c greater than az: " << c->greaterthan(az) << endl << endl;

	//COMPARISON OF D
	cout << "d greater than a: " << d->greaterthan(a) << endl;
	cout << "d greater than c: " << d->greaterthan(c) << endl;
	cout << "d greater than b: " << d->greaterthan(b) << endl;
	cout << "d greater than ax: " << d->greaterthan(ax) << endl;
	cout << "d greater than az: " << d->greaterthan(az) << endl << endl;

	//COMPARISON OF AX
	cout << "ax greater than a: " << ax->greaterthan(a) << endl;
	cout << "ax greater than c: " << ax->greaterthan(c) << endl;
	cout << "ax greater than d: " << ax->greaterthan(d) << endl;
	cout << "ax greater than b: " << ax->greaterthan(b) << endl;
	cout << "ax greater than az: " << ax->greaterthan(az) << endl << endl;

	//COMPARISON OF AZ
	cout << "az greater than a: " << az->greaterthan(a) << endl;
	cout << "az greater than c: " << az->greaterthan(c) << endl;
	cout << "az greater than d: " << az->greaterthan(d) << endl;
	cout << "az greater than b: " << az->greaterthan(b) << endl;
	cout << "az greater than ax: " << az->greaterthan(ax) << endl << endl;
	
	//PRINT THE RESULTS OF COMPARING THE LONG INTEGERS TO EACH OTHER WITH EQUALTO

	cout << "COMPARISON OF LONG INTEGERS WITH EQUALTO()" << endl;

	//LONG INTEGER A COMPARED TO THE OTHERS

	cout << "a equal to a: " << a->equalto(a) << endl;
	cout << "a equal to b: " << a->equalto(b) << endl;
	cout << "a equal to c: " << a->equalto(c) << endl;
	cout << "a equal to d: " << a->equalto(d) << endl;
	cout << "a equal to ax: " << a->equalto(ax) << endl;
	cout << "a equal to az: " << a->equalto(az) << endl << endl;

	//LONG INTEGER B COMPARED TO THE OTHERS

	cout << "b equal to b: " << b->equalto(b) << endl;
	cout << "b equal to a: " << b->equalto(a) << endl;
	cout << "b equal to c: " << b->equalto(c) << endl;
	cout << "b equal to d: " << b->equalto(d) << endl;
	cout << "b equal to ax: " << b->equalto(ax) << endl;
	cout << "b equal to az: " << b->equalto(az) << endl << endl;

	//LONG INTEGER C COMPARED TO THE OTHERS

	cout << "c equal to c: " << c->equalto(c) << endl;
	cout << "c equal to a: " << c->equalto(a) << endl;
	cout << "c equal to b: " << c->equalto(b) << endl;
	cout << "c equal to d: " << c->equalto(d) << endl;
	cout << "c equal to ax: " << c->equalto(ax) << endl;
	cout << "c equal to az: " << c->equalto(az) << endl << endl;

	//LONG INTEGER D COMPARED TO THE OTHERS

	cout << "d equal to d: " << d->equalto(d) << endl;
	cout << "d equal to a: " << d->equalto(a) << endl;
	cout << "d equal to b: " << d->equalto(b) << endl;
	cout << "d equal to c: " << d->equalto(c) << endl;
	cout << "d equal to ax: " << d->equalto(ax) << endl;
	cout << "d equal to az: " << d->equalto(az) << endl << endl;

	//LONG INTEGER AX COMPARED TO THE OTHERS

	cout << "ax equal to ax: " << ax->equalto(ax) << endl;
	cout << "ax equal to a: " << ax->equalto(a) << endl;
	cout << "ax equal to b: " << ax->equalto(b) << endl;
	cout << "ax equal to c: " << ax->equalto(c) << endl;
	cout << "ax equal to d: " << ax->equalto(d) << endl;
	cout << "ax equal to az: " << ax->equalto(az) << endl << endl;

	//LONG INTEGER AZ COMPARED TO THE OTHERS

	cout << "az equal to az: " << az->equalto(az) << endl;
	cout << "az equal to a: " << az->equalto(a) << endl;
	cout << "az equal to b: " << az->equalto(b) << endl;
	cout << "az equal to c: " << az->equalto(c) << endl;
	cout << "az equal to d: " << az->equalto(d) << endl;
	cout << "az equal to ax: " << az->equalto(ax) << endl << endl;

	//PRINT THE NUMBER OF DIGITS IN THE LONG INTEGERS
	cout << "PRINT THE NUMBER OF DIGITS IN THE LONG INTEGERS USING GETDIGITCOUNT()" << endl;
	cout << "a: " << a->getdigitcount() << endl;
	cout << "b: " << b->getdigitcount() << endl;
	cout << "c: " << c->getdigitcount() << endl;
	cout << "d: " << d->getdigitcount() << endl;
	cout << "ax: " << ax->getdigitcount() << endl;
	cout << "az: " << az->getdigitcount() << endl;

	//PRINT THE OVERFLOW OF B AS AN INTEGER
	cout << endl << "PRINT THE OVERFLOW OF B AS AN INTEGER USING OVERFLOW()" << endl;
	int _b = 99999999;
	int overflow = a->over_flow(_b);
	cout << overflow << endl;	

	//FREE THE MEMORY HELD THE LONG INTEGERS
	free(a); free(b); free(c); free(d); free(ax); free(az);

	return 0;
}
#pragma once
#include "Multime.h"

typedef int TElem;

class IteratorMultime
{
	friend class Multime;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMultime(const Multime&m);

	//contine o referinta catre containerul pe care il itereaza
	const Multime& mult;

	/* aici e reprezentarea  specifica a iteratorului */
	int* act;
	int poz;


public:

	//reseteaza pozitia iteratorului la inceputul containerului
	 //Teta(1) CF=CM=CD=CT
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	 //Teta(1) CF=CM=CD=CT
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	 //Teta(1) CF=CM=CD=CT
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	 //Teta(1) CF=CM=CD=CT
	TElem element() const;
};


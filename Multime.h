#pragma once
typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorMultime;

class Multime {

	friend class IteratorMultime;

private:
	/* aici e reprezentarea */
	int max_size;
	/* aici e reprezentarea */
	int* array;
	int used;

public:
	//constructorul implicit
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	// Teta(1)  CF - i == n + nu e nevoie de redimensionare
	//Teta(n)  CD - i==0 + e nevoie de redimensionare
	//Teta(n)  CM
	//O(n)  CT
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	//Teta(1)  CF - i==n
	//Teta(n)  CD - i==0
	//Teta(n)  CM
	//O(n)  CT
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	//Teta(1)  CF - i==1
	//Teta(n)  CD - i==n
	//Teta(n)  CM
	//O(n)  CT
	bool cauta(TElem elem) const;


	//intoarce numarul de elemente din multime;
	//Teta(1) CF=CD=CM=CT
	int dim() const;

	//Teta(1) CF=CD=CM=CT
	TElem * get_arr() const;

	//Teta(1) CF=CD=CM=CT
	int get_used() const;


	//verifica daca multimea e vida;
	//Teta(1) CF=CD=CM=CT
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	~Multime();

};
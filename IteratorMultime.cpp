#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : mult(m) {
	this->act = m.array;
	this->poz = 0;
	/* de adaugat */
}

TElem IteratorMultime::element() const {
	/* de adaugat */
	return *this->act;
}

bool IteratorMultime::valid() const {
	/* de adaugat */
	if (this->poz < mult.get_used()) {
		return true;
	}
	return false;
}

void IteratorMultime::urmator() {
	/* de adaugat */
	this->act += 1;
	this->poz += 1;
}

void IteratorMultime::prim() {
	/* de adaugat */
	this->act = mult.get_arr();
	this->poz = 0;
}
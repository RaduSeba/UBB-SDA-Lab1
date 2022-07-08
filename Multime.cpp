#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

Multime::Multime() {
	/* de adaugat */
	if (5 <= 0) {
		throw exception();
	}
	this->array = new int[5];
	this->used = 0;
	this->max_size = 5;
}


bool Multime::adauga(TElem elem) {
	
	if (this->used == this->max_size) {
		this->max_size *= 2;
		TElem* temp = new int[this->max_size];
		for (int i = 0; i < this->max_size / 2; i++) {
			temp[i] = this->array[i];
		}
		delete[] this->array;
		this->array = temp;
	}
	for (int i = 0; i < this->used;i++ ) {
		if (this->array[i] == elem)
		{
			return false;
		}
		if (rel(elem,this->array[i]) == true)
		{
			for (int index = this->used; index >i; --index) {
				this->array[index] = this->array[index - 1];
			}
			this->array[i] = elem;
			this->used += 1;
			return true;
		}
	}
	this->array[this->used] = elem;
	this->used += 1;
	return true;

}
bool Multime::sterge(TElem elem) {
	for (int i = 0; i < this->used; i++)
	{
		if (elem == this->array[i])
		{

			for (int index = i; index < this->used - 1; ++index) {
				this->array[index] = this->array[index + 1];
			}
			this->used -= 1;
			return true;
		}
	}
	return false;
}


bool Multime::cauta(TElem elem) const {
	for (int i = 0; i < this->used; i++)
	{
		if (elem == this->array[i])
			return true;
	}
	return false;
}


int Multime::dim() const {
	/* de adaugat */
	return this->used;
}

TElem* Multime::get_arr() const {
	return this->array;
}

int Multime::get_used() const {
	return this->used;
}


bool Multime::vida() const {
	if (this->used == 0)
	{
		return true;
	}
	return false;
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


Multime::~Multime() {
	delete[] this->array;
	/* de adaugat */
}
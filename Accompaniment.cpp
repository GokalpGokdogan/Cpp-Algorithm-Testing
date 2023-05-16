#include "Accompaniment.h"

Accompaniment::Accompaniment(string s, Snack* s0, Snack* s1)
{
	this->name = s;
	this->snack0 = s0;
	this->snack1 = s1;
}
Accompaniment::Accompaniment()
{
	this->name = "";
	this->snack0 = nullptr;
	this->snack1 = nullptr;
}

Accompaniment::Accompaniment(const Accompaniment& a)
{
	this->name = a.name;
	this->snack0 = a.snack0;
	this->snack1 = a.snack1;
}

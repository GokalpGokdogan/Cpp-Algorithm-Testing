#include "Snack.h"
#include <iostream>
#include <string>
using namespace std;

void Snack::addAccompanied(Snack& s)
{
	accompanied.push_back(s);

}

void Snack::printAccompanied()
{
	for (int i = accompanied.size()-1; i >= 0; i--)
	{
		cout << accompanied[i].name << " ";
	}
	cout << endl;
}

Snack::Snack(string s)
{
	this->name = s;
}

Snack::Snack()
{
	this->name = "";
}

Snack::Snack(const Snack& s)
{
	this->name = s.name;
	for (int i = 0; i < s.accompanied.size(); i++)
	{
		accompanied.push_back(s.accompanied[i]);

	}

}

Snack::~Snack()
{
	name = "";
	accompanied.~vector();
}

Snack* Snack::findSnack(string s)
{
	for (int i = 0; i < accompanied.size(); i++)
	{
		if (accompanied[i].name == s) {
			return &accompanied[i];
		}
	}
	
	return nullptr;
}

void Snack::eraseAccompanied(string s)
{
	for (auto i = accompanied.begin(); i < accompanied.end(); i++)
	{
		if (i->name == s) {
			accompanied.erase(i);
			return;
		}
	}

}
bool Snack::operator==(const Snack& other) const {
	return name == other.name;
}

void Snack::operator=(const Snack& other) {
	name = other.name;
	for (int i = 0; i < other.accompanied.size(); i++)
	{
		accompanied.push_back(other.accompanied[i]);
	}
}
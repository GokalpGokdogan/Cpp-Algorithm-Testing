#pragma once
#include "Snack.h"
#include <list>
class SnackHashing
{
private:

	list<Snack> arr[11];

	
public:

	SnackHashing();/// table size is 11 in this assignment


	/// this will only give  hash code, it is advised to use mod <table_size> when needed
	//int toHash(Snack s);


	void add(Snack s);
	void erase(string s);
	Snack* find(string s);
	int strToHash(string s);
};


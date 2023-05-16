#pragma once
#include "Snack.h"
#include <list>
#include "Accompaniment.h"
class AccompanimentHashing
{
private:

	Accompaniment arr[71];


public:

	AccompanimentHashing();/// table size is 71 in this assignment


	/// this will only give  hash code, it is advised to use mod <table_size> when needed
	int toHash(Accompaniment s);


	void add(Accompaniment s);
	void erase(string s1,string s2);
	bool isFull();
	bool isThere(string s1,string s2);
	int strToHash(string s);

};


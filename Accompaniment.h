#pragma once
#include <string>
#include "Snack.h"
using namespace std;
class Accompaniment
{

public:
	string name;
	Snack* snack0, *snack1;

	Accompaniment(string s, Snack* s0, Snack* s1);
	Accompaniment();
	Accompaniment(const Accompaniment& a);


private:
	//string name

};


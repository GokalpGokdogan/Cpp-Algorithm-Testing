#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class City
{
public:
	string name;
	vector< City > destination;

	City(string na);
	void addDest(City ccc);
	void deleteDest(City ccc);

};


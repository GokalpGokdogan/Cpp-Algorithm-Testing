#include "City.h"

City::City(string na)
{
	name = na;
}

void City::addDest(City ccc)
{
	destination.push_back(ccc);
}

void City::deleteDest(City ccc)
{
	vector<City> temp;
	for (int i = 0; i < destination.size();i++ ) {
		if (ccc.name == destination[i].name) {
			continue;
		}
		temp.push_back(destination[i]);
	}
	destination = temp;
}

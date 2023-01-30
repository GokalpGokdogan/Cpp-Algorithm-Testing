#pragma once
//#include "City.h"
#include <string>
using namespace std;

/// <summary>
/// Mustafa Gokalp Gokdogan
/// Section: 3
/// 22102936
/// </summary>


class Flight
{
public:
	string to;
	string from;
	int id;
	int cost;
	mutable int state; /// default: 0, ended: -1, success: 1

	Flight(int, int, string, string);

	void changeState(int) const;

};


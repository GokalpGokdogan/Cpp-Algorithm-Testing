#include "Flight.h"

/// <summary>
/// Mustafa Gokalp Gokdogan
/// Section: 3
/// 22102936
/// </summary>
 

Flight::Flight(int id, int cost, string from, string to)
{
	this->id = id;
	this->cost = cost;
	this->from = from;
	this->to = to;
	this->state = 0;
}

void Flight::changeState(int s) const
{
	this->state = s;
}


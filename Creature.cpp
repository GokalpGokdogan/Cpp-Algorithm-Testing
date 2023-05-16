#include "Creature.h"

Creature::Creature(int idin, int healthin, double xin, double yin)
{
	this->id = idin;
	this->x = xin;
	this->y = yin;
	this->health = healthin;
}


void Creature::setX(double n)
{
	this->x = n;
}

double Creature::getX()
{
	return x;
}

void Creature::setY(double n)
{
	y = n;
}

double Creature::getY()
{
	return y;
}

int Creature::getId()
{
	return id;
}

int Creature::getHealth()
{
	return health;
}

void Creature::setHealth(int n)
{
	health = n;
}
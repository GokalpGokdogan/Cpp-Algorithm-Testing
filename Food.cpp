#include "Food.h"
#include <random>
#include <ctime>

using namespace std;

Food::Food(int idin, double xin, double yin, int Quality, int spawnin)
{
	this->id = idin;
	this->x = xin;
	this->y = yin;
	this->quality = Quality;
	this->spawn = spawnin;
}

void Food::setX(double n)
{
	this->x = n;
}

double Food::getX()
{
	return x;
}

void Food::setY(double n)
{
	y = n;
}

double Food::getY()
{
	return y;
}

int Food::getId()
{
	return id;
}

int Food::getSpawn()
{
	return spawn;
}

int Food::getQuality()
{
	return quality;
}

#pragma once
class Food
{
public:
	;
	Food(int idin, double xin, double yin, int Quality, int spawnin);

	void setX(double n);
	double getX();
	void setY(double n);
	double getY();
	
	int getId();
	int getSpawn();
	int getQuality();

private:
	double x;
	double y;
	int id;
	int quality;
	int spawn;
};
#pragma once
class Creature
{
public:
	
	Creature(int idin, int healthin, double xin, double yin);

	void setX(double n);
	double getX();
	void setY(double n);
	double getY();

	int getId();
	int getHealth();
	void setHealth(int n);

private:
	int id;
	int health;
	double x;
	double y;
};


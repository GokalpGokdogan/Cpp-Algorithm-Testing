#include "MovLinkedList.h"
#include "Subscriber.h"
#include "Movie.h"
#include <iostream>
using namespace std;

Subscriber::Subscriber(int id)
{
	this->id = id;
}

void Subscriber::rent(Movie m)
{
	rentedMovies.add(m);
	pastMovies.add(m);
}

void Subscriber::returnMov(Movie m)
{
	rentedMovies.remove(m);
	
	
	pastMovies.giveMov(m)->copies=0;
	
	
}

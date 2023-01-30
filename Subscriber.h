#pragma once
#include "MovLinkedList.h"
#include "Movie.h"
#include <iostream>
using namespace std;

class Subscriber
{
public:
	MovLinkedList rentedMovies;

	MovLinkedList pastMovies;


	int id;

	Subscriber(int id=-1);
	

	void rent(Movie m);
	void returnMov(Movie m);

	
	
};


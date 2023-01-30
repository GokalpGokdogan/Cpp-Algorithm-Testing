#pragma once
#include<iostream>
#include "MovNode.h"
#include "Movie.h"
using namespace std;
class MovLinkedList
{
private:
	//MovNode* head;
	

public:
	//bool output = 0;
	MovNode* head;
	MovLinkedList();
	~MovLinkedList();
	void add(Movie item);
	int size();
	void remove(Movie item);
	void display() const;
	bool isAvailable(Movie m);
	void updateCop(Movie m, int no);
	bool doesExist(Movie m) const;

	Movie* giveMov(Movie s) const;

};


#pragma once
#include<iostream>
#include "SubNode.h"
#include "Subscriber.h"
using namespace std;
class SubLinkedList
{
private:
	
public:
	SubNode* head;

	SubLinkedList();
	~SubLinkedList();
	void add(Subscriber item);
	int size();
	void remove(Subscriber item);
	void display() const;
	bool doesExist(Subscriber s) const;
	Subscriber* giveSub(Subscriber s) const;
};
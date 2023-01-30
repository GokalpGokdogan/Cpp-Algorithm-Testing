#pragma once
#include "Subscriber.h"
class SubNode
{
public:
	SubNode();
	~SubNode();

	Subscriber data;
	SubNode* next;
};


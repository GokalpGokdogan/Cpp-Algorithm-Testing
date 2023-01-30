#pragma once
#include "Movie.h"
class MovNode
{
public:
	MovNode();
	~MovNode();

	Movie data;
	MovNode* next;
};


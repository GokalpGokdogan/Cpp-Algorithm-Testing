#include "MovNode.h"
#include <iostream>
using namespace std;

MovNode::MovNode() {
	this->next = NULL;
	//this->data = nullptr;
}

MovNode::~MovNode()
{
	
	if (next != nullptr) {
		delete next;
	}
	next = nullptr;
}

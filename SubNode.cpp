#include "SubNode.h"
using namespace std;

SubNode::SubNode() {
	this->next = nullptr;
	//this->data = nullptr;
}

SubNode::~SubNode()
{
	if (next != nullptr) {
		delete next;
	}
	next = nullptr;
}

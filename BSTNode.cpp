#include "BSTNode.h"
#include <iostream>
using namespace std;

BSTNode::BSTNode(BSTNode& node)
{
	this->val = node.val;
	this->left = node.left;
	this->right = node.right;
}

int BSTNode::getVal()
{
	return val;
}

BSTNode* BSTNode::getLeft()
{
	return left;
}

BSTNode* BSTNode::getRight()
{
	return right;
}

BSTNode::~BSTNode()
{

	if (this->left != nullptr) {
		delete this->left;
	}
	if (this->right != nullptr) {
		delete this->right;
	}
	
	//cout << "lol" << endl;
}


BSTNode& BSTNode::operator=( const BSTNode& node){
	this->val = node.val;
	this->left = node.left;
	this->right = node.right;

	return *this;

}

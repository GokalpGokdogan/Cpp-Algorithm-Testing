#pragma once
#include "BSTNode.h"
#include <vector>
using namespace std;

class BST
{
public:
	int size;
	BSTNode* root;
	BSTNode* searchBST(BSTNode* root, int val);
	BSTNode* searchBST(int val);
	BSTNode* leftist(BSTNode* root);
	BSTNode* findPrev(BSTNode* root, BSTNode* leftist);
	vector<int> inorderTraversal(BSTNode* root) const;
//public:
	void insertItem(int key); 
	void deleteItem(int key);
	int* inorderTraversal(int& length) const;
	bool hasSequence(int* seq, int length);
	BSTNode* insertItem(BSTNode* current,int key);
	void printInorder() const;
	~BST();
	BST& operator=(const BST& Node);
	BST(const BST& old);
	BST();
	vector<int> preorderTraversal(BSTNode* root)const;
	int* preorderTraversal(int& length) const;
	void printPreorder() const;
	void deleteNode(BSTNode*& del);
	void processLeftmost(BSTNode*& nodePtr, int& treeItem);
};


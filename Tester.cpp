#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
#include <iostream>
#include <chrono>
#include "BST.h"
#include "BSTNode.h"	
#include "analysis.h"
using namespace std;


BST* merge(const BST& tree1, const BST& tree2);



int main() {

	//BST test;
	//test.insertItem(8);
	//test.insertItem(4);
	//test.insertItem(13);
	//test.insertItem(3);
	//test.insertItem(6);
	//test.insertItem(12);
	//test.insertItem(15);
	//test.insertItem(1);
	//test.insertItem(2);
	//test.insertItem(5);
	//test.insertItem(10);
	//test.insertItem(14);

	//test.deleteItem(15);
	//cout << "---------------First Inorder------------------\n";
	//test.printInorder();
	///////
	//BST test1;
	//test1.insertItem(31);
	//test1.insertItem(23);
	//test1.insertItem(85);
	//test1.insertItem(110);
	//test1.insertItem(135);
	//test1.insertItem(21);
	//test1.insertItem(20);
	//
	//cout << "---------------Second Inorder------------------\n";
	//test1.printInorder();

	//BST* test2 = merge(test,test1);


	//cout << "---------------Merged Inorder------------------\n";
	//test2->printInorder();
	


	//##################################################


	//test();
	timeAnalysis();

	return 0;
}

BST* merge(const BST& tree1, const BST& tree2)
{
	BST* ans = new BST(tree1);
	//int size1;
	int size2;
	//int* arr1 = tree1.inorderTraversal(size1);
	int* arr2 = tree2.inorderTraversal(size2);
	/*
	for (int i = 0; i < size1; i++)
	{
		ans->insertItem(arr1[i]);
	}*/
	//ans->printInorder();
	for (int i = 0; i < size2; i++)
	{
		ans->insertItem(arr2[i]);
	}
	//cout << "------------\n";
	//ans->printInorder();
	return ans;
}

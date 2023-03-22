#pragma once
#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
#include "analysis.h"
#include "BST.h"
#include "BSTNode.h"
#include <random>
#include <ctime>
#include <iostream>
//#define CLOCKS_PER_SEC 1000
#define CLOCKS_PER_SEC  ((clock_t)1000)
using namespace std;

void timeAnalysis() {
	const int SIZE = 15000;
	srand(time(NULL));
	int* arr = new int[SIZE];
	BST* tree = new BST();
	cout << "Part e - Time analysis of Binary Search Tree - part 1\n" <<
		"-----------------------------------------------------------\n" <<
		"Tree Size		Time Elapsed\n" <<
		"-----------------------------------------------------------\n";

	for (int j = 0; j < SIZE; j++)
	{

		arr[j] = j;
	}

	for (int i = 0; i < SIZE; i++) {
		int j = rand() % SIZE;
		swap(arr[i], arr[j]);

	}
	for (int i = 0; i < 10; i++)
	{
		/*for (int j = 0; j < 1500; j++)
		{
			
			arr[i * 1500 + j] = rand() % 30000;
		}*/


		clock_t start = clock();
		for (int j = 0; j < 1500; j++)
		{
			tree->insertItem(arr[i * 1500 + j]);

		}
		clock_t end = clock();

		double time = double(end - start) / (CLOCKS_PER_SEC / 1000);

		cout << (i + 1) * 1500 << "				" << time << "ms\n";

	}
	for (int i = 0; i < SIZE; i++) {
		int j = rand() % SIZE;
		swap(arr[i], arr[j]);

	}
	cout << "Part e - Time analysis of Binary Search Tree - part 2\n" <<
		"-----------------------------------------------------------\n" <<
		"Tree Size		Time Elapsed\n" <<
		"-----------------------------------------------------------\n";

	//BSTNode* x = tree->searchBST(14369);
	//BSTNode* x1 = tree->findPrev(tree->root, x);
	for (int i = 0; i < 10; i++)
	{
		

		clock_t start = clock();
		for (int j = 0; j < 1500; j++)
		{
			//if (arr[i * 1500 + j] == 14661) {
				//tree->searchBST(141);
			//	cout << "";
			//}
			//tree->searchBST(141);


			//cout << i * 1500 + j <<":" << arr[i * 1500 + j] << endl;
			tree->deleteItem(arr[i * 1500 + j]);
			
		}
		clock_t end = clock();

		double time = double(end - start) / (CLOCKS_PER_SEC / 1000);

		cout << SIZE-(i + 1) * 1500 << "				" << time << "ms\n";

	}


}
void test() {
	
		const int SIZE = 10;
		//srand(time(NULL));
		int* arr = new int[SIZE];
		BST* tree = new BST();
		cout << "Part e - Time analysis of Binary Search Tree - part 1\n" <<
			"-----------------------------------------------------------\n" <<
			"Tree Size		Time Elapsed\n" <<
			"-----------------------------------------------------------\n";


		
			for (int j = 0; j < 10; j++)
			{

				arr[j] = j;//rand() % 200;
				/*if (arr[j == 129]) {
					cout << "a";
				}*/
			}

			for (int i = 0; i < SIZE; i++) {
				int j = rand() % SIZE;
				swap(arr[i], arr[j]);

			}
			clock_t start = clock();
			for (int j = 0; j < 10; j++)
			{
				tree->insertItem(arr[ j]);

			}
			clock_t end = clock();

			double time = double(end - start) / (CLOCKS_PER_SEC / 1000);

			cout <<  "		" << time << "ms\n";

		
		for (int i = 0; i < SIZE; i++) {
			int j = rand() % SIZE;
			swap(arr[i], arr[j]);

		}
		cout << "Part e - Time analysis of Binary Search Tree - part 2\n" <<
			"-----------------------------------------------------------\n" <<
			"Tree Size		Time Elapsed\n" <<
			"-----------------------------------------------------------\n";

		//BSTNode* x = tree->searchBST(14369);
		//BSTNode* x1 = tree->findPrev(tree->root, x);
		



			 start = clock();
			for (int j = 0; j < 10; j++)
			{
				//int size11;
				//int size22;
				tree->printInorder();
				//cout << arr[j] << ", ";
				//BSTNode* x = tree->searchBST(14369);
				/*if (arr[i * 1500 + j] == 14369) {
					cout << endl;
				}*/
				cout << "-----------\n";
				tree->deleteItem(arr[ j]);
				//tree->preorderTraversal(size22);
				//int diff = size11 - size22;

			}
			 end = clock();

			 time = double(end - start) / (CLOCKS_PER_SEC / 1000);

			cout << SIZE  << "		" << time << "ms\n";

		


	

}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

}
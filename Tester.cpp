#pragma comment(linker, "/STACK:2000000")
#include <iostream>
#include <chrono>
#include "sorting.h"
using namespace std;





int main() {

	cout << "----------Random Array------------------" << endl;

	double duration;
	int size = 1000;
	int* arr0 = new int[size];
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	int* arr4 = new int[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 1000;
		arr0[i] = n;
		arr1[i] = n;
		arr2[i] = n;
		arr3[i] = n;
		arr4[i] = n;

	}

	cout << "Array Size: " << size << endl;
	int compCount = 0;
	int moveCount = 0;
	clock_t startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	size = 5000;
	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 1000;
		arr0[i] = n;
		arr1[i] = n;
		arr2[i] = n;
		arr3[i] = n;
		arr4[i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;


	size = 10000;

	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 1000;
		arr0[i] = n;
		arr1[i] = n;
		arr2[i] = n;
		arr3[i] = n;
		arr4[i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;


	size = 20000;

	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];
	for (int i = 0; i < size; i++)
	{
		int n = rand() % 1000;
		arr0[i] = n;
		arr1[i] = n;
		arr2[i] = n;
		arr3[i] = n;
		arr4[i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	

	//////////////////////////////////////////////////////////////////

	cout << "----------Partialy Ascending Array------------------" << endl;

	size = 1000;
	int limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	int x;
	int last;
	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = limit + i * limit;
			int n = rand() % x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = rand() % x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	size = 5000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = limit + i * limit;
			int n = rand() % x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = rand() % x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	size = 10000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = limit + i * limit;
			int n = rand() % x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = rand() % x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	size = 20000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	
	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = limit + i * limit;
			int n = rand() % x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = rand() % x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;




	cout << "----------Partialy Descending Array------------------" << endl;

	size = 1000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = size - i * limit;
			int n = 0 - rand() % limit + x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = 0 - rand() % limit + x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;


	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;



	size = 5000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = size - i * limit;
			int n = 0 - rand() % limit + x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = 0 - rand() % limit + x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;


	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;



	size = 10000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = size - i * limit;
			int n = 0 - rand() % limit + x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = 0 - rand() % limit + x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;

	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;



	size = 20000;
	limit = log2(size);


	arr0 = new int[size];
	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size / limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			x = size - i * limit;
			int n = 0 - rand() % limit + x;
			arr0[i * limit + j] = n;
			arr1[i * limit + j] = n;
			arr2[i * limit + j] = n;
			arr3[i * limit + j] = n;
			arr4[i * limit + j] = n;
			last = i * limit + j;

		}


	}

	for (int i = 0; i < size % limit; i++) {
		int n = 0 - rand() % limit + x;
		arr0[last + i] = n;
		arr1[last + i] = n;
		arr2[last + i] = n;
		arr3[last + i] = n;
		arr4[last + i] = n;


	}

	cout << "Array Size: " << size << endl;
	compCount = 0;
	moveCount = 0;
	startTime = clock();
	insertionSort(arr0, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Insertion Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	bubleSort(arr1, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Bubble Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	mergeSort(arr2, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Merge Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	quickSort(arr3, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Quick Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	startTime = clock();
	hybridSort(arr4, size, compCount, moveCount);
	duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << "Hybrid Sort:	Comparison) " << compCount << " Move) " << moveCount << " Time) " << duration;
	compCount = 0;
	moveCount = 0;
	cout << endl;

	delete[] arr0;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;





	return 0;
}

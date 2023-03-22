#include "sorting.h"
#pragma comment(linker, "/STACK:2000000")
#include <iostream>
#include <chrono>
using namespace std;




void insertionSort(int* arr, int size, int& compCount, int& moveCount)
{
	
	for (int i = 1; i < size; i++) {
		compCount++;
		if (arr[i] < arr[i - 1]) {
			for (int j = i ; j >= 1; j--) {
				compCount++;
				if (arr[j] < arr[j - 1]) {
					swap(arr[j], arr[j - 1]);
					moveCount++;
				}
				else {
					break;
				}
			}
		}
	}

	

}

void bubleSort(int* arr, int size, int& compCount, int& moveCount)
{
	bool check = 0;

	do {
		check = 0;

		for (int i = 1; i < size; i++) {
			compCount++;
			if (arr[i - 1] > arr[i]) {
				moveCount++;
				swap(arr[i], arr[i - 1]);
				check++;
			}
		}

	} while (check);
}

void mergeSort(int* arr, int size, int& compCount, int& moveCount)
{
	if (size == 1) {
		return;
	}
	mergeSort(arr, size / 2, compCount, moveCount);
	mergeSort(arr+size/2, size-size / 2, compCount, moveCount);
	
	int* temp = merge(arr, arr + size / 2, size / 2, size - size / 2, compCount,moveCount);
	for (int i = 0; i < size; i++)
	{	
		moveCount++;
		swap(arr[i], temp[i]);

	}
	
}

int* merge(  int* arr1, int* arr2, int size1, int size2, int& compCount, int& moveCount)
{	
	int* arr = new int[size1 + size2];
	int index = 0;
	int j = 0;
	for (int i = 0; i < size1; i++) {

		compCount++;
		if (arr1[i] > arr2[j]) {
			arr[index] = arr2[j];
			j++;
			i--;
			
		}
		else {
			arr[index] = arr1[i];

		}
		if (size2 == j) {
			index++;
			for (int k=index; k < size1 + size2; k++) {
				i++;
				arr[k] = arr1[i];
				
			}
			
			break;
		}
		

		index++;
	}

	if (size2 > j) {
		for (int k = index; k < size1 + size2; k++) {
			arr[k] = arr2[j];
			j++;
		}
	}
	return arr;

		
	
}

void hybridSort(int* arr, int size, int& compCount, int& moveCount)
{
	if (size <= 20) {
		bubleSort( arr, size, compCount, moveCount);
	}
	else {
		int index = partition(arr, size, compCount, moveCount);
		hybridSort(arr, index - 1, compCount, moveCount);
		hybridSort(arr + index + 1, size - index - 1, compCount, moveCount);
	}

}

void quickSort(int* arr, int size, int& compCount, int& moveCount)
{
	if (size <= 1) {
		return;
	}
	int index = partition(arr, size, compCount, moveCount);
	quickSort(arr, index-1, compCount, moveCount);
	quickSort(arr + index+1,size-index-1, compCount, moveCount);

}
//
//void swap(int& x, int& y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}

int partition(int* arr, int size, int& compCount, int& moveCount) {
	int pivot = arr[size - 1];
	int* small = arr;
	for (int i = 0; i < size - 1; i++)
	{
		compCount++;
		if (arr[i] < pivot) {
			moveCount++;
			swap(*small, arr[i]);
			small++;
		}
	}
	moveCount++;
	swap(*(small), arr[size - 1]);
	return small - arr + 1;
}
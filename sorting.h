#pragma once


	void insertionSort(int* arr, int size, int& compCount, int& moveCount);

	void bubleSort(int* arr, int size, int& compCount, int& moveCount);

	void mergeSort(int* arr, int size, int& compCount, int& moveCount);

	int* merge(int* arr1, int* arr2, int size1, int size2, int& compCount, int& moveCount);

	void hybridSort(int* arr, int size, int& compCount, int& moveCount);

	void quickSort(int* arr, int size, int& compCount, int& moveCount);

	int partition(int* arr, int size, int& compCount, int& moveCount);

	void swap(int& x, int& y);




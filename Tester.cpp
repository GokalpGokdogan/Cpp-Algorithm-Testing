#include <iostream>
#include <chrono>
using namespace std;


void insertionSort(int* arr, int size, int& compCount, int& moveCount);

void bubleSort(int* arr, int size, int& compCount, int& moveCount);

void mergeSort(int* arr, int size, int& compCount, int& moveCount);

int* merge(int* arr1, int* arr2, int size1, int size2, int& compCount, int& moveCount);

void hybridSort(int* arr, int size, int& compCount, int& moveCount);

void quickSort(int* arr, int size, int& compCount, int& moveCount);

int partition(int* arr, int size, int& compCount, int& moveCount);

void swap(int& x, int& y);


int main() {

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




	/*
	int const size = 60;
	int compCount = 0;
	int moveCount = 0;
	
	int arr[size] ;
	for (int i = 0; i < size; i++) {
		arr[i]= rand()%100;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}
	cout<<"\nNew:\n";
	hybridSort(arr, size, compCount, moveCount);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}
	*/
	return 0;
}

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

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int partition(int* arr, int size, int& compCount, int& moveCount) {
	int pivot = arr[size - 1];
	int* small = arr;
	for (int i = 0; i < size-1; i++)
	{
		compCount++;
		if (arr[i] < pivot) {
			moveCount++;
			swap(*small, arr[i]);
			small++;
		}
	}
	moveCount++;
	swap(*(small ), arr[size - 1]);
	return small - arr+1;
}
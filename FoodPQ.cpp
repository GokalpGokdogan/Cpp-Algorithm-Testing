#include "FoodPQ.h"
#include "Food.h"

#include <iostream>
using namespace std;
FoodPQ::FoodPQ(int x) : size(0), qualityBool(x) {
	
}


bool FoodPQ::heapIsEmpty() {
	return (size == 0);
}

void FoodPQ::heapInsert(Food*& newItem) {
	if (qualityBool) {

		//const int MAX_HEAP = 30;
		if (size >= 30) {
			cout << "HeapException: Heap full\n";
			return;
		}

		// Place the new item at the end of the heap
		items[size] = newItem;

		// Trickle new item up to its proper position
		int place = size;
		int parent = (place - 1) / 2;
		while ((place > 0) && (items[place]->getQuality() > items[parent]->getQuality())) {
			Food* temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;

			place = parent;
			parent = (place - 1) / 2;
		}
		++size;
	}
	else {//for spawn time

		//const int MAX_HEAP = 30;
		if (size >= 30) {
			cout << "HeapException: Heap full\n";
			return;
		}

		// Place the new item at the end of the heap
		items[size] = newItem;

		// Trickle new item up to its proper position
		int place = size;
		int parent = (place - 1) / 2;
		while ((place > 0) && (items[place]->getSpawn() < items[parent]->getSpawn())) {
			Food* temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;

			place = parent;
			parent = (place - 1) / 2;
		}
		++size;
	}



}

void FoodPQ::heapDelete(Food*& rootItem) {
	if (heapIsEmpty()) {
		cout << "HeapException: Heap empty\n";
		return;
	}
	else {
		rootItem = items[0];
		items[0] = items[--size];
		items[size] = nullptr;
		heapRebuild(0);
	}
}

Food* FoodPQ::returnFirst()
{
	if (size == 0)
		return nullptr;

	Food* temp = items[0];
	heapDelete(items[0]);
	return temp;
}

int FoodPQ::getSize()
{
	return size;
}

Food* FoodPQ::getFirst()
{
	if (!heapIsEmpty()) {
		return items[0];
	}

	return nullptr;
}

FoodPQ::~FoodPQ()
{
	for (int i = 0; i < size; i++) {
		delete items[i];
	}
}

void FoodPQ::heapRebuild(int root) {


	if (qualityBool) {
		int child = 2 * root + 1; 	
		if (child < size) {
			
			int rightChild = child + 1; 	
			
			if ((rightChild < size) &&
				(items[rightChild]->getQuality() > items[child]->getQuality())) {
				child = rightChild;
			}
			else if((rightChild < size) && (items[rightChild]->getQuality() == items[child]->getQuality())) {
				if (items[rightChild]->getId() < items[child]->getId()) {
					child = rightChild;
				}
			}
					

			// If root’s item is smaller than larger child, swap values
			if (items[root]->getQuality() < items[child]->getQuality()) {
				Food* temp = items[root];
				items[root] = items[child];
				items[child] = temp;

				// transform the new subtree into a heap
				heapRebuild(child);
			}
			else if (items[root]->getQuality() == items[child]->getQuality()) {
				if (items[root]->getId() > items[child]->getId()) {
					Food* temp = items[root];
					items[root] = items[child];
					items[child] = temp;

					// transform the new subtree into a heap
					heapRebuild(child);
				}
			}
		}
	}
	else { // for spawn time
		int child = 2 * root + 1; 	// index of root's left child, if any
		if (child < size) {
			// root is not a leaf so that it has a left child
			int rightChild = child + 1; 	// index of a right child, if any
			// If root has right child, find larger child
			if ((rightChild < size) &&
				(items[rightChild]->getSpawn() < items[child]->getSpawn()))
				child = rightChild; 	// index of larger child

			// If root’s item is smaller than larger child, swap values
			if (items[root]->getSpawn() > items[child]->getSpawn()) {
				Food* temp = items[root];
				items[root] = items[child];
				items[child] = temp;

				// transform the new subtree into a heap
				heapRebuild(child);
			}
		}
	}

}

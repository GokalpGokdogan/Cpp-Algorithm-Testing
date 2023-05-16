#include "CreaturePQ.h"
#include"Creature.h"

#include <iostream>
using namespace std;
CreaturePQ::CreaturePQ() : size(0) {

}


bool CreaturePQ::heapIsEmpty() {
	return (size == 0);
}

void CreaturePQ::heapInsert(Creature*& newItem) {

	//int MAX_HEAP = 30;
	if (size >= 30) {
		cout << "HeapException: Heap full\n";
		return;
	}

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1) / 2;
	while ((place > 0) && (items[place]->getId() < items[parent]->getId())) {
		Creature* temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
}

void CreaturePQ::heapDelete(Creature*& rootItem) {
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

Creature* CreaturePQ::returnFirst()
{
	if (size == 0)
		return nullptr;

	Creature* temp = items[0];
	heapDelete(items[0]);
	return temp;
}

int CreaturePQ::getSize()
{
	return size;
}

Creature* CreaturePQ::getFirst()
{
	if (!heapIsEmpty()) {
		return items[0];
	}

	return nullptr;
}

CreaturePQ::~CreaturePQ()
{
	for (int i = 0; i < size; i++) {
		delete items[i];
		items[i] = nullptr;
	}
}

void CreaturePQ::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) &&
			(items[rightChild]->getId() < items[child]->getId()))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (items[root]->getId() > items[child]->getId()) {
			Creature* temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
#pragma once
#include "Food.h"


class FoodPQ
{
public:

	//const int MAX_HEAP = 30;
	FoodPQ(int x);
	bool heapIsEmpty();
	void heapInsert(Food*& newItem);
	void heapDelete(Food*& rootItem);
	void heapRebuild(int root);
	Food* returnFirst();
	
	
	int getSize();
	Food* getFirst();

	~FoodPQ();
private:
	Food* items[30];//[MAX_HEAP];	// array of heap items
	int	size;
	bool qualityBool;


};



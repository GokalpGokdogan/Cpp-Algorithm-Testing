#pragma once
#include "Creature.h"
class CreaturePQ
{
public:

	//const int MAX_HEAP = 30;
	CreaturePQ();
	bool heapIsEmpty();
	void heapInsert(Creature*& newItem);
	void heapDelete(Creature*& rootItem);
	void heapRebuild(int root);
	Creature* returnFirst();
	int getSize();
	Creature* getFirst();
	~CreaturePQ();
private:
	Creature* items[30];//[MAX_HEAP];	// array of heap items
	int	size;
	

};

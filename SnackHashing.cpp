#include "SnackHashing.h"
#include "Snack.h"
#include <list>
using namespace std;

SnackHashing::SnackHashing()
{
	//arr = new list<Snack>[11];
}

void SnackHashing::add(Snack s)
{
	int index = strToHash(s.name) % 11;
	//if (find(arr[index].begin(), arr[index].end(), s) == arr[index].end()) {
		arr[index].push_back(s);
	//}
}

void SnackHashing::erase(string s)
{
	int index = strToHash( s) % 11;
	//auto i = find(arr[index].begin(), arr[index].end(), s);
	/*if (i != arr[index].end()) {
		arr[index].remove(s);
	}*/
	for (auto i = arr[index].begin(); i != arr[index].end(); i++)
	{
		if (i->name == s) {
			arr[index].remove(*i);
			return;
		}
	}
}

Snack* SnackHashing::find(string s)
{
	int index = strToHash(s) % 11;
	for (auto i = arr[index].begin(); i != arr[index].end(); i++)
	{
		if (i->name == s) {
			return &*i;
		}
	}

	return nullptr;
}

int SnackHashing::strToHash(string s)
{
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}

	return sum;
	}



//int SnackHashing::toHash(Snack s) {
//
//	int sum = 0;
//
//	for (int i = 0; i < s.name.size(); i++) {
//		sum += s.name[i];
//	}
//
//	return sum;
//}

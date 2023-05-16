#include "AccompanimentHashing.h"
#include <string>
AccompanimentHashing::AccompanimentHashing()
{
    //arr = new Accompaniment[71];
}

int AccompanimentHashing::toHash(Accompaniment s)
{
	int sum = 0;

	for (int i = 0; i < s.name.size(); i++) {
		sum += s.name[i];
	}

	return sum;
}

void AccompanimentHashing::add(Accompaniment s)
{
	int index = toHash(s) % 71;
	for (int i = 0; !isFull(); i++)
	{
		int ind = (index + i * i) % 71;
		if (arr[ind].name == "") {
			arr[ind] = s;
			return;
		}

	}
}

void AccompanimentHashing::erase(string s1,string s2)
{
	int check = 0;
	int index = toHash(Accompaniment(s1+s2,nullptr,nullptr) )% 71;
	for (int i = 0; check<71; i++)
	{
		check++;
		int ind = (index + i * i) % 71;
		if (arr[ind].name == s1+s2 || arr[ind].name == s2 + s1) {
			arr[ind].name = "";
			arr[ind].snack0 = nullptr;
			arr[ind].snack1 = nullptr;
			return;

		}

	}
}



bool AccompanimentHashing::isFull()
{
	for (int i = 0; i < 71; i++)
	{
		if (arr[i].name == "") {
			return false;
		}

	}
	return true;
}

bool AccompanimentHashing::isThere(string s1, string s2)
{
	//int check = 0;
	int index = strToHash(s1+s2) % 71;
	for (int i = 0; /*check<71*/true; i++)
	{
		if (arr[(index + i * i) % 71].name == s1+s2 || arr[(index + i * i) % 71].name == s2 + s1) {
			return true;
		}
		else if (arr[(index + i * i) % 71].name == "") {
			return false;
		}
		//check++;

	}
	return false;
}



int AccompanimentHashing::strToHash(string s)
{
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}

	return sum;
}




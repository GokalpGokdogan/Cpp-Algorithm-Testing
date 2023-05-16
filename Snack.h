#pragma once
#include <string>
#include <vector>
using namespace std;
class Snack
{
public:
	string name;
	vector<Snack> accompanied;
	void addAccompanied(Snack& s);
	void printAccompanied();
	Snack(string s);
	Snack();
	Snack(const Snack& s);
	~Snack();
	Snack* findSnack(string s);
	void eraseAccompanied(string s);

	bool operator==(const Snack& other) const;

	void operator=(const Snack& other);

	/// needs copy constructor...
};


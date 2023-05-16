
#include <random>
#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Snack.h"
#include "SnackHashing.h"
#include "Accompaniment.h"
#include "AccompanimentHashing.h"

using namespace std;

int main() {

	
	string input;
	SnackHashing sHash;
	AccompanimentHashing acHash;

	while (true)
	{
		getline(cin, input);
		stringstream str(input);
		char selection;
		str >> selection;
		if (selection == 'S') {

			string str1;
			str >> str1;
			Snack s(str1);
			sHash.add(s);
			cout << "Snack '" << str1 <<"' created" << endl;

		}
		else if (selection == 'C') {
			string str1, str2;
			str >> str1 >> str2;
			Snack* s1, * s2;
			sHash.find(str1)->addAccompanied(*sHash.find(str2));///needs checking
			sHash.find(str2)->addAccompanied(*sHash.find(str1));
			s1 = sHash.find(str1)->findSnack(str2);
			s2 = sHash.find(str2)->findSnack(str1);
			Accompaniment a(str1 + str2, s1, s2);
			acHash.add(a);

		}
		else if (selection == 'D') {
			string str1, str2;
			str >> str1 >> str2;
			//acHash.erase(str1, str2);

			sHash.find(str1)->eraseAccompanied(str2);
			sHash.find(str2)->eraseAccompanied(str1);
			acHash.erase(str1, str2);

		}
		else if (selection == 'L') {
			string str1;
			str >> str1;
			sHash.find(str1)->printAccompanied();
		}
		else if (selection == 'Q') {
			string str1, str2;
			str >> str1 >> str2;
			bool res = acHash.isThere(str1, str2);
			if (res) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}

		}
		else if (selection == 'X') {
			return 0;

		}


	}


	
	return 0;
}





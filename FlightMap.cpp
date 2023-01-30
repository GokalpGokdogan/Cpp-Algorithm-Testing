#include "FlightMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

/// <summary>
/// Mustafa Gokalp Gokdogan
/// Section: 3
/// 22102936
/// </summary>

FlightMap::FlightMap(const string cityFile, const string flightFile)
{

	list<string> l1;
	ifstream cityName;
	string line;
	int check = 0;
	cityName.open(cityFile.c_str(), ios::in);
	if (cityName)
	{
		while (getline(cityName, line)) {
			stringstream stream(line);
			//getline(cityName, line);
			/*stringstream stream(line);
			string part1, part2, part3, part4;
			getline(stream, part1, ';');
			getline(stream, part2, ';');
			getline(stream, part3, ';');
			getline(stream, part4, ';');*/
			string s(line);
			//cities.push_back(s);
			l1.push_back(s);
		}
	}
	else
	{
		check++;
		cout << "Input file " << cityFile << " does not exist\n";
	}
	l1.sort();
	while (l1.size()!=0)
	{
		cities.push_back(l1.front());
		l1.pop_front();
	}
	ifstream flightName;

	
	flightName.open(flightFile.c_str(), ios::in);
	if (flightName)
	{
		string line;
		while (getline(flightName, line)) {
			stringstream stream(line);
			string part1, part2, part3, part4;
			getline(stream, part1, ';');
			getline(stream, part2, ';');
			getline(stream, part3, ';');
			getline(stream, part4, ';');
			int id;
			stream.clear();
			stream.str(part3);
			stream >> id;
			
			int value;
			stream.clear();
			stream.str(part4);
			stream >> value;

			Flight fff(id, value, part1, part2);
			flights.push_back(fff);
		}
		
	}
	else
	{
		check++;
		cout << "Input file " << flightFile << " does not exist\n";
	}
	cout << cities.size() << " cities and " << flights.size() << " flights have been loaded\n";


}

void FlightMap::displayAllCities() const
{
	if (cities.size()) {
		cout << "The list of the cities that HPAir serves is given below:\n";
		for (int i = 0; i < cities.size(); i++) {
			cout << cities[i] << ", ";
			/*
			if (i != cities.size() - 1) {
				cout << ", ";
			}
			*/
		}
		cout << endl;
	}
	
}

void FlightMap::displayAdjacentCities(const string cityName) const
{
	bool cityExists=0;
	if (cities.size()) {
		//cout << "The list of the cities that HPAir serves is given below:\n";
		for (int i = 0; i < cities.size(); i++) {
			if (cities[i]==cityName) {
				cityExists++;
				break;
			}
				/*
			if (i != cities.size() - 1) {
				cout << ", ";
			}*/
		}
		if (cityExists) {
			cout << "The cities adjacent to " << cityName << " are:\n" << cityName << " -> ";
			list<string> l1;
			for (int i = 0; i < flights.size(); i++) {
				if (flights[i].from == cityName) {
					l1.push_back(flights[i].to);
					//cout << flights[i].to << ", ";
				}
			}
			l1.sort();
			while (l1.size() != 0)
			{
				cout << l1.front() << ", ";
				l1.pop_front();
			}
		}


		cout << endl;
	}
}

void FlightMap::displayFlightMap() const
{
	cout << "The whole flight map is given below:\n";
	
	for (int i = 0; i < cities.size(); i++) {
		cout << cities[i] << " -> ";
		list<string> l1;
		for (int j = 0; j < flights.size(); j++) {
			if (flights[j].from == cities[i]) {
				l1.push_back(flights[j].to);
				//cout << flights[j].to << ", ";
			}
		}
		l1.sort();
		while (l1.size()!=0)
		{
			cout << l1.front() << ", "; 
			l1.pop_front();
		}
		cout << endl;
	}

}

void FlightMap::findFlights(const string deptCity, const string destCity) const
{
	vector<stack<string>> v_Of_s;
	vector<int> prices;

	cout << "Request is to fly from " << deptCity << " to " << destCity << ":\n";
	
	stack<string> current;
	current.push(deptCity);
	//bool success=0;
	while (current.size() != 0) {
		if (current.top() == destCity) {
			//printFlights(current);
			prices.push_back(searchFlights(current));
			v_Of_s.push_back(current);
			current.pop();
			
			for (int i = 0; i < prices.size(); i++)
			{
				int min = prices[i];
				for (int j = i; j < prices.size(); j++) {
					if (prices[j] < prices[i]) {
						int temp = prices[i];
						prices[i] = prices[j];
						prices[j] = temp;

						stack<string> temp0 = v_Of_s[i];
						v_Of_s[i] = v_Of_s[j];
						v_Of_s[j] = temp0;
					}
				}
			}
			
		}
		else {
			if (!availableFlights(current.top())) {
				current.pop();
			}
			else
			{
				int check = -1;
				for (int i = 0; i < flights.size(); i++)
				{
					if (current.top() == flights[i].from) {
						if (flights[i].state == 0) {
							//current.push(flights[i].to);
							flights[i].state = -1;
							check = i;
							break;
						}
						
						
					}
				}

				if (check == -1) {
					for (int i = 0; i < flights.size(); i++)
					{
						if (current.top() == flights[i].from) {
							//if (flights[i].state == 0) {
							//	//current.push(flights[i].to);
							//	flights[i].state = -1;
							//	check = i;
							//	break;
							//}
							flights[i].state = 0;


						}
					}
					current.pop();
				}
				else {
					current.push(flights[check].to);
					if (!unvisited(current))
					{
						current.pop();
						
						/*
						current.pop();
						while (flights[check].to != current.top())
						{

						}*/

					}
					
				}
			}
		}
		

	}
	if (v_Of_s.size() == 0) {
		cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << ".\n";
	}
	else {
		print(v_Of_s);
	}
	reset();
}

void FlightMap::printFlights(stack<string> current) const {
	stack<string> temp;
	while (!current.empty())
	{
		temp.push(current.top());
		current.pop();
	}

	while (!temp.empty())
	{
		string n = temp.top();
		temp.pop();
		//cout << "Request is to fly from "<< <<" to "<< <<":"
	}
	
	
}

void FlightMap::searchFlights(const string deptCity, const string destCity) const {
	for (int i = 0; i < flights.size(); i++)
	{
		if (flights[i].to == destCity && flights[i].from == deptCity) {
			//flights[i].changeState(1);
		}
	}
}
int FlightMap::searchFlights(stack<string> current) const {

	stack<string> temp;
	while (!current.empty())
	{
		temp.push(current.top());
		current.pop();
	}
	string n = temp.top();
	temp.pop();
	string n1 = temp.top();
	temp.pop();

	int tot = 0;

	while (!temp.empty())
	{
		
		for (int i = 0; i < flights.size(); i++)
		{

			if (n == flights[i].from) {
				if (flights[i].to == n1) {
					flights[i].state = 1;
					//cout << "Flight #" << flights[i].id << " from " << flights[i].from << " to " << flights[i].to << ", Cost: " << flights[i].cost << " TL" << endl;
					tot += flights[i].cost;
					n = n1;
					n1 = temp.top();
					temp.pop();
					break;
				}
			}
		}
		
	}
	for (int i = 0; i < flights.size(); i++)
	{

		if (n == flights[i].from) {
			if (flights[i].to == n1) {
				flights[i].state =  1;
				//cout << "Flight #" << flights[i].id << " from " << flights[i].from << " to " << flights[i].to << ", Cost: " << flights[i].cost << " TL" << endl;
				tot += flights[i].cost;
				
				
				break;
			}
		}
	}
	//cout << "Total Cost: " << tot << " TL\n";
	return tot;
}



bool FlightMap::availableFlights(const string deptCity) const {
	//bool check = false;
	
	for (int i = 0; i < flights.size(); i++)
	{
		if (deptCity == flights[i].to) {
			if (flights[i].state == 0) {
				return true;
			}
		}
	}
	for (int i = 0; i < flights.size(); i++)
	{
		if (deptCity == flights[i].from) {
			if (flights[i].state == 0|| flights[i].state == 1) {
				return true;
			}
		}
	}
	return false;
}

bool FlightMap::unvisited(stack<string> current) const {
	//bool check = false;
	string last = current.top();
	current.pop();
	while (current.size() != 0)
	{
		if (last == current.top()) {

			return false;

		}
		current.pop();

	}
	return true;
}
void FlightMap::reset() const {
	for (int i = 0; i < flights.size(); i++)
	{
		flights[i].state = 0;
		
	}
}

void FlightMap::print(vector<stack<string>> v) const {
	for (int i = 0; i < v.size(); i++) {
		stack<string> current = v[i];
		stack<string> temp;
		while (!current.empty())
		{
			temp.push(current.top());
			current.pop();
		}
		string n = temp.top();
		temp.pop();
		string n1 = temp.top();
		temp.pop();

		int tot = 0;

		while (!temp.empty())
		{

			for (int i = 0; i < flights.size(); i++)
			{

				if (n == flights[i].from) {
					if (flights[i].to == n1) {
						flights[i].state = 1;
						cout << "Flight #" << flights[i].id << " from " << flights[i].from << " to " << flights[i].to << ", Cost: " << flights[i].cost << " TL" << endl;
						tot += flights[i].cost;
						n = n1;
						n1 = temp.top();
						temp.pop();
						break;
					}
				}
			}

		}
		for (int i = 0; i < flights.size(); i++)
		{

			if (n == flights[i].from) {
				if (flights[i].to == n1) {
					flights[i].state = 1;
					cout << "Flight #" << flights[i].id << " from " << flights[i].from << " to " << flights[i].to << ", Cost: " << flights[i].cost << " TL" << endl;
					tot += flights[i].cost;


					break;
				}
			}
		}
		cout << "Total Cost: " << tot << " TL\n";
	}

}
bool FlightMap::isConnected(const string deptCity) const {
	return 0;
}
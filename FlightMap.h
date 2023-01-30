#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include "Flight.h"

/// <summary>
/// Mustafa Gokalp Gokdogan
/// Section: 3
/// 22102936
/// </summary>

class FlightMap
{
private:
	vector<string> cities;
	vector<Flight> flights;
public:
	FlightMap(const string cityFile, const string flightFile);
	//~FlightMap();
	void displayAllCities() const;
	void displayAdjacentCities(const string cityName) const;
	void displayFlightMap() const;
	void findFlights(const string deptCity, const string destCity) const;
	void printFlights(stack<string>) const;
	void searchFlights(const string deptCity, const string destCity) const;
	int searchFlights(stack<string> current) const;
	bool availableFlights(const string deptCity) const;
	bool unvisited(stack<string> current) const;
	void reset() const;
	void print(vector<stack<string>> current) const;
	bool isConnected(const string deptCity) const;
};


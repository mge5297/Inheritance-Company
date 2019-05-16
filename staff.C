/**********************************************
* Program:  staff.C                           *
* Author:   Eileen Peluso                     *
* Date:     04/23/19                          *
*                                             *
* Abstract: Final 2019, Part 2                *
**********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Employee.h"

using namespace std;

int main() {
	// *************************************************************
	// Define an array of 10 Technician objects called "techies"
	
	
	Technician techies[10];
	
	
	// *************************************************************
	ifstream inFile("staff.dat");
	if (!inFile){
		cout << "You must have forgotten to copy in \"staff.dat\"";
		return 1;
	}
	string name;
	string ID;
	int weeks;
	double yearlyPay;
	char payFreq;
	string certifications;
	
	for (int i = 0; i < 10; i++)
	{
		getline(inFile, name);
		inFile >> ID;
		inFile >> weeks;
		inFile >> yearlyPay;
		inFile >> payFreq;
		getline(inFile, certifications);
		techies[i] = Technician(ID, name, weeks, yearlyPay,payFreq, certifications);
	}
	
	// *************************************************************
	// Write code that will display (using the << operator) all of the techies'
	//   information on the screen
	for (int i = 0; i < 10; i++)
	{
		cout << techies[i] << endl;
	}
	

	// *************************************************************
	
	cout << "\n\n";
	
	// *************************************************************
	// Write code that will SEARCH the array to find the techie who 
	//  has the lowest badge ID (using the < operator)
	//  and then display that person's name and salary on the screen
	int lowest = 0;
	
	for (int i = 0; i < 10; i++)
	{
		if(techies[i] < techies[lowest]){
			lowest = i;
		}
	}
	cout << "The techie with the lowest badge is:" << endl;
	cout << techies[lowest] << endl;

	// *************************************************************

	return 0;
}


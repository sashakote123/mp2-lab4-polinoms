#include <iostream>
#include "list.h"
using namespace std;


int main() {
	
	int NumberOfMonoms;
	int choice = 0;
	double scalar = 0;
	Polinoms p1;
	Polinoms p2;
	cout << "First you need to enter the first polynom\nEnter the number of monoms: ";
	cin >> NumberOfMonoms;
	cout << "Rules for writing a polynom:\nFirst, the coefficient in front of the monom is entered.\nThen the three-digit value of the degree (x - hundreds, y - tens, z - units). Every time for every monom.\nEnter polynom: ";
	p1.setPolinom(NumberOfMonoms);
	cout << "Your first polynom is:\n";
	p1.printPolinom();
	cout << "\nEnter, what to do with polynom:\n1. Add second polynom\n2. Subctruct second polynom\n3. Multiply by a second polynom\n4. Multiply by a scalar\n...";

	while (choice > 5 || choice < 1) {
		cin >> choice;
		if (choice > 5 || choice < 1)
			cout << "Wrong choice!\n";
	}
	switch (choice) {
	case 1: {
		cout << "Polynoms addition.\nEnter second polynom:\nEnter numders of monoms: ";
		cin >> NumberOfMonoms;
		cout << "Enter polynom: ";
		p2.setPolinom(NumberOfMonoms);
		cout << "\nYour second polynom is:\n";
		p2.printPolinom();
		cout << "\nAdditional is: ";
		(p1 + p2).printPolinom();
	}
		  break;
	case 2: {
		cout << "Polynoms substruct.\nEnter second polynom:\nEnter numders of monoms: ";
		cin >> NumberOfMonoms;
		cout << "Enter polynom: ";
		p2.setPolinom(NumberOfMonoms);
		cout << "\nYour second polynom is:\n";
		p2.printPolinom();
		cout << "\nSubctruct is: ";
		(p1 - p2).printPolinom();
	}
		  break;
	case 3: {
		cout << "Polynoms multiply.\nEnter second polynom:\nEnter numders of monoms: ";
		cin >> NumberOfMonoms;
		cout << "Enter polynom: ";
		p2.setPolinom(NumberOfMonoms);
		cout << "\nYour second polynom is:\n";
		p2.printPolinom();
		cout << "\nMultipy is: ";
		(p1 * p2).printPolinom();
	}
		  break;
	case 4: {
		cout << "Multiply by a scalar\nEnter scalar:\n";
		cin >> scalar;
		cout << "Multiply is: ";
		(p1 * scalar).printPolinom();
	}
		  break;
	}
}


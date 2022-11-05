#pragma once
#include <iostream>
using namespace std;

class Zatrati {
protected:
	double tax_expens;
	double purchase_expens;
	double food_expens;
	double entertainment_expens;

public:
	Zatrati() {
		tax_expens = 0;
		purchase_expens = 0;
		food_expens = 0;
		entertainment_expens = 0;
	}
	Zatrati(double te, double pe, double fe, double ee) {
		tax_expens = te;
		purchase_expens = pe;
		food_expens = fe;
		entertainment_expens = ee;
	}

	void PrintExpenses() {
		cout << "Nalogi: " << tax_expens << endl;
		cout << "Chena pokypki: " << purchase_expens << endl;
		cout << "Chena edi: " << food_expens << endl;
		cout << "Chena razvlechenya: " << entertainment_expens << endl;
	}

};

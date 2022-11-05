#pragma once
#include <iostream>
#include "Bankkarta.h"
#include "Zatrati.h"
using namespace std;

class Debkarta : public Bankkarta, public Zatrati {
private:
	int bank_account;
	long balance_account;

public:
	Debkarta() : Bankkarta() {
		bank_account = 0;
		balance_account = 0;
	}
	Debkarta(int ba, long am, string n, string s, string bn, string num, int cvv) : Bankkarta(n, s, bn, num, cvv) {
		bank_account = ba;
		balance_account = am;
	}

	void TaxCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na nalogi: ";
		cin >> answer;
		tax_expens += answer;
		balance_account -= tax_expens;
	}
	void PurchasesCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na pokypki: ";
		cin >> answer;
		purchase_expens += answer;
		balance_account -= purchase_expens;
	}
	void FoodCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na edy: ";
		cin >> answer;
		food_expens += answer;
		balance_account -= food_expens;
	}
	void EntertainmentCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na razvlechenya: ";
		cin >> answer;
		entertainment_expens += answer;
		balance_account -= entertainment_expens;
	}

	string NumberOfCard() {
		return number;
	}
	double getTaxExpens() {
		return tax_expens;
	}
	double getPurchasesExpens() {
		return purchase_expens;
	}
	double getFoodExpens() {
		return food_expens;
	}
	double getEntertainmentExpens() {
		return entertainment_expens;
	}

	void Input() {
		InputCard();
		cout << "Vvedite bankovskyi akkaynt: ";
		cin >> bank_account;
		cout << "Vvedite balans: ";
		cin >> balance_account;
		while (balance_account > bank_account) {
			balance_account = 0;
			cout << "\nOshibka\nTry again: ";
			cin >> balance_account;
		}
		cout << endl;
	}
	void Print() {
		PrintCard();
		cout << "Bankovskaya karta: " << bank_account << endl;
		cout << "Balans akkaynta: " << balance_account << endl;
	}

};
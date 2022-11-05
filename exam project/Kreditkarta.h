#pragma once
#include <iostream>
#include "Bankkarta.h"
#include "Zatrati.h"
using namespace std;

class Kreditkarta : public Bankkarta, public Zatrati {
private:
	int credit_limite;
	double amount_money;

public:
	Kreditkarta() : Bankkarta() {
		credit_limite = 0;
		amount_money = 0;
	}
	Kreditkarta(int cl, double am, string n, string s, string bn, string num, string ed, int cvv) : Bankkarta(n, s, bn, num, cvv) {
		credit_limite = cl;
		amount_money = am;
	}

	void TaxCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na nalogi: ";
		cin >> answer;
		tax_expens += answer;
		amount_money -= tax_expens;
	}
	void PurchasesCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na pokypki: ";
		cin >> answer;
		purchase_expens += answer;
		amount_money -= purchase_expens;
	}
	void FoodCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na edy: ";
		cin >> answer;
		food_expens += answer;
		amount_money -= food_expens;
	}
	void EntertainmentCosts() {
		int answer;
		cout << "Vvedite symmy potrachenyy na razvleshenya: ";
		cin >> answer;
		entertainment_expens += answer;
		amount_money -= entertainment_expens;
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
		cout << "Vvedite creditniy lemit: ";
		cin >> credit_limite;
		cout << "Vvedite balans akkaynta: ";
		cin >> amount_money;
		while (amount_money > credit_limite) {
			amount_money = 0;
			cout << "\nOshibka\nTry again: ";
			cin >> amount_money;
		}
		cout << endl;
	}
	void Print() {
		PrintCard();
		cout << "Kreditniy limit: " << credit_limite << endl;
		cout << "Balans akkaynta: " << amount_money << endl;
	}



};

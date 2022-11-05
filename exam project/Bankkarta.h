#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bankkarta {



protected:
	string name;
	string surname;
	string bank_name;
	string number;
	int cvv;

public:
	Bankkarta() = default;


	Bankkarta(string n, string s, string bn, string num, int cvv) {
		name = n;
		surname = s;
		bank_name = bn;
		number = num;
		this->cvv = cvv;
	}
	Bankkarta(Bankkarta& obj) {
		name = obj.name;
		surname = obj.surname;
		bank_name = obj.bank_name;
		number = obj.number;
		cvv = obj.cvv;
	}

	void InputCard() {
		cout << endl;
		cout << "Vvedite vashe imya: ";
		cin >> name;
		cout << "Vvedite vashy familiy: ";
		cin >> surname;
		cout << "Vvedite imya banka: ";
		cin >> bank_name;
		cout << "Vvedite nomer karti: ";
		cin >> number;
		cout << "Vvedyte daty: ";
		cout << "Vvedite cvv kod: ";
		cin >> cvv;
		while (cvv < 001 || cvv > 999) {
			cvv = 0;
			cout << "\nOshibka\nTry again: ";
			cin >> cvv;
		}
	}
	void PrintCard() {
		cout << "Imya: " << name << endl;
		cout << "Familiya: " << surname << endl;
		cout << "Bank: " << bank_name << endl;
		cout << "Nomer karti: " << number << endl;
		cout << "Cvv kod: " << cvv << endl;
	}

};

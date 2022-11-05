#pragma once
#include <iostream>
using namespace std;

class Koshelek {



private:
	string name;
	string surname;
	string number;




public:
	Koshelek() = default;
	Koshelek(string n, string s, string num) {
		name = n;
		surname = s;
		number = num;
	}

	string getNumberOfWallet() {
		return number;
	}

	void Input() {
		cout << endl;
		cout << "Vvedite vashe imya: ";
		cin >> name;
		cout << "Vvedite vashy familiy: ";
		cin >> surname;
		cout << "Vvedite nomer koshelyka: ";
		cin >> number;
		cout << endl;
	}
	void Print() {
		cout << "Imya: " << name << endl;
		cout << "Familia: " << surname << endl;
		cout << "Nomer koshelyka: " << number << endl;
	}

};

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "Bankkarta.h"
#include "Kreditkarta.h"
#include "Debkarta.h"
#include "Koshelek.h"
#include "Zatrati.h"
using namespace std;

void Menu() {
	typedef map<double, string> minemap;
	typedef minemap::iterator Iter;
	minemap m;
	Iter it;


	ofstream ban("");
	ofstream front_ban;
	ifstream back_ban;


	int day = 0;
	string line;

	int kredit_chose = 0;
	int deb_chose = 0;
	int koshelek_chose = 0;

	string nomer_karti;
	int res, case_res, case_res2, case_res3, case_res4;
	int case_res1_1, case_res2_1, case_res3_1, case_res4_1;

	vector<Kreditkarta*> kredit_karta;
	vector<Debkarta*> deb_karta;
	vector<Koshelek*> wallet;

	bool exit = false;
	while (exit != true) {
		cout << "\n1. Dobavit\n2. Posmotret\n3. Zatrati\n4. Otchet o zatratax\n5. Vihod\n-> ";
		cin >> res, "vvod:";
		switch (res) {
		case 1:
			cout << "\n1. Kreditnaya karta\n2. Debitovaya karta\n3. Koshelek\n-> ";
			cin >> case_res ,"vvod:";
			switch (case_res) {
			case 1:
				kredit_karta.push_back(new Kreditkarta());
				kredit_karta[kredit_chose]->Input();
				kredit_chose++;
				break;

			case 2:
				deb_karta.push_back(new Debkarta());
				deb_karta[deb_chose]->Input();
				deb_chose++;
				break;

			case 3:
				wallet.push_back(new Koshelek());
				wallet[koshelek_chose]->Input();
				koshelek_chose++;
				break;
			}
			break;

		case 2:
			cout << "\n1. Kreditnaya karta\n2. Debitovaya karta\n3. Koshelek\n4. Vse\n-> ";
			cin >> case_res2, "vvod:";
			switch (case_res2) {
			case 1:
				cout << "\nVvedite nomer karti: ";
				cin >> nomer_karti, "vvod:";
				cout << endl;
				for (int i = 0; i < kredit_karta.size(); i++) {
					if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
						kredit_karta[i]->Print();
					}
				}
				cin.ignore();
				break;

			case 2:
				cout << "\nVvedite nomer karti: ";
				cin >> nomer_karti, "vvod:";
				cout << endl;
				for (int i = 0; i < deb_karta.size(); i++) {
					if (nomer_karti == deb_karta[i]->NumberOfCard()) {
						deb_karta[i]->Print();
					}
				}
				cin.ignore();
				break;

			case 3:
				cout << "Enter number of wallet: ";
				cin >> nomer_karti, "vvod:";
				cout << endl;
				for (int i = 0; i < wallet.size(); i++) {
					if (nomer_karti == wallet[i]->getNumberOfWallet()) {
						wallet[i]->Print();
					}
				}
				cin.ignore();
				break;

			case 4:
				for (int i = 0; i < kredit_karta.size(); i++) {
					cout << "\nKreditnaya karta " << i + 1 << endl;
					kredit_karta[i]->Print();
					cout << endl;
				}
				for (int i = 0; i < deb_karta.size(); i++) {
					cout << "\nDebitovaya karta " << i + 1 << endl;
					deb_karta[i]->Print();
					cout << endl;
				}
				for (int i = 0; i < wallet.size(); i++) {
					cout << "Koshelek " << i + 1 << endl;
					wallet[i]->Print();
					cout << endl;
				}
				break;
			}
			break;

		case 3:
			cout << "\n1. Nalogi\n2. Pokypki\n3. Eda\n4. Razvlekalovka\n-> ";
			cin >> case_res3, "vvod:";
			switch (case_res3) {
			case 1:
				cout << "\nViberete karty:" << endl;
				cout << "1. Kreditnaya karta\n2. Debitovaya karta\n-> ";
				cin >> case_res1_1;
				switch (case_res1_1) {
				case 1:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < kredit_karta.size(); i++) {
						if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
							kredit_karta[i]->TaxCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;

				case 2:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < deb_karta.size(); i++) {
						if (nomer_karti == deb_karta[i]->NumberOfCard()) {
							deb_karta[i]->TaxCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;
				}
				break;

			case 2:
				cout << "\nViberete karty:" << endl;
				cout << "1. Kreditnaya karta\n2. Debitovaya karta\n-> ";
				cin >> case_res2_1, "vvod:";
				switch (case_res2_1) {
				case 1:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < kredit_karta.size(); i++) {
						if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
							kredit_karta[i]->PurchasesCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;

				case 2:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < deb_karta.size(); i++) {
						if (nomer_karti == deb_karta[i]->NumberOfCard()) {
							deb_karta[i]->PurchasesCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;
				}
				break;

			case 3:
				cout << "\nVviberete karty:" << endl;
				cout << "1. Kreditnaya karta\n2. Debitovaya karta\n-> ";
				cin >> case_res3_1, "vvod:";
				switch (case_res3_1) {
				case 1:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < kredit_karta.size(); i++) {
						if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
							kredit_karta[i]->FoodCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;

				case 2:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < deb_karta.size(); i++) {
						if (nomer_karti == deb_karta[i]->NumberOfCard()) {
							deb_karta[i]->FoodCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;
				}
				break;

			case 4:
				cout << "\nViberete karty:" << endl;
				cout << "1. Kreditnaya karta\n2. Debitovaya karta\n-> ";
				cin >> case_res4_1, "vvod:";
				switch (case_res4_1) {
				case 1:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < kredit_karta.size(); i++) {
						if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
							kredit_karta[i]->EntertainmentCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;

				case 2:
					cout << "Vvedite nomer karti: ";
					cin >> nomer_karti, "vvod:";
					for (int i = 0; i < deb_karta.size(); i++) {
						if (nomer_karti == deb_karta[i]->NumberOfCard()) {
							deb_karta[i]->EntertainmentCosts();
							cout << endl;
						}
					}
					cin.ignore();
					break;
				}
				break;
			}
			break;

		case 4:
			front_ban.open("sohranit ban.txt");
			back_ban.open("sohranit ban.txt");
			cout << "\n1. Kreditnaya karta\n2. Debitovaya karta\n-> ";
			cin >> case_res4, "vvod:";
			if (case_res4 == 1) {
				cout << "\nVvedite nomer karti: ";
				cin >> nomer_karti, "vvod:";
				cout << endl;
				for (int i = 0; i < kredit_karta.size(); i++) {
					if (nomer_karti == kredit_karta[i]->NumberOfCard()) {
						m.emplace(make_pair(kredit_karta[i]->getTaxExpens(), "Nalogi: "));
						m.emplace(make_pair(kredit_karta[i]->getPurchasesExpens(), "Pokypki: "));
						m.emplace(make_pair(kredit_karta[i]->getFoodExpens(), "Eda: "));
						m.emplace(make_pair(kredit_karta[i]->getEntertainmentExpens(), "Razvlechenya: "));
					}
				}
				cin.ignore();
			}
			else if (case_res4 == 2) {
				cout << "\nVvedite nomer karti: ";
				cin >> nomer_karti, "vvod:";
				cout << endl;
				for (int i = 0; i < deb_karta.size(); i++) {
					if (nomer_karti == deb_karta[i]->NumberOfCard()) {
						m.emplace(make_pair(deb_karta[i]->getTaxExpens(), "Nalogi: "));
						m.emplace(make_pair(deb_karta[i]->getPurchasesExpens(), "Pokypki: "));
						m.emplace(make_pair(deb_karta[i]->getFoodExpens(), "Eda: "));
						m.emplace(make_pair(deb_karta[i]->getEntertainmentExpens(), "Razvlechenya: "));
					}
				}
				cin.ignore();
			}

			cout << "\n1. Rashodi v pervyi den\n2. Rashodi za nedely\n-> ";
			cin >> case_res4, "vvod:";
			if (case_res4 == 1) {
				day++;
				front_ban << day << endl;
				for (it = m.end(); it != m.begin(); ) {
					it--;
					front_ban << it->second << it->first << endl;
				} m.clear();
				if (day == 1) {
					while (!back_ban.eof()) {
						if (line == to_string(day) || line != to_string(day + 1)) {
							getline(back_ban, line);
							ban << line << endl;
						}
					}
					cout << "Zaversheno" << endl;
				}
			}
			else if (case_res4 == 2) {
				day++;
				front_ban << day << endl;
				for (it = m.end(); it != m.begin(); ) {
					it--;
					front_ban << it->second << it->first << endl;
				} m.clear();
				if (day == 7) {
					while (!back_ban.eof()) {
						if (line == to_string(day) || line != to_string(day + 1)) {
							getline(back_ban, line);
							ban << line << endl;
						}
					}
					cout << "Zaversheno" << endl;
				}
			}
			front_ban.close();
			back_ban.close();
			break;

		case 5:
			exit = true;
			break;
		}
	}

}

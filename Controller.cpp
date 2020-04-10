#include "Controller.h"
#include "Repo.h"
#include "Medikament.h"
#include "UI.h"
#include "App.h"
#include<iostream>
using namespace std;


Controller::Controller(){}

void Controller::ui_menu(int choice, Repo* r, Medikament m){

	Medikament* med;
	int quantity, op = choice, price_reduc;
	float concentration, price;
	string name,s;
	
	switch (op) {


	case 0:

		cout << "Bye Bye!";

		system("PAUSE");

	case 1:
		cout << "Please name the medicine you wish to add!" << endl;
		cin >> name;
		cout << "How much does this medicine cost?" << endl;
		cin >> price;
		cout << "Quantity?" << endl;
		cin >> quantity;
		cout << "Concentration?" << endl;
		cin >> concentration;

		med = new Medikament(quantity, concentration, price, name);
		if (r->add_Medikament(*med) == true)
		{
			for (int i = 0; i < r->size_medicine(); i++)
				if (r->medicine.at(i).get_Name() == name && r->medicine.at(i).get_Concentration() == concentration)
				{
					r->medicine.at(i).set_Quantity(quantity);
					r->medicine.at(i).print();
					break;
				}

		}
		else {
			r->add_Medikament(*med);
			int poz = r->medicine.size() - 1;
			r->medicine.at(poz).print();

			delete med;
		}

		system("PAUSE");
		break;

	case 2:

		cout << "Which medicine would you like to delete?";
		cin >> name;
		cout << "Concentration?";
		cin >> concentration;

		r->delete_Medikament(name, concentration);
		system("PAUSE");
		break;


	case 3:
		cout << "Medicine?";
		cin >> name;
		cout << "Concentration?";
		cin >> concentration;
		cout << "Enter reduction price:";
		cin >> price_reduc;
		r->update_Medikament_Price(name, concentration, price_reduc);

		system("PAUSE");
		break;


	case 4:
		cout << "Enter the string you want to sort by."<<endl;
		cin >> s;
		cout << "The drugs that contain " << s << " are:" << endl;
		r->sort_by_string(m, s);

		system("PAUSE");
		break;
	
	/*
	case 5:
		cout << "What concentration";
		cin >> concentration;
		cout << "medicine";
		cin >> name;
		break;
		system("PAUSE");
				
	case 6:
		cout << "Medicine?";
		cin >> name;
		cout << "Price?";
		cin >> price;
		break;
		system("PAUSE");
	
	*/
	}


	
}
#include "Controller.h"
#include "Repo.h"
#include "Medikament.h"
#include<iostream>
using namespace std;


Controller::Controller(){}

void Controller::ui_menu(int choice, Repo* r, Medikament m) {

	Medikament* med;
	int quantity, op = choice, price_reduc;
	float concentration, price;
	string name;
	bool exit = false;


	while (exit!=true) {
		
		switch (op)
			
		{
		case 0:
			
			cout << "Bye Bye!";
			exit = true;
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
			if (r->add_Medikament(*med) == false) {
				for (int i = 0; i < r->size_medicine(); i++)
					if (r->medicine.at(i).get_Name() == name && r->medicine.at(i).get_Concentration() == concentration) {
						r->medicine.at(i).set_Quantity(quantity);
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
			cout << "Enter reduction price.";
			cin >> price_reduc;
			r->update_Medikament(name, concentration, price_reduc);

			break;
			system("PAUSE");


		case 4:
			cout << "Medicine?";
			cin >> name;
			cout << "Price?";
			cin >> price;
			break;
		case 5:
			//ne trebuie un fisier de ex medicamente.txt,deoarece am functie de undo si redo,care cred ca necesita un fisier
			
		}
	}
}
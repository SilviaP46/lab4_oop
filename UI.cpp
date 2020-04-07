#include "UI.h"
#include "Repo.h"
#include "Medikament.h"
#include "Controller.h"
#include <iostream>
using namespace std;

UI::UI(){}

void UI::Menu(){

	Medikament m;
	Repo r;
	Controller c;

	int choice;
	do
	{
		system("CLS");
		cout << "MENU" << endl;
		cout << "Enter your choice or press 0 to exit!" << endl;
		cout << "1.Add medicine." << endl;
		cout << "2.Delete medicine." << endl;
		cout << "3.Edit medicine price." << endl;
		cout << "4.group Medikament by price" << endl;
		
		cin >> choice;

		c.ui_menu(choice, &r, m);
		
	} while (choice != 0);
	
}





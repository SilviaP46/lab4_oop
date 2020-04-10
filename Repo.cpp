#include "Repo.h"
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

Repo::Repo() {}

bool Repo::add_Medikament(Medikament m) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == m.get_Name() && medicine.at(i).get_Concentration() == m.get_Concentration())
		{
			return true;
			break;
		}
			
	}
	medicine.push_back(m);
	return false;
}

void Repo::delete_Medikament(string name,float concentration) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == name && medicine.at(i).get_Concentration()==concentration) {
			medicine.erase(medicine.begin() + i);
			cout << "Medicine deleted!"<<endl;
			return;
		}
	}
	cout << "Medicine does not exist."<<endl;
}


void Repo::update_Medikament_Price(string name, float concentration,int p) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == name && medicine.at(i).get_Concentration()==concentration) {
			cout << "Old price:" << medicine.at(i).get_Price() << endl;
			medicine.at(i).set_Price(medicine.at(i).get_Price() - p);
			cout <<"New price:"<<medicine.at(i).get_Price()<<endl;
		}
	}
}



void  Repo::sort_by_string(Medikament m, string s) {

	string str = s;

	auto compareFunction = [](Medikament a, Medikament b) {

		return a.get_Name() < b.get_Name(); 
	};

	sort(medicine.begin(), medicine.end(), compareFunction);

	if (s == "ok")
	{
		for (int i = 0; i < medicine.size(); i++)
			medicine[i].print();
	}

	else {

		vector<Medikament> aux;

		for (int i = 0;i < medicine.size();i++)
		{
			if (medicine.at(i).get_Name().find(s) != string::npos) //until end of string
				aux.push_back(medicine.at(i));
		}

		for (int i = 0; i < aux.size(); i++)
			aux[i].print();

	}
	}




/*

void Repo::Search()//search a medicine by concentration,if it is smaller then
{
	int x;
	cout << "Show the Concentration for search";
	cin >> x;
	Medikament temp;
	int ok = 0;
	ifstream in("medicament.txt", ios::in);
	while (in >> temp.get_Name >> temp.get_Concentration >> temp.get_Price >> temp.get_Quantity)//read one line
		if (in >> temp.get_Concentration)
		{
			ok = 1;
			cout << temp.get_Name() << " " << temp.get_Concentration() << " " << temp.get_Price() << " " << temp.get_Quantity() << " \n";
		}
	if (ok == 0)
	{
		cout << "There is no medicine by concentration!";
	}
}



void Repo::Group()//group Medikament by price
{
	


	//create 2 vectors and memorize the name and the price of each one
	Medikament temp;
	ifstream in("medicament.txt", ios::in);
	while (in >> temp.get_Name >> temp.get_Concentration >> temp.get_Price >> temp.get_Quantity)

		v.push_back(temp);//create a vector
	int k = 0;
	for (const auto& it : v)
	{
		name.push_back(it.get_Name());
		price.push_back(it.get_Price());
		k++;
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (price[i] > price[j])
			{
				int aux = price[i];
				string aux1 = name[i];
				price[i] = price[j];
				price[j] = aux;
				name[i] = name[j];
				name[j] = aux1;
			}
		}
	}
	//group the elem by price and display them
	int i = 0;
	while (i < k)
	{
		cout << "Price: " << price[i] << " - ";
		int j = i;
		while (j < k)
		{
			if (price[i] == price[j])
			{
				cout << name[j] << " ";
				j++;
			}
			else
				break;
		}
		i = j;
		cout << endl;
	}
}

void Repo::RUndo()//help function for Undo
{
	Medikament temp;
	ifstream in("medicament.txt", ios::in);
	while (in >> temp.get_Name >> temp.get_Concentration >> temp.get_Price >> temp.get_Quantity)
		c.push_back(temp);//create a vektor
}

void Repo::Undo()
{
	vector<Medikament>g;
	g = c;
	ofstream trunc("medicament.txt", ios::out);
	for (const auto& medi : g)
	{
		trunc << medi.get_Name()<< ' ' << medi.get_Concentration() << ' ' << medi.get_Price() << ' ' << medi.get_Quantity() << ' ' << endl;
	}
	cout << "Undo/Redo was mad...search in the folder for verification" << endl;
	c = {};
}

*/


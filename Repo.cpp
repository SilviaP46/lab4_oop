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





void Repo::Search(float c)//search a medicine by concentration,if it is smaller then
{
	int x = c;
	int ok = 0;
	for (int i = 0; i < medicine.size(); i++)
		if (medicine.at(i).get_Concentration() < c) {
			medicine.at(i).print();
			ok = 1;
		}

	if (ok == 0)
	{
		cout << "There is no medicine by concentration!";
	}
}



void Repo::Group()//group Medikament by price
{

	for (int i = 0; i < medicine.size(); i++) //sortare
	{
		for (int j = 0; j < medicine.size(); j++)
		{
			if (medicine.at(i).get_Price() > medicine.at(j).get_Price())
			{
				int aux = medicine.at(i).get_Price();
				string aux1 = medicine.at(i).get_Name();
				medicine.at(i).set_Price(medicine.at(j).get_Price());
				medicine.at(j).set_Price(aux);
				medicine.at(i).set_Name(medicine.at(j).get_Name());
				medicine.at(j).set_Name(aux1);
			}
		}
	}
	//group the elem by price and display them
	int i = 0;
	while (i < medicine.size())
	{
		cout << "Price: " << medicine.at(i).get_Price() << " - ";
		int j = i;
		while (j < medicine.size())
		{
			if (medicine.at(i).get_Price() == medicine.at(j).get_Price())
			{
				cout << medicine.at(j).get_Name() << " ";
				j++;
			}
			else
				break;
		}
		i = j;
		cout << endl;
	}
}

/*
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


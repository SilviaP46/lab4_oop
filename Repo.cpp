#include "Repo.h"
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;


vector<Medikament>c;
Repo::Repo() {}

bool Repo::add_Medikament(Medikament m) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == m.get_Name())
			return false;
	}
	medicine.push_back(m);
	return true;

	cout <<"ok";
}

void Repo::delete_Medikament(string name,float concentration) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == name && medicine.at(i).get_Concentration()==concentration) {
			medicine.erase(medicine.begin() + i);
			cout << "Medicine deleted!";
			return;
		}
	}
	cout << "Medicine does not exist.";
}


void Repo::update_Medikament(string name, float concentration,int p) {
	for (int i = 0; i < medicine.size(); i++) {
		if (medicine.at(i).get_Name() == name && medicine.at(i).get_Concentration()==concentration) {
			medicine.at(i).set_Price(medicine.at(i).get_Price() - p);
		}
	}
}
void Repo::Group()//group Medikament by price
{
	vector<Medikament>v;
	pair<double, string>p;
	vector<string>name = {};
	vector<double>price = {};

	//create 2 vectors and memorize the name and the price of each one
	Medikament temp;
	ifstream in("medikament.txt", ios::in);
	while (in >> temp.get_Name >> temp.get_Concentration >> temp.get_Price >> temp.get_Quantity)
		v.push_back(temp);//create a vector
	int k = 0;
	for (const auto& it : v)
	{
		name.push_back(it.get_Name);
		price.push_back(it.get_Price);
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

void Repo::RUndo()//functie ajutatoare pt Undo
{
	Medikament temp;
	ifstream in("medikament.txt", ios::in);
	while (in >> temp.get_Name >> temp.get_Concentration >> temp.get_Price >> temp.get_Quantity)
		c.push_back(temp);//create a vektor
}

void Repo::Undo()
{
	vector<Medikament>g;
	g = c;
	ofstream trunc("medikament.txt", ios::out);
	for (const auto& medi : g)
	{
		trunc << medi.get_Name << ' ' << medi.get_Concentration << ' ' << medi.get_Price << ' ' << medi.get_Quantity << ' ' << endl;
	}
	cout << "Undo/Redo was mad..." << endl;
	c = {};
}




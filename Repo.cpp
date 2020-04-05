#include "Repo.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;



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

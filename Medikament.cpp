#include "Medikament.h"
#include <iostream>
using namespace std;

Medikament::Medikament() {
	Name = "";
	Price = 0;
	Quantity = 0;
	Concentration = 0;
}

Medikament::Medikament(int quantity, float concentration, float price, string name) {
	Quantity = quantity;
	Concentration = concentration;
	Price = price;
	Name = name;
}


int Medikament::get_Quantity() const{

	return Quantity;

}

float Medikament::get_Concentration() const {

	return Concentration;

}

float Medikament::get_Price() const {

	return Price;

}

string Medikament::get_Name() const {

	return Name;

}

void Medikament::set_Quantity(int quantity) {

	this->Quantity = quantity;
}

void Medikament::set_Concentration(float concentration) {

	this->Concentration = concentration;
}

void Medikament::set_Price(float price) {

	this->Price = price;
}

void Medikament::set_Name(string name) {

	this->Name = name;
}


void Medikament::print()
{
	cout <<endl<< " Name: " << Name << " Concentration: " << Concentration << " Quantity: " << Quantity << " Price: " << Price << endl;
}
Medikament::~Medikament() {}




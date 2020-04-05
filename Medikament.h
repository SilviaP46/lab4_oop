#pragma once
#include <cstring>
#include <string>

using namespace std;

class Medikament {
private:
	int Quantity;
	float Concentration,Price;
	string Name;
public:

	Medikament();
	Medikament(int Quantity, float Concentration, float Price, string Name); //innit

	//getter
	int get_Quantity() const;
	float get_Concentration() const;
	float get_Price() const;
	string get_Name() const;

	//setter
	void set_Quantity(int Quantity);
	void set_Concentration(float Concentration);
	void set_Price(float Price);
	void set_Name(string Name);

	void print();


	~Medikament(); //destructor
};


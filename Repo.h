#pragma once
#include <vector>
#include<string>
#include "Medikament.h"
using namespace std;

class Repo{
	friend class Medikament;
	public:
	vector<Medikament> medicine;

	
public:
	Repo();
	int size_medicine() { return medicine.size(); }
	bool add_Medikament(Medikament m);
	void delete_Medikament(string name, float concentration);
	void update_Medikament(string name, float concentration,int p);
	void Group();
	void RUndo();
	void Undo();
	string get_Name();
	int get_Concentration();
	int get_Price();
	int get_Quantity();
	//nu stiu daca trebuie adugate astea de mai sus?P:)))

};


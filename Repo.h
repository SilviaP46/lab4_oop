#pragma once
#include <vector>
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

};


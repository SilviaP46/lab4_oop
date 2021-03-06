#pragma once
#include <vector>
#include<string>
#include "Medikament.h"
using namespace std;

class Repo{
	friend class Medikament;
	public:
	vector<Medikament> medicine;
	vector<Medikament> v;
	pair<double, string> p;
	vector<string> name = {};
	vector<double> price = {};
	vector<Medikament> c;

	
public:
	Repo();
	int size_medicine() { return medicine.size(); }
	bool add_Medikament(Medikament m);
	void delete_Medikament(string name, float concentration);
	void update_Medikament_Price(string name, float concentration,int p);
	void sort_by_string(Medikament m, string s);

	void Search(float c);
	void Group();
	//void RUndo();
	//void Undo();
	

};


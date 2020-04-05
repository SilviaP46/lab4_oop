#pragma once
#include "Repo.h"
#include <iostream>
#include <string>
#include <algorithm>
class Controller{
public:
	vector <Medikament> medicine;
public:
	Controller();
	void ui_menu(int choice, Repo* r, Medikament m);


};


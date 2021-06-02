#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
	: view(new View())
{
	repGens.push_back(new RegionRepGen());
	repGens.push_back(new YearRepGen());
	repGens.push_back(new AnimalRepGen());
}

Control::~Control(){
	for(int i = 0; i < repGens.size(); ++i){
		delete repGens[i];
	}
	
	delete view;
}

void Control::launch(){
	int choice;

	repGens[0]->getData();

	do{
		view->showMenu(choice);

		switch(choice){
			case 1:
				repGens[0]->compute();
				break;
			
			case 2:
				repGens[1]->compute();
				break;

			case 3:
				repGens[2]->compute();
				break;

			case 0:
				repGens[0]->cleanup();
				break;
		}

	} while(choice != 0);
}
#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 3;

  cout << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Compute most frequent caller" << endl;
  cout << "  (2) Compute most frequently called" << endl;
  cout << "  (3) Show all calls" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;

  while (choice < 0 || choice > numOptions) {
		if (choice == 0)
    	return;

    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}




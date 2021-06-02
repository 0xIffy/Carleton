#ifndef VIEW_H
#define VIEW_H

/*
	Purpose: An boundary class. Displays menu to user and handles user interaction.
*/

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
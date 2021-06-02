/*
	Purpose: Simulate a telephone company thta manages subscribers and their calls
	Usage: Run the makefile and the execute the binary file that gets created
	Author: Braeden Hall
	Student #: 101143403
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"

int main(){
	Control c("Bell");
	c.launch();
}
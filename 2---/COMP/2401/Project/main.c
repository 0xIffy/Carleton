#include "defs.h"

int main(){
	MapType *m = NULL;
	int choice;

	initMap(&m);
	if(!readData(m, "grad.dat")){
		printf("An error occured while reading data from the file, exiting.\n");
		return -1;
	}

	do{
		printMenu();
		scanf("%d", &choice);
		printf("\n");

		switch(choice){
			case 1:
				calcGradPctByDeg(m);
				break;

			case 2:
				calcFemaleGradPct(m);
				break;

			case 3:
				calcGradPctByYear(m, 2014, 2017);
				break;

			case 4:
				handleCase4(m);
				break;

			case 5:
				handleCase5(m);
				break;

			case 0:
				printf("Thank you, good bye.\n");
				freeMap(m);
				break;

			default:
				printf("Invalid input, try again...\n");
				break;
		}
	} while(choice != 0);
}
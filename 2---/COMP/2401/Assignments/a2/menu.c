#include <stdio.h>
#include "defs.h"


/*
	Purpose: print the menu of of options to the screen
			 in: N/A
	 return: N/A
*/
void printMenu(){
	printf("\t\t\tINVENTORY MANAGEMENT SYSTEM\n\n");
	printf("(1)\tPrint Inventory\n");
	printf("(2)\tAdd Product Stock\n");
	printf("(3)\tBuy Product\n");
	printf("(0)\tExit\n\n");

	printf("Please enter your choice: ");
}


/*
	Purpose: print the list of inventory products to the screen
			 in: a pointer to the store whose inventory will be printed
	 return: N/A
*/
void printInventory(InventoryType *store){
	if(store != NULL){
		ProductType p;

		printf("\n");
		printf("%s\n",store->name);
		for(int i = 0; i < store->products->numProducts; ++i){
			p = **(store->products->pArr+i);

			printf("-- Product #%d: %38s,  %2d units,  $%.2f\n",p.id,p.name,p.stock,p.price);
		}
		printf("\n");
	}
}

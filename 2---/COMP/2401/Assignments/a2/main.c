#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(){
	int choice;
	float totalPrice = 0;

	InventoryType *store = NULL;
	ProductType *p = NULL;

	if(initStore(&store)){
		do{
			printMenu();
			scanf("%d",&choice);

			switch(choice){
				case 1:
					printInventory(store);

					break;
				
				case 2:
					printf("Please input the id of the product you would like to restock: ");
					if(findProduct(store->products,&p)){
						restock(p);
					}

					break;

				case 3:
					printf("Please enter the id of the product you want to purchase: ");
					if(findProduct(store->products, &p)){
						printf("\n");
						buyProduct(p,&totalPrice);

						printf("Your current total is: $%.2f.\n\n",totalPrice);
					}

					break;

				case 0:
					printf("Your final total is: $%.2f.\n",totalPrice);
					freeAll(store);
					break;

				default:
					printf("Your choice was invalid.\n\n");
					break;
			}

		} while(choice != 0);
	} else{
		printf("Error loading store.\n");
	}

	return 1;
}
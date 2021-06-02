#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

/*
	Purpose: allocate memory for the store and initialize an instance of it with a name and products for the user to interact with
	 in/out: the address of a pointer to the store that will be initialized
	 return: 1 if the store is initialized correctly, 0 otherwise
*/
int initStore(InventoryType **store){
	if(store != NULL){
		*store = (InventoryType *) malloc(sizeof(InventoryType));

		if(*store != NULL){
			ProductType *p = NULL;
			
			strcpy((*store)->name,"Pokefiends V&M");
			
			if(initProductArr(&((*store)->products))){
				char *names[10] = {	
					"1st Edition Base Set PSA 10 Charizard",
					"1st Edition Base Set PSA 8 Blastoise",
					"1st Edition Base Set PSA 8 Venusaur",
					"Shadowless PSA 9 Red Cheeks Pikachu",
					"1st Edition PSA 10 Blaine's Arcanine",
					"Hidden Fates PSA 10 SV56 Greninja GX",
					"Hidden Fates PSA 9 SV75 Gardevoir GX",
					"1st Edition Team Rocket Booster Box",
					"Hidden Fates Charizard GX Tin",
					"Shining Legends Elite Trainer Box"
				};
				float prices[10] = {150000,11000,7000,6100,2500,120,50,11000,49.99,101.96};
				int units[10] = {1,3,6,11,4,15,25,2,30,21};

				for(int i =0; i < 10; ++i){
					if(createProduct(&p,names[i],prices[i],units[i])){
						addProduct(p,(*store)->products);
					} else{
						return 0;
					}
				}

				return 1;
			}

			printf("The product array could not be initialized properly.\n");
			return 0;
		}	
	}

	printf("Store could not be initialized.\n");
	return 0;
}

/*
	Purpose: allocate memory for the product array type and initialize it
	 in/out: the address of a pointer to the product array stored in the store type
	 return: 1 if the product array is initialized correctly, 0 otherwise
*/
int initProductArr(ProductArrType **products){
	if(products != NULL){
		*products = (ProductArrType *) malloc(sizeof(ProductArrType));

		if(*products != NULL){
			(*products)->numProducts = 0;
			(*products)->nextId = 1001;
			(*products)->pArr = (ProductType **) calloc(MAX_PRODUCTS,sizeof(ProductType));

			if((*products)->pArr == NULL){
				return 0;
			}

			return 1;
		}
	}

	return 0;
}

/*
	Purpose: allocate memory for a product type and create it with the given name, price and stock quantity
	 in/out: the address of a pointer to the product type to be created
	 		 in: the name of the product
			 in: the price of the product
			 in: the number of units in stock for the product
	 return: 1 if the store is initialized correctly, 0 otherwise
*/
int createProduct(ProductType **p,char *name,float price,int units){
	if(p != NULL){
		*p = (ProductType *) malloc(sizeof(ProductType));

		if(*p != NULL){
			strcpy((*p)->name,name);
			(*p)->price = price;
			(*p)->stock = units;

			return 1;
		}
	}

	printf("Error creating product.\n");
	return 0;
}

/*
	Purpose: add a product to the product array/list of inventory for the store being viewed
			 in: a pointer to the product to be added to the product array
	 in/out: a pointer to the product array of the store being viewed
	 return: N/A
*/
void addProduct(ProductType *p, ProductArrType *products){
	if(p != NULL && products != NULL){
		products->pArr[products->numProducts] = p;
		(products->pArr[products->numProducts])->id = products->nextId;
		products->numProducts +=1;
		products->nextId +=1;

		return;
	}
}

/*
	Purpose: prompt the user to enter the id of a product and search through the given product array for it
	 		 in: a pointer to the product array/list of inventory of the store being viewed
			out: the address of a pointer to the product in the array if found
	 return: 1 if the product is found in the list of inventory, 0 otherwise
*/
int findProduct(ProductArrType *products, ProductType **p){
	if(p != NULL && products != NULL){
		int choice;

		scanf("%d", &choice);

		for(int i = 0; i < products->numProducts; i++){
			if((products->pArr[i])->id == choice){
				*p = products->pArr[i];
				return 1;
			}
		}

		printf("\nSorry, that product does not exist in the inventory for this store.\n\n");
		return 0;
	}

	printf("\nCould not find product.\n\n");
	return 0;
}

/*
	Purpose: prompt the user to enter the amount of units to add to the given product and then increment the stock by that amount
	 in/out: a pointer to the product the units should be added to
	 return: N/A
*/
void restock(ProductType *p){
	if(p != NULL){
		int units;

		do{
			printf("How many units would you like to add? ");
			scanf("%d",&units);

			if(units <= 0){
				printf("Sorry, you must input a positive integer for units.\n");
			}
		}while(units <= 0);

		p->stock += units;
		printf("\nSuccess, %s now has %d units in stock.\n\n",p->name,p->stock);
	}
}

/*
	Purpose: decrement the stock of the given product by 1 and add the price of the product to the user's running total
	 in/out: a pointer to the product being 'bought'
	 		out: a pointer to the user's running total price
	 return: N/A
*/
void buyProduct(ProductType *p, float *total){
	if(p != NULL && total != NULL){
		if(p->stock >= 1){
			p->stock -= 1;
			*total += p->price;

			printf("You have purchased one %s.\n", p->name);
		} else{
			printf("\nSorry, that product is out of stock at the moment.");
		}
	}
}

/*
	Purpose: free all pointers to all memory that was dynamically allocated during the runtime of the program
			 in: a pointer to the store instance that was being used throughout the program
	 return: N/A
*/
void freeAll(InventoryType *store){
	if(store != NULL){
		for(int i = 0; i < store->products->numProducts; i++){
			free(store->products->pArr[i]);
		}
		free(store->products->pArr);
		free(store->products);
		free(store);
	}
}
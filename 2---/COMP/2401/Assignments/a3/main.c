#include "defs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(){
	ListType *calvinMovies = NULL, *hobbesMovies = NULL;
	ArrayType *arrayByTitle = NULL, *arrayByYear = NULL;

	// Initialize all required data structures
	if(initList(&calvinMovies) && initList(&hobbesMovies) && initArray(&arrayByTitle) && initArray(&arrayByYear)){

		//Add relevant data to both list data structures
		initAllMovies(calvinMovies,hobbesMovies);

		//Print the list data strcutures the first time
		printf("\tCalvin Movies:\n");
		printList(calvinMovies);
		printf("\n\n\tHobbes Movies:\n");
		printList(hobbesMovies);

		//Add data to the array data structures
		mergeMovies(BY_TITLE,arrayByTitle,calvinMovies,hobbesMovies);
		mergeMovies(BY_YEAR,arrayByYear,calvinMovies,hobbesMovies);

		//Print the list data strcutures the second time
		printf("\n\n\tCalvin Movies again:\n");
		printList(calvinMovies);
		printf("\n\n\tHobbes Movies again:\n");
		printList(hobbesMovies);

		//Print the array data
		printf("\n\n\tMovies by Title:\n");
		printArray(arrayByTitle);
		printf("\n\tMovies By Year:\n");
		printArray(arrayByYear);

		//Free all memory in the stack
		freeList(calvinMovies);
		freeList(hobbesMovies);
		freeAllMovies(arrayByTitle);
		freeArray(arrayByTitle);
		freeArray(arrayByYear);
	} else{
		printf("An error occured while initializing the required data structures.\nProgram ending.\n");
		return 1;
	}
}
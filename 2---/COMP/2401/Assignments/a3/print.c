#include "defs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
	purpose: print all the movie data in a given list both forwards then backwards as well as the data stored at the head and tail
	 		 in: the list structure for which data will be printed
	 return: N/A
*/
void printList(ListType *list){
	NodeType *curr;

	curr = list->head;

	printf("Forwards:\n");
	while(curr != NULL){
		printMovie(curr->data);
		
		curr = curr->next;
	}

	printf("\n\n");

	curr = list->tail;

	printf("Backwards:\n");
	while(curr != NULL){
		printMovie(curr->data);

		curr = curr->prev;
	}

	printf("\nList Head: ");
	printMovie(list->head->data);
	printf("List Tail: ");
	printMovie(list->tail->data);
}

/*
	purpose: print all the data for a given movie to the screen
	 		 in: the movie strcuture for which data will be printed
	 return: N/A
*/
void printMovie(MovieType *m){
	printf("Movie #%02d: %-35s\tYear: %d\n",m->id,m->title,m->year);
}

/*
	purpose: print all the movie data in a given array forwards
	 		 in: the array structure for which data will be printed
	 return: N/A
*/
void printArray(ArrayType *arr){
	for(int i = 0; i < arr->size; i++){
		printMovie(arr->elements[i]);
	}
}
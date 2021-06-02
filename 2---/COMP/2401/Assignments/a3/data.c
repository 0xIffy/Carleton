#include "defs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void addMovieToList(SortType s, ListType *list, MovieType *m){
	NodeType *curr, *prev;

	curr = list->head;
	prev = NULL;

	if(s == BY_TITLE){
		while(curr != NULL){
			if(strcmp(curr->data->title,m->title) > 0){
				break;
			}

			prev = curr;
			curr = curr->next;
		}
	} else if(s == BY_YEAR){
		while(curr != NULL){
			if(m->year < curr->data->year){
				break;
			}

			prev = curr;
			curr = curr->next;
		}
	} else{
		printf("Invalid sort type provided.\nReturning...\n");
		return;
	}

	if(!addNode(list,prev,curr,m)){
		printf("Error adding node to list, list id not incremented.\nReturning...\n");
		return;
	}

	if(m->id == -1){
		m->id = list->nextId;
		list->nextId++;
	}
}

/*
	purpose: add a node to the given list structure btween the given nodes
	 in/out: the list structure the node will be added to
	 	 	 in: the node the new node will be added after
			 in: the node the new node will be added before
			 in: the movie data to be stored in the node
	 return: 1 if the node is added correctly and 0 otherwise
*/
int addNode(ListType *list, NodeType *prev, NodeType *next, MovieType *m){
	NodeType *n = NULL;
	n = (NodeType *) malloc(sizeof(NodeType));

	if(n == NULL)
		return C_FALSE;

	n->data = m;
	n->next = NULL;
	n->prev = NULL;

	if(prev == NULL)
		list->head = n;
	else{
		if(next == NULL)
			list->tail = n;
		else
			next->prev = n;
			
		prev->next = n;
	}

	n->prev = prev;
	n->next = next;

	return C_TRUE;
}

void mergeMovies(SortType s, ArrayType *arr, ListType *l1, ListType *l2){
	ListType *orderedList = NULL;
	NodeType *curr = l1->head != NULL ? l1->head : l2->head;

	initList(&orderedList);

	while(curr != NULL){
		addMovieToList(s,orderedList,curr->data);

		curr = curr != l1->tail ? curr->next : l2->head;
	}

	curr = orderedList->head;

	while(curr != NULL){
		if(!addMovieToArray(arr,curr->data))
			break;

		curr = curr->next;
	}

	if(curr != NULL){
		printf("Error occured while generating array.\nReturning...\n");
		return;
	}

	freeList(orderedList);
}

/*
	purpose: create a new array with the new movie data and store in the given array structure
	 in/out: the array structure to be chagned
	 		 in: the movie data to be appended
	 return: 1 if the created and stored correctly and 0 otherwise
*/
int addMovieToArray(ArrayType *arr, MovieType *m){
	MovieType **newArr = NULL;
	int i;

	newArr = calloc(arr->size + 1, sizeof(MovieType*));

	if(newArr == NULL)
		return C_FALSE;

	for(i = 0; i < arr->size; i++){
		newArr[i] = arr->elements[i];
	}

	newArr[i] = m;

	free(arr->elements);
	arr->elements = newArr;
	(arr->size)++;

	return C_TRUE;
}

/*
	purpose: free the memory for all the nodes stored in a list as well as the list itself
	 in/out: the list structure to be freed
	 return: N/A
*/
void freeList(ListType *list){
	NodeType *curr = list->head, *prev = NULL;

	while(curr != NULL){
		prev = curr;
		curr = curr->next;
		free(prev);
	}

	free(list);
}

/*
	purpose: free the memory for all movie structures used in the program
	 in/out: an array structure containing all movie structures
	 return: N/A
*/
void freeAllMovies(ArrayType *arr){
	for(int i = 0; i < arr->size; i++){
		free(arr->elements[i]);
	}
}

/*
	purpose: free the memory for an array structure
	 in/out: the array structure to be freed
	 return: N/A
*/
void freeArray(ArrayType *arr){
	free(arr->elements);
	free(arr);
}
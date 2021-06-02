/*
FILE IS main2D.c

Purpose:
a. Practice memory allocation of a 2D array and populating it.

Description:
See tutorial notes

History:
20/1/2018 Doron Nussbaum modified the file

2018 copyright Doron Nussbaum

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


// #define DIM_1   10 
// #define DIM_2    5 



int main(int argc, char **argv)

{

    int i,j;
    int count = 0;
    int rc = 0; 
    int **arr = NULL;

		int DIM_1, DIM_2;

		if(argc == 3){
			DIM_1 = atoi(argv[1]);
			DIM_2 = atoi(argv[2]);
		} else if(argc > 3){
			printf("Too many arguments supplied.\n");
			return 1;
		} else{
			printf("Not enough arguments were supplied.\n");
			return 1;
		}

    
    // allocate memory for the arrray of pointers to int array
    // the array has to have DIM_1 elements where each element is an int *
    // add code
    //
		arr = (int**) malloc(DIM_1*sizeof(int*));
    
		if(arr == NULL)
			return 1;

    // initialize the pointers to NULL
		for(int i = 0; i < DIM_1; i++){
			arr[i] = NULL;
		}
    
        
    
    // allocate memory for each element in the array arr
    // each element should contains the address of a 1D array of DIM_2 elements each of type int 
    
		for(int i = 0; i < DIM_1; i++){
			// allocate memory for arr[i]
			// check if the memory was allocated
			arr[i] = (int*) malloc(DIM_2*sizeof(int));
			if(arr[i] == NULL)
				return 1;
		}

    
    // populate the array (using 2 for loops) 

	// outer loop of size DIM_1
			// inner loop of size DIM_2
				  // set array element to count
				  //  increment count by 1
   
    // add code 
		for(int i = 0; i < DIM_1; i++){
			for(int j = 0; j <DIM_2; j++){
				arr[i][j] = count;
				count++;
			}
		}

    // print the array  (using 2 for loops)
		for(int i = 0; i < DIM_1; i++){
			printf("[");
			for(int j = 0; j <DIM_2; j++){
				printf("%02d,",arr[i][j]);
			}
			printf("],\n");
		}
    //  Add code
    

		for(int i = 0; i < DIM_1; i++){
			free(arr[i]);
		}
		free(arr);

    return(0);
}




/* file is bit_functions.c 
Purpose: helper functions for bit manipulation

*/

#include "bit_functions.h"

/*
  Function:  isBitset
  Purpose:   checks if bit in position bitNum of the character c is set to 1
       in:   character to be checked
       in:   the bit position position to be checked
   return:   1 if the bits is set, 0 if the bit is not set
*/
int isBitSet(unsigned char c, int bitNum) 
{
	return ((c & (1 << bitNum)) >> bitNum);
}


/***************************************************************/


/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int bitNum) 
{
	return (c | (1 << bitNum));
}


/***************************************************************/


/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/

unsigned char clearBit(unsigned char c, int bitNum) 
{
	return (c & (~(1 << bitNum)));
}


/***************************************************************/

/*
Function: printBitsIterative
Purpose: prints the bits of the the character using an iterative method 
input: a character whose bits must be printed
return: none
*/

void printBitsIterative(unsigned char c) 
{
	for(int i = 7; i >= 0; i--){
		printf("%d",isBitSet(c,i));
	}
	printf("\n");
}

/***************************************************************/


/*
Function: printBitsRecursive
Purpose: prints the bits of the the character using a recurive method
input: a character whose bits must be printed
return: none
*/

void printBitsRecursive(unsigned char c) 
{
	if(c == 0){
		printf("\n");
		return;
	}

	printf("%d",isBitSet(c,0));

	printBitsRecursive((c >> 1));
}


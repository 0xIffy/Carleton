#include <stdio.h>
#include <string.h>

#define MAX_BUF  		 256
#define INIT_KEY 		 0b10110110
#define INIT_COUNTER 0b01010101

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char processCounter(unsigned char, unsigned char);
unsigned char processSrc(unsigned char, unsigned char);
unsigned char xorByte(unsigned char, unsigned char, unsigned char, int);


int main()
{
  char str[8];
  int  choice;

	char message[MAX_BUF];
	unsigned char key = INIT_KEY;
	unsigned char counter = INIT_COUNTER;
	unsigned char byte;

	while(1){

		printf("\nYou may:\n");
		printf("  (1) Encrypt a message \n");
		printf("  (2) Decrypt a message \n");
		printf("\n  what is your selection: ");
		fgets(str, sizeof(str), stdin);
		sscanf(str, "%d", &choice);

		switch (choice) {
			case 1:
				printf("Please input the message you would like to encrypt: \n");
				fgets(message, sizeof(message), stdin);

				printf("Encrypted message: ");

				for(int i = 0; i < strlen(message) - 1; i++){
					counter = processCounter(key,counter);
					counter += 1;
					key += 1;

					printf("%d ",processSrc(counter,message[i]));
				}
				printf("\n");

				break;

			case 2:
				printf("Please input the message you would like decrypted followed by -1: \n");
				scanf("%d",&choice);

				while(choice != -1){
					if(choice <= 255){
						byte = choice;

						counter = processCounter(key,counter);
						counter += 1;
						key += 1;

						printf("%c",processSrc(counter,byte));

					} else{
						printf("The ciphertext you input contains a value greater than 255. This is value can not be processed by this alogorithm.\n");
						printf("The program is being terminated. Good bye.\n\n");
						return 0;
					}

					scanf("%d",&choice);
				}

				printf("\n");

				break;

			default:
				printf("\nInvalid choice. Please try again.\n");
				continue;
		}
		break;
  }

  return 0;
}

/*
	Function: xorByte
	Purpose: 	either set or clear a bit in the byte currently being processed based on the result of the xor operation performed of 2 bits
			 in:	the character in which a bit will be cleared or set
			 in:	first bit to be used in the xor operation
			 in:	second bit to be used in the xor operation
			 in:	the position of the bit that will be changed in the character
	 Return:	new value of the character with the bit either set or cleared
*/
unsigned char xorByte(unsigned char byte, unsigned char bit1, unsigned char bit2, int n)
{
	unsigned char xorBit;

	xorBit = (bit1 ^ bit2);

	return xorBit ? setBit(byte,n) : clearBit(byte,n);
}

/*
	Function:	processCounter
	Purpose:	process the counter value using the key value
			 in:	the key value used to process the counter
			 in:	the counter value to be processed
	 Return:	the new counter value after being processed
*/
unsigned char processCounter(unsigned char key, unsigned char counter)
{
	unsigned char bit1, bit2;
	int pos1, pos2;

	for(int i = 7; i >= 0; i--){
		pos1 = i;
		
		if(getBit(key,i)){
			pos2 = i + 1;
		} else{
			pos2 = i + 2;
		}
		pos2 = pos2 <= 7 ? pos2 : pos2 - 8;

		bit1 = getBit(counter,pos1);
		bit2 = getBit(counter,pos2);

		counter = xorByte(counter,bit1,bit2,i);
	}

	return counter;
}

/*
	Function:	processSrc
	Purpose:	process the source byte using the counter value
			 in:	the couter value used to process the source
			 in:	the source byte to be processed
	 Return:	the new value of the source byte after being processed
*/
unsigned char processSrc(unsigned char counter, unsigned char srcByte)
{
	unsigned char bit1, bit2;
	int modCounter = counter % 9;

	if(modCounter < 3){
		for(int i = 0; i < 8; i+=2){
			bit1 = getBit(counter,i);
			bit2 = getBit(srcByte,i);

			srcByte = xorByte(srcByte,bit1,bit2,i);
		}
	} else if(modCounter >= 3 && modCounter <= 5){
		for(int i = 1; i < 8; i+=2){
			bit1 = getBit(counter,i);
			bit2 = getBit(srcByte,i);

			srcByte = xorByte(srcByte,bit1,bit2,i);
		}
	} else{
		for(int i = 0; i < 8; i++){
			bit1 = getBit(counter,i);
			bit2 = getBit(srcByte,i);

			srcByte = xorByte(srcByte,bit1,bit2,i);
		}
	}

	return srcByte;
}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)   
{ 
	unsigned char bit = 1 << n;

	return (c & bit) >> n;
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)   
{ 
	unsigned char bit = 1 << n;

	return c | bit;
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n) 
{ 
	unsigned char bit = 1 << n;

	return c & (~bit);
}

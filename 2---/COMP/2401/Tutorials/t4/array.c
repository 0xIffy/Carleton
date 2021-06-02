#include <stdio.h>

int main() {
  int    array1[5];
  float  array2[3];
  double array3[6];
  char   array4[10];
	int rowSum[3] = { 0, 0, 0};

  printf("The size of int is %lu\n",    sizeof(int));     //  4
  printf("The size of float is %lu\n",  sizeof(float));   //  4 
  printf("The size of double is %lu\n", sizeof(double));  //  8
  printf("The size of char is %lu\n\n", sizeof(char));    //  1
  
  printf("The size of array1 is %lu\n",   sizeof(array1)); //  5*4 = 20
  printf("The size of array2 is %lu\n",   sizeof(array2)); //  3*4 = 12
  printf("The size of array3 is %lu\n",   sizeof(array3)); //  6*8 = 48
  printf("The size of array4 is %lu\n\n", sizeof(array4)); // 10*1 = 10

  
  for (int i=0; i<sizeof(array1)/sizeof(int); i++){
		array1[i] = i*3; 
    printf("%d, ", array1[i]);
	}
  printf("\n");
  
  for (int i=0; i<sizeof(array2)/sizeof(float); i++){
		array2[i] = (float) i + 0.101;
    printf("%f, ", array2[i]);
	}
  printf("\n");
  
  for (int i=0; i<sizeof(array3)/sizeof(double); i++){ 
		array3[i] = (double) i + 0.12301;
    printf("%g, ", array3[i]);
	}
  printf("\n");
  
  for (int i=0; i<sizeof(array4)/sizeof(char); i++){
		array4[i] = i+97; 
    printf("%c, ", array4[i]);
	}
  printf("\n\n");


  int array2D[3][4] = { {1,  2,  3,  4},
                        {5,  6,  7,  8},
                        {9, 10, 11, 12} };
  
  printf("The size of array2D is %lu \n", sizeof(array2D));
  printf("The #elements in array2D is %lu \n", sizeof(array2D)/sizeof(int));
  printf("The #elements in each row of array2D is %lu \n", sizeof(array2D[0])/sizeof(int));
  printf("The #rows of array2D is %lu \n", sizeof(array2D)/sizeof(array2D[0]));
  
  for (int i=0; i<3; i++) {
    for (int j=0; j<4; j++){
      printf("%02d ", array2D[i][j]);
			rowSum[i] += array2D[i][j];
		}
    printf("\n");
  }
	printf("\n");
	for(int i = 0; i<3; i++){
		printf("The sum of row %d is %d\n",i+1,rowSum[i]);
	}
  
  printf("\n\n\n");
  
  int cube[4][4][4] = {	{{1,  2,  3,  4},
			 {5,  6,  7,  8},
			 {9, 10, 11, 12},
 			 {13, 14, 15, 16}},
			{{17, 18, 19, 20},
			 {21, 22, 23, 24},
			 {25, 26, 27, 28},
 			 {29, 30, 31, 32}},
			{{33, 34, 35, 36},
			 {37, 38, 39, 40},
			 {41, 42, 43, 44},
 			 {45, 46, 47, 48}},
			{{49, 50, 51, 52},
			 {53, 54, 55, 56},
			 {57, 58, 59, 60},
 			 {61, 62, 63, 64}} };

  int rows = sizeof(cube)/sizeof(cube[0]);
  int cols = sizeof(cube[0])/sizeof(cube[0][0]);
  int depth = sizeof(cube)/(rows*cols*sizeof(int));
  
  printf("Cube has %d rows\n", rows);
  printf("Cube has %d columns\n", cols);
  printf("Cube has %d layers\n", depth);
  
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols; c++) {
      for (int d=0; d<depth; d++)
	printf("%02d ", cube[r][c][d]);
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}


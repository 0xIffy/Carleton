#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_1   16
#define MAX_STR_2   32
#define MAX_ARR     64
#define C_OK         0
#define C_NOK       -1

typedef struct {
	int hours;
	int minutes;
	int seconds;
} TimeType;

typedef struct {
	char name[MAX_STR_2];
	int age;
	TimeType finishTime;
} RunnerType;

typedef struct {
  int size;
  RunnerType* elements[MAX_ARR];
} ArrayType;

void initArray(ArrayType*);
void addRunner(ArrayType*, RunnerType*);
void selectBest(ArrayType*, ArrayType*, int, int, int);
void initRunner(char*, int, int, int, int, RunnerType*);
void printArray(ArrayType*);
void printRunner(RunnerType*);

int main()
{
  ArrayType runners, bestRunners;
  RunnerType* newRunner;
  int  num1, num2, num3, num4;
  char str[MAX_STR_1];

  initArray(&runners);
  initArray(&bestRunners);

  while(1) {
    printf("Enter runner name, age, finish time hours, minutes, and seconds:  ");
    scanf("%s %d %d %d %d", str, &num1, &num2, &num3, &num4);
    if (strcmp(str, "-1") == 0)
      break;
    newRunner = malloc(sizeof(RunnerType));
    initRunner(str, num1, num2, num3, num4, newRunner);
    addRunner(&runners, newRunner);
  }

  printf("Enter age and cut-off time (hours and minutes):  ");
  scanf("%d %d %d", &num1, &num2, &num3);
  selectBest(&runners, &bestRunners, num1, num2, num3);

  printf("\n\nALL RUNNERS:");
  printArray(&runners);

  printf("\n\nBEST RUNNERS:");
  printArray(&bestRunners);

  return(0);
}

/*
  Purpose:  initialize an array structure
*/
void initArray(ArrayType *a) { a->size = 0; }

/*
  Purpose:  populate newArr with all runners from orgArr who are
            younger than the given age, and have a finish time less
            than the time represented by the given hours and minutes
			 in:	pointer to the array of all runners
	 in/out:	pointer to the array runners that meet the given constraints
	 		 in:	age constraint to be applied
			 in:	hour value of the time constaint
			 in:	minute value of the time constraint
*/
void selectBest(ArrayType *orgArr, ArrayType *newArr, int a, int h, int m)
{
	RunnerType *r;
	for(int i = 0; i < orgArr->size; i++){
		r = orgArr->elements[i];
		if(r->age < a && (r->finishTime.hours  < h || (r->finishTime.hours == h && r->finishTime.minutes < m))){
			addRunner(newArr, r);
		}
	}
}

/*
  Purpose:  add a runner structure to the back of the array
*/
void addRunner(ArrayType *arr, RunnerType *newRunner)
{
  if (arr->size >= MAX_ARR)
    return;

  arr->elements[arr->size] = newRunner;
  ++(arr->size);
}

/*
  Purpose:  initialize a runner structure with the given parameters
			 in:	name of the runner
			 in:	age of the runner
			 in:	hours of the finish time of the runner
			 in:	minutes of the finish time of the runner
			 in: 	seconds of the finish time of the runner
	 in/out:	pointer to the runner structure being initialized
*/
void initRunner(char *n, int a, int h, int m, int s, RunnerType *newRunner)
{
	TimeType t;

	t.hours = h;
	t.minutes = m;
	t.seconds = s;

	strcpy(newRunner->name,n);
	newRunner->age = a;
	newRunner->finishTime = t;
}


/*
  Purpose:  print all information for the given runner
*/
void printRunner(RunnerType *r)
{
  printf("%10s, age %2d, finish time: %2d:%2d:%2d\n", r->name, r->age,
         r->finishTime.hours, r->finishTime.minutes, r->finishTime.seconds);

}


/*
  Purpose:  print out all the runners in a given array
*/
void printArray(ArrayType *arr)
{
  int i;

  printf("\n");

  for (i=0; i<arr->size; ++i)
    printRunner(arr->elements[i]);
}

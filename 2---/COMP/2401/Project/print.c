#include "defs.h"

/*
	purpose: pirnt the menu for the user to see
	 return: N/A
*/
void printMenu(){
	char reports[NUM_REPORTS][MAX_STR] = {"Graduate Percentage By Degree", "Top/Bottom 5 Countries For Percentage of Female Grads", "Graduate Percentage By Year 2014-2017", "Top/Bottom 5 Countries For Number of Grads", "Sample Standard Deviation Per Degree"};

	for(int i = 0; i < NUM_REPORTS; i++){
		printf("%d: %s\n", i+1, reports[i]);
	}
	printf("0 to quit\n\n");

	printf("Please select the report you wolud like to view: \t");
}

/*
	purpose: pirnt the options for different degrees and allow the user to choose a degree
			out: a pointer to the enum type to represent degree chosen
	 return: N/A
*/
void chooseDegree(DegreeNum *deg){
	int choice;

	char options[NUM_DEGS + 1][MAX_STR] = {"Bachelor's", "Master's", "Doctorate", "All"};
	do{
		for(int i = 0; i < NUM_DEGS + 1; i++){
			printf("%d: %s\n", i+1, options[i]);
		}

		printf("Please select the deegree you wolud like to sort grads by: \t");

		scanf("%d", &choice);

		switch (choice){
			case 1:
				*deg = L6;
				return;
			case 2:
				*deg = L7;
				return;
			case 3:
				*deg = L8;
				return;
			case 4:
				*deg = ALL;
				return;
			default:
				printf("\nInvalid opition selected, try agin...\n\n");
				break;
		}
	} while(1);
}

/*
	purpose: prints the data for the first report to the screen
			 in: an array of country names
			 in: a 2 dimentional array containing the sums for each degree for each country
			 in: an array of the total sums for each degree
			 in: the total number of countries
	 return: N/A
*/
void printGradPctByDeg(char ctryNames[][MAX_STR], int ctrySums[][NUM_DEGS + 1], int *totalSums, int numCtrys){
	printf("+---------------+------------+------------+------------+------------+\n");
	printf("|%-15s|%12s|%12s|%12s|%12s|\n","Country","Bachelor's %","Master's %","Doctorate %","Total %");
	printf("+---------------+------------+------------+------------+------------+\n");

	for(int i = 0; i < numCtrys; i++){
		printf("|%-15s|", ctryNames[i]);
		for(int j = 0; j < NUM_DEGS + 1; j++){
			printf("%12.1f|", (float) ctrySums[i][j]/totalSums[j] * 100);
		}
		printf("\n+---------------+------------+------------+------------+------------+\n");
	}

	printf("\n\n");
}

/*
	purpose: prints the data for the third report to the screen
			 in: an array of country names
			 in: a 2 dimentional array containing the sums for each year in the range beg-end for each country
		 	 in: an array of the total sums for each year in the range beg-end
			 in: the total number of countries
			 in: the first year of the range
			 in: the last year of the range
	 return: N/A
*/
void printGradPctByYear(char ctryNames[][MAX_STR], int ctrySums[][4], int *totalSums, int numCtrys, int beg, int end){
	printf("+---------------+----+----+----+----+\n");
	printf("|%-15s|","Country");
	for(int i = beg; i <= end; i++)
		printf("%4d|",i);

	printf("\n+---------------+----+----+----+----+\n");

	for(int i = 0; i < numCtrys; i++){
		printf("|%-15s|", ctryNames[i]);
		for(int j = beg; j <= end; j++){
			printf("%4.1f|", (float) ctrySums[i][j - beg]/totalSums[j - beg] * 100);
		}
		printf("\n+---------------+----+----+----+----+\n");
	}
	printf("\n\n");
}

/*
	purpose: prints the data for the second report to the screen
			 in: an array of pointers to data nodes that contain the country name and female grad percentage for each country
			 in: the total number of countries
	 return: N/A
*/
void printFemaleGradPct(VariableNodeType *pcts[], int numCtrys){
	printf("Top 5:\n");
	printf("+---------------+--------------+\n");
	printf("|%-15s|%-14s|\n","Country", "% Female Grads");
	printf("+---------------+--------------+\n");

	for(int i = numCtrys - 1; i > numCtrys - 6; i--){
		printf("|%-15s|%14.1f|\n", pcts[i]->country, (*(float*) (pcts[i]->data)));
		printf("+---------------+--------------+\n");
	}
	printf("\n\n");

	printf("Bottom 5:\n");
	printf("+---------------+--------------+\n");
	printf("|%-15s|%-14s|\n","Country", "% Female Grads");
	printf("+---------------+--------------+\n");

	for(int i = 0; i < 5; i++){
		printf("|%-15s|%14.1f|\n", pcts[i]->country, (*(float*) (pcts[i]->data)));
		printf("+---------------+--------------+\n");
	}
	printf("\n\n");
}

/*
	purpose: prints the data for the fourth report to the screen
			 in: an array of pointers to data nodes that contain the country name and total grads for each country
			 in: the total number of countries
			 in: the enum type representing the degree the data relates to
	 return: N/A
*/
void printNumGrads(VariableNodeType *arr[], int numCtrys, DegreeNum deg){
	char degree[12];
	char title[MAX_STR];

	getDegree(deg, degree);

	sprintf(title, "%s %s:\n", "Top 5 for", degree);

	printf("\n%s",title);
	printf("+---------------+---------------+\n");
	printf("|%-15s|%-15s|\n","Country", "Number of Grads");
	printf("+---------------+---------------+\n");

	for(int i = numCtrys - 1; i > numCtrys - 6; i--){
		printf("|%-15s|%15.1d|\n", arr[i]->country, (* (int*) (arr[i]->data) ));
		printf("+---------------+---------------+\n");
	}
	printf("\n\n");

	sprintf(title, "%s %s:\n", "Bottom 5 for", degree);

	printf("%s",title);
	printf("+---------------+---------------+\n");
	printf("|%-15s|%-15s|\n","Country", "Number of Grads");
	printf("+---------------+---------------+\n");

	for(int i = 0; i < 5; i++){
		printf("|%-15s|%15d|\n", arr[i]->country, (* (int*) (arr[i]->data) ));
		printf("+---------------+---------------+\n");
	}
	printf("\n\n");
}

/*
	purpose: prints the data for the fftht report to the screen
			 in: an array of averages for each country
			 in: an array of pointers to data nodes that contain the country names and stadard deviations for each country
			 in: the total number of countries
			 in: the enum type representing the degree the data relates to
	 return: N/A
*/
void printStdDev(double mean[], VariableNodeType *arr[], int numCtrys, DegreeNum deg){
	char degree[12];
	char title[MAX_STR];

	getDegree(deg, degree);

	sprintf(title, "%s %s:\n", "Standard Deviation for", degree);

	printf("\n%s",title);
	printf("+---------------+---------+---------+\n");
	printf("|%-15s|%-9s|%-9s|\n","Country", "Average", "Standard");
	printf("|%-15s|%-9s|%-9s|\n","       ", "Num Grads", "Deviation");
	printf("+---------------+---------+---------+\n");

	for(int i = 0; i < numCtrys; i++){
		printf("|%-15s|%9.1lf|%9.1lf|\n", arr[i]->country, mean[i], (* (double*) (arr[i]->data) ));
		printf("+---------------+---------+---------+\n");
	}
	printf("\n\n");
}

/*
	purpose: writes the proper degree title to a string
			 in: the enum type representing the degree
			out: a string for the degree title based on the enum number
	 return: N/A
*/
void getDegree(DegreeNum deg, char *degree){
	if(deg == L6){
		strcpy(degree, "Bachelor's");
	} else if(deg == L7){
		strcpy(degree, "Master's");
	} else if(deg == L8){
		strcpy(degree, "Doctorate");
	} else if(deg == ALL){
		strcpy(degree, "all degrees");
	}
}
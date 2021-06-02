#include "defs.h"

/*
	purpose: add the given list node to the given list
			 in: a pointer to the list node to add
	 in/out: a pointer to the list the node will be added to
	 return: N/A
*/
void addListNode(ListNodeType *n, ListType *l){
	ListNodeType *curr, *prev;

	curr = l->head;
	prev = NULL;

	while(curr != NULL){
		if(curr->data->year > n->data->year)
			break;

		prev = curr;
		curr = curr->next;
	}

	if(prev == NULL)
		l->head = n;
	else{
		if(curr == NULL)
			l->tail = n;
		else
			curr->prev = n;
			
		prev->next = n;
	}

	n->prev = prev;
	n->next = curr;
}

/*
	purpose: initialize a map node with the given list and key and add it to the map
	 in/out: the address of a pointer to the map node to be initialized
	 in/out: a pointer to the map the node will be added to
	 		 in: a pointer to the list that the node will contain
			 in: the key the node will have as a string
	 return: 1 if the data is read successfully, 0 otherwise
*/
int addMapNode(MapNodeType **n, MapType *m, ListType *l, char *key){
	if(!initMapNode(n, l, key))
		return C_FALSE;

	if(m->tail == NULL)
		m->head = *n;
	else
		m->tail->next = *n;

	m->tail = *n;
	m->size++;

	return C_TRUE;
}

/*
	purpose: read the data from the given file and add it into the given map
	 in/out: a pointer to the map that the data will be stored in
	 		 in: the name of the file to be read
	 return: 1 if the data is read successfully, 0 otherwise
*/
int readData(MapType *m, char* fileName){
	FILE *infile;
	char ctryCode[CTRY_CODE_LENGTH];
	char ctryName[MAX_STR];
	char gender[GND_STR];
	char degree[DEG_STR];
	int year;
	int numGrads;

	RecordType *r;
	ListType *l;
	ListNodeType *ln;

	MapNodeType *mn;

	infile = fopen(fileName, "r");
	if(!infile){
		printf("Error: could not open file.\n");
		exit(1);
	}

	while(1){
		fscanf(infile, "%s %s %s %s %d %d", ctryCode, ctryName, gender, degree, &year, &numGrads);

		if(feof(infile))
			break;
			
		r = NULL;
		l = NULL;
		ln = NULL;

		if(!initRecord(&r, ctryCode, ctryName, gender, degree, year, numGrads))
			return C_FALSE;

		mn = m->head;
		while(mn != NULL){
			if(strcmp(mn->key, ctryCode) == 0)
				break;
			
			mn = mn->next;
		}

		if(!initListNode(&ln, r))
			return C_FALSE;
			
		if(mn == NULL){
			if(!initList(&l, ctryCode))
				return C_FALSE;

			if(!addMapNode(&mn, m, l, l->countryCode))
				return C_FALSE;

			addListNode(ln, l);
			mn->begRange = year;
			mn->endRange = year;
		} else{
			addListNode(ln, mn->list);
			if(year > mn->endRange)
				mn->endRange = year;
			else if(year < mn->begRange)
				mn->begRange = year;
		}		
	}

	fclose(infile);

	return C_TRUE;
}

/*
	purpose: sum the total grads for each country for a given degree of all degrees
			 in: a pointer to the map that stores all of the data
	 in/out: an array of data node pointers that store the sums for each country
	 		 in: an enum type representing the degree of interest
	 in/out: a pointer to an array that will store sums, passed so that it can be free'd at the end of the calling function
	 return: 1 if the function was succeful, 0 otherwise
*/
int calcNumGrads(MapType *m, VariableNodeType *arr[], DegreeNum deg, int **sum){
	char degree[DEG_STR];
	MapNodeType *mn = m->head;;
	ListNodeType *ln;
	VariableNodeType *s;
	int mNodeCount = 0;

	*sum = (int*) calloc(m->size, sizeof(int));

	if(*sum == NULL)
		return C_FALSE;

	if(deg == L6){
		strcpy(degree, "L6");
	} else if(deg == L7){
		strcpy(degree, "L7");
	} else if(deg == L8){
		strcpy(degree, "L8");
	}
	
	while(mn != NULL){
		s = NULL;

		ln = mn->list->head;
		if(!initVariableNode(&s, ln->data->countryName, "int"))
			return C_FALSE;

		(*sum)[mNodeCount] = 0;

		while(ln != NULL){
			if(strcmp(ln->data->gender, "T") == 0){
				if(deg == ALL){
					(*sum)[mNodeCount] += ln->data->numGrads;
				} else if(strcmp(ln->data->degree, degree) == 0){
					(*sum)[mNodeCount] += ln->data->numGrads;
				}
			}

			ln = ln->next;
		}

		s->data = &((*sum)[mNodeCount]);

		arr[mNodeCount] = s;

		mn = mn->next;
		mNodeCount++;
	}

	return C_TRUE;
}

/*
	purpose: sum the total grads for each degree per country as well as for all countries and pass the data to the printing function
			 in: a pointer to the map that stores all of the data
	 return: N/A
*/
void calcGradPctByDeg(MapType *m){
	int ctrySums[m->size][NUM_DEGS+1];
	MapNodeType *mn = m->head;;
	ListNodeType *ln;
	char ctrys[m->size][MAX_STR];
	int mNodeCount = 0;
	int sums[NUM_DEGS + 1];

	for(int i = 0; i < NUM_DEGS + 1; i++){
		sums[i] = 0;
	}
	
	while(mn != NULL){
		for(int i = 0; i < NUM_DEGS + 1; i++){
			ctrySums[mNodeCount][i] = 0;
		}

		ln = mn->list->head;
		strcpy(ctrys[mNodeCount], ln->data->countryName);

		while(ln != NULL){
			if(strcmp(ln->data->gender, "T") == 0){
				if(strcmp(ln->data->degree, "L6") == 0){
					ctrySums[mNodeCount][0] += ln->data->numGrads;
					sums[0] += ln->data->numGrads;
				} else if(strcmp(ln->data->degree, "L7") == 0){
					ctrySums[mNodeCount][1] += ln->data->numGrads;
					sums[1] += ln->data->numGrads;
				} else if(strcmp(ln->data->degree, "L8") == 0){
					ctrySums[mNodeCount][2] += ln->data->numGrads;
					sums[2] += ln->data->numGrads;
				}

				ctrySums[mNodeCount][3] += ln->data->numGrads;
				sums[3] += ln->data->numGrads;
			}

			ln = ln->next;
		}

		mn = mn->next;
		mNodeCount++;
	}

	printGradPctByDeg(ctrys,ctrySums,sums,m->size);
}

/*
	purpose: sum the total grads for each year in the range beg to end per each country as well as for all countries and pass the data to the printing function
			 in: a pointer to the map that stores all of the data
			 in: the beginnig year for the range
			 in: the end year for the range
	 return: N/A
*/
void calcGradPctByYear(MapType *m, int beg, int end){
	int ctrySums[m->size][end - beg + 1];
	MapNodeType *mn = m->head;;
	ListNodeType *ln;
	char ctrys[m->size][MAX_STR];
	int mNodeCount = 0;
	int sums[end - beg + 1];


	for(int i = 0; i < end - beg + 1; i++){
		sums[i] = 0;
	}
	
	while(mn != NULL){
		for(int i = 0; i < end - beg + 1; i++){
			ctrySums[mNodeCount][i] = 0;
		}

		ln = mn->list->head;
		strcpy(ctrys[mNodeCount], ln->data->countryName);

		while(ln != NULL){
			if(strcmp(ln->data->gender, "T") == 0){
				for(int i = beg; i <= end; i++){
					if(ln->data->year == i){
						ctrySums[mNodeCount][i - beg] += ln->data->numGrads;
						sums[i - beg] += ln->data->numGrads;
					}
				}
			}

			ln = ln->next;
		}

		mn = mn->next;
		mNodeCount++;
	}

	printGradPctByYear(ctrys,ctrySums,sums,m->size, beg, end);
}

/*
	purpose: calculate the female graduate percentage for each country and pass the data to the printing function
			 in: a pointer to the map that stores all of the data
	 return: N/A
*/
void calcFemaleGradPct(MapType *m){
	int fSums[m->size];
	int mNodeCount = 0;
	MapNodeType *mn = m->head;;
	ListNodeType *ln;
	char ctrys[m->size][MAX_STR];
	int sums[m->size];
	VariableNodeType *s;

	for(int i = 0; i < m->size; i++){
		sums[i] = 0;
	}


	while(mn != NULL){
		fSums[mNodeCount] = 0;

		ln = mn->list->head;
		strcpy(ctrys[mNodeCount], ln->data->countryName);

		while(ln != NULL){
			if(strcmp(ln->data->gender, "T") == 0){
				sums[mNodeCount] += ln->data->numGrads;
			} else if(strcmp(ln->data->gender, "F") == 0){
				fSums[mNodeCount] += ln->data->numGrads;
			}

			ln = ln->next;
		}

		mn = mn->next;
		mNodeCount++;
	}

	VariableNodeType *pcts[m->size];

	float p[m->size];

	for(int i = 0; i < m->size; i++){
		p[i] = (float) fSums[i]/sums[i] * 100;
		s = NULL;
		initVariableNode(&s, ctrys[i], "float");
		s->data = &(p[i]);
		pcts[i] = s;
	}	

	qsort(pcts, m->size, sizeof(VariableNodeType*), cmpFunc);

	printFemaleGradPct(pcts,m->size);

	freeSortArray(pcts, m->size);
}

/*
	purpose: implements the control flow for calculating and printing the top and bottom 5 countries by total numGrads
			 in: a pointer to the map that stores all of the data
	 return: N/A
*/
void handleCase4(MapType *m){
	DegreeNum deg;
	VariableNodeType *arr[m->size];
	int *sum;


	chooseDegree(&deg);
	calcNumGrads(m, arr, deg, &sum);
	qsort(arr, m->size, sizeof(VariableNodeType *), cmpFunc);
	printNumGrads(arr, m->size, deg);

	free(sum);
	freeSortArray(arr, m->size);
}

/*
	purpose: implements the control flow for calculating and printing the sample standard deviation of num grads for each country
			 in: a pointer to the map that stores all of the data
	 return: N/A
*/
void handleCase5(MapType *m){
	char degree[DEG_STR];
	DegreeNum deg;
	VariableNodeType *arr[m->size];
	int yearRange[m->size];
	double mean[m->size];
	int *sum;


	chooseDegree(&deg);
	calcNumGrads(m, arr, deg, &sum);


	if(deg == L6){
		strcpy(degree, "L6");
	} else if(deg == L7){
		strcpy(degree, "L7");
	} else if(deg == L8){
		strcpy(degree, "L8");
	}

	MapNodeType *mn = m->head;;
	ListNodeType *ln;
	double variance[m->size];
	double stdDev[m->size];
	int mNodeCount = 0;

	while(mn != NULL){
		variance[mNodeCount] = 0;

		yearRange[mNodeCount] = mn->endRange - mn->begRange + 1;
		mean[mNodeCount] = deg != ALL ? (double) (* (int*) arr[mNodeCount]->data) / yearRange[mNodeCount] : (double) (* (int*) arr[mNodeCount]->data) / (3 * yearRange[mNodeCount]);

		ln = mn->list->head;

		while(ln != NULL){
			if(strcmp(ln->data->gender, "T") == 0){
				if(deg == ALL){
					variance[mNodeCount] += pow((double) ln->data->numGrads - mean[mNodeCount], 2);
				} else if(strcmp(ln->data->degree, degree) == 0){
					variance[mNodeCount] += pow((double) ln->data->numGrads - mean[mNodeCount], 2);
				}
			}

			ln = ln->next;
		}

		variance[mNodeCount] /= deg != ALL ? (yearRange[mNodeCount] - 1) : (3 * yearRange[mNodeCount]) - 1;
		stdDev[mNodeCount] = sqrt(variance[mNodeCount]);

		strcpy(arr[mNodeCount]->type, "double");
		arr[mNodeCount]->data = &(stdDev[mNodeCount]);

		mn = mn->next;
		mNodeCount++;
	}

	printStdDev(mean, arr, m->size, deg);

	free(sum);
	freeSortArray(arr, m->size);
}

/*
	purpose: compare 2 array values to figure out sorted order, lowest to highest
			 in: an element of the array cast to a void pointer
			 in: a subsequent element of the array to be compared to the firse, also cast to a void pointer
	 return: a negative int if the second element should come before the the first, 0 if the order is interchangeable, a postive int if the first elemnt should come before the second
*/
int cmpFunc(const void *a, const void *b){
	VariableNodeType *d1 = *(VariableNodeType**) a;
	VariableNodeType *d2 = *(VariableNodeType**) b;

	if(strcmp(d1->type, "int") == 0){
		return ((* (int*) d1->data) - (* (int*) d2->data));
	} else if(strcmp(d1->type, "float") == 0){
		return (int) ((* ( (float*) d1->data ) ) * 10 - (* ( (float*) d2->data ) ) * 10);
	}
}

/*
	purpose: free all of the dynamically allocated data stored in the given map including the map itself
	 in/out: a pointer to the map to be free'd
	 return: N/A
*/
void freeMap(MapType *m){
	MapNodeType *mn = m->head, *nextMN = NULL;
	ListNodeType *ln, *nextLN;

	while(mn != NULL){
		ln = mn->list->head;

		while(ln != NULL){
			nextLN = ln->next;
			free(ln->data);
			free(ln);

			ln = nextLN;
		}

		nextMN = mn->next;
		free(mn->list);
		free(mn);

		mn = nextMN;
	}

	free(m);
}

/*
	purpose: free all of the dynamically allocated data stored in the given array
	 in/out: the array of data be be free'd
	 		 in: the size/length of the array
	 return: N/A
*/
void freeSortArray(VariableNodeType *arr[], int size){
	for(int i = 0; i < size; i++){
		free(arr[i]);
	}
}
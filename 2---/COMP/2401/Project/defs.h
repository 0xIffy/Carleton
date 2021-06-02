#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CTRY_CODE_LENGTH			4
#define GND_STR 							2
#define DEG_STR								3
#define MAX_STR								60
#define NUM_REPORTS						5
#define NUM_DEGS							3

#define C_FALSE								0
#define C_TRUE								1

typedef struct {
	char countryCode[CTRY_CODE_LENGTH];
	char countryName[MAX_STR];
	char gender[GND_STR];
	char degree[DEG_STR];
	int year;
	int numGrads;
} RecordType;

typedef struct ListNode{
	RecordType *data;
	struct ListNode *next;
	struct ListNode *prev;
} ListNodeType;

typedef struct {
	ListNodeType *head;
	ListNodeType *tail;
	char countryCode[CTRY_CODE_LENGTH];
} ListType;

typedef struct MapNode{
	char key[CTRY_CODE_LENGTH];
	int begRange;
	int endRange;
	ListType *list;
	struct MapNode *next;
} MapNodeType;

typedef struct {
	MapNodeType *head;
	MapNodeType *tail;
	int size;
} MapType;

typedef struct {
	char country[MAX_STR];
	void *data;
	char type[10];
} VariableNodeType;

typedef enum{
	L6, L7, L8, ALL
} DegreeNum;

// Functions in init.c
int initRecord(RecordType**, char*, char*, char*, char*, int, int);
int initListNode(ListNodeType**, RecordType*);
int initList(ListType**, char*);
int initMapNode(MapNodeType**, ListType*, char*);
int initMap(MapType**);
int initVariableNode(VariableNodeType**, char*, char*);

// Functions in data.c
void addListNode(ListNodeType*, ListType*);
int addMapNode(MapNodeType**, MapType*, ListType*, char*);
int readData(MapType*, char*);
void calcGradPctByDeg(MapType*);
void calcGradPctByYear(MapType*, int, int);
void calcFemaleGradPct(MapType*);
int calcNumGrads(MapType*, VariableNodeType *[], DegreeNum, int**);
void handleCase4(MapType*);
void handleCase5(MapType*);
int cmpFunc(const void *, const void *);
void freeMap(MapType*);
void freeSortArray(VariableNodeType *[], int);

// Functions in print.c
void printMenu();
void printGradPctByDeg(char[][MAX_STR], int[][NUM_DEGS + 1], int*, int);
void printGradPctByYear(char[][MAX_STR], int[][4], int*, int, int, int);
void printFemaleGradPct(VariableNodeType*[], int);
void printNumGrads(VariableNodeType*[], int, DegreeNum);
void printStdDev(double[], VariableNodeType *[], int, DegreeNum);
void chooseDegree(DegreeNum*);
void getDegree(DegreeNum, char*);
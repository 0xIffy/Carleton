#define MAX_STR 	40
#define C_TRUE 		1
#define C_FALSE 	0

typedef struct{
	int id;
	char title[MAX_STR];
	int year;
} MovieType;

typedef struct Node{
	MovieType *data;
	struct Node *next;
	struct Node *prev;
} NodeType;

typedef struct{
	NodeType *head;
	NodeType *tail;
	int nextId;
} ListType;

typedef struct{
	int size;
	MovieType **elements;
} ArrayType;

typedef enum{
	BY_TITLE, BY_YEAR
} SortType;

// Functions in init.c
void initAllMovies(ListType*, ListType*);
int initList(ListType**);
int initArray(ArrayType**);
void initMovie(char*,int,MovieType**);

// Functions in data.c
void addMovieToList(SortType,ListType*,MovieType*);
int addNode(ListType*,NodeType*,NodeType*,MovieType*);
void mergeMovies(SortType, ArrayType*,ListType*,ListType*);
int addMovieToArray(ArrayType*,MovieType*);
void freeList(ListType*);
void freeArray(ArrayType*);
void freeAllMovies(ArrayType*);

//Fucntions in print.c
void printList(ListType*);
void printMovie(MovieType*);
void printArray(ArrayType*);
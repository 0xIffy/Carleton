#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <curses.h>
#include <signal.h>

#define START_POS				35
#define END_POS					2
#define PATH_1       		10
#define PATH_2       		14
#define MAX_HEALTH   		50
#define MAX_RUNNERS  		20
#define MAX_DORCS    		50
#define MAX_STR      		16
#define MAX_BUF      		80

#define HEALTH_ROW    	0
#define HEALTH_COL   		30
#define STATUS_ROW    	4
#define STATUS_COL   		30

#define C_TRUE        	1
#define C_FALSE       	0

#define DORC_FREQ     	3

#define HEALTH_BAR_ROW 	HEALTH_ROW + 2

typedef struct {
  pthread_t thr;
  char avatar[MAX_STR];
  int  currPos;
  int  path;
} EntityType;

typedef struct {
  EntityType ent;
  char name[MAX_STR];
  int  health;
  int  dead;
} RunnerType;

typedef struct {
  int numRunners;
  RunnerType *runners[MAX_RUNNERS];
  int numDorcs;
  EntityType *dorcs[MAX_DORCS];
  char winner[MAX_STR];
  int  statusRow;
  sem_t mutex;
} RaceInfoType;

//graphics.c
void initNcurses();
void cleanupNcurses(int);
void scrPrt(char*, int, int);
int  randm(int);
void moveEntity(int currPos, int currPath, char *a, int nextPos, int nextPath);
void updateHealth(int newHealth, int col);
void printStatus(char *type, char *player, char *message);

//entity.c
void *goRunner(void*);
void *goDorc(void*);
void checkCollisions(RunnerType *, int);

//init.c
int initRace(RunnerType **);
int initRunner(RunnerType **, char name[MAX_STR], char a[MAX_STR], int path);
int initEntity(EntityType **, char a[MAX_STR], int path, int pos);
void freeAll();

RaceInfoType *race;


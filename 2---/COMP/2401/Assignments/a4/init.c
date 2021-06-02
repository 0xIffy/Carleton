#include "defs.h"

/*
			purpose:	allocate memory for the race dats strcuture, initialize its feilds and create threads for all runners
					 in:	an array of pointers  to all runners to be stored in the race's runners array.
			 return:	1 if the actions of the function are successful, 0 otherwise.
 side-effects:	the race's data gets updated
*/
int initRace(RunnerType *runners[]){
	race = (RaceInfoType *) malloc(sizeof(RaceInfoType));

	if(race == NULL)
		return C_FALSE;

	race->numRunners = 0;
	race->numDorcs = 0;

	for(int i = 0; i < MAX_RUNNERS; i++){
		race->runners[i] = runners[i];
		if(runners[i] != NULL){
			printf("%d",runners[i]->ent.path);
			race->numRunners++;
		}
	}

	if(sem_init(&(race->mutex),0,1) < 0){
		printf("semaphore initialization error.\n");
		exit(1);
		return C_FALSE;
	}

	strcpy(race->winner, "");
	race->statusRow = STATUS_ROW;

	srand( (unsigned)time(NULL) );
	initNcurses();

	scrPrt("Health:",HEALTH_ROW,HEALTH_COL);
	scrPrt("----------------------",END_POS-1,0);
	scrPrt("----------------------",START_POS+1,0);

	for(int i = 0; i < race->numRunners; i++){
		scrPrt(race->runners[i]->ent.avatar, race->runners[i]->ent.currPos, race->runners[i]->ent.path);
		scrPrt(race->runners[i]->ent.avatar, HEALTH_ROW, HEALTH_COL + race->runners[i]->ent.path);
		pthread_create(&(race->runners[i]->ent.thr), NULL, goRunner, race->runners[i]);
	}

	return C_TRUE;
}

/*
	purpose:	allocate and initialize the data for a runner data type
	 in/out:	the address of a pointer to a runner structure
			 in:	the name of the runner
			 in:	the runner's avatar
			 in:	the path/column the runner will be racing in
	 return:	1 if the actions of the function are successful, 0 otherwise.
*/
int initRunner(RunnerType **r, char name[MAX_STR], char a[MAX_STR], int path){
	EntityType *e;
	*r = (RunnerType *) malloc(sizeof(RunnerType));

	if(!initEntity(&e, a, path, START_POS) || *r == NULL)
		return C_FALSE;

	(*r)->ent = *e;
	strcpy((*r)->name, name);
	(*r)->dead = 0;
	(*r)->health = MAX_HEALTH;
	
	free(e);
	return C_TRUE;
}

/*
	purpose:	allocate and initialize data for an entity data type
	 in/out:	the address of a pointer to a entity structure
			 in:	the entity's avatar
			 in:	the path/column the entity will start in
			 in:	the row/position the entity will start in
	 return:	1 if the actions of the function are successful, 0 otherwise.
*/
int initEntity(EntityType **e, char a[MAX_STR], int path, int pos){
	*e = (EntityType *) malloc(sizeof(EntityType));

	if(e == NULL)
		return C_FALSE;

	strcpy((*e)->avatar, a);
	(*e)->path = path;
	(*e)->currPos = pos;

	return C_TRUE;
}
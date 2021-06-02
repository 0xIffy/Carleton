#include "defs.h"

/*
	purpose:	the logic/loop for each runner thread
			 in:	a pointer to a runner data type (cast to void)
	 return:	N/A
*/
void *goRunner(void *r){
	RunnerType *runner = (RunnerType *) r;

	int nextPos;
	int randNum;
	int healthCol = HEALTH_COL + runner->ent.path;

	while(runner->ent.currPos > END_POS && !runner->dead){
		usleep(250000);
		nextPos = runner->ent.currPos;

		randNum = randm(10);
		if(randNum <= 6){
			randNum = randm(4) + 1;
			nextPos = nextPos - randNum > END_POS ? nextPos - randNum : END_POS;
			runner->health = runner->health > randNum ? runner->health - randNum : 0;
		} else {
			randNum = randm(3) + 1;
			nextPos = nextPos + randNum < START_POS ? nextPos + randNum : START_POS;
		}

		checkCollisions(runner, nextPos);

		if(runner->health == 0){
			strcpy(runner->ent.avatar, "+");
			runner->dead = 1;

			if(sem_wait(&(race->mutex)) < 0){
				printf("semaphore wait error\n");
				exit(1);
			}
			printStatus("STATUS", runner->name, "has died.");
			if(sem_post(&(race->mutex)) < 0){
				printf("semaphore post error\n");
				exit(1);
			}
		}

		moveEntity(runner->ent.currPos, runner->ent.path, runner->ent.avatar, nextPos, runner->ent.path);
		updateHealth(runner->health, healthCol);
		
		
		runner->ent.currPos = nextPos;
	}

	if(!runner->dead && strcmp(race->winner, "") == 0){
		strcpy(race->winner, runner->name);
	}

	moveEntity(runner->ent.currPos, runner->ent.path, runner->ent.avatar, nextPos, runner->ent.path);
}

/*
	purpose:	the logic/loop for each dorc thread
			 in:	a pointer to a entity data type (cast to void)
	 return:	N/A
*/
void *goDorc(void *d){
	EntityType *dorc = (EntityType *) d;

	int nextPos;
	int nextPath;
	int steps;
	int randNum;

	while(dorc->currPos < START_POS){
		nextPos = dorc->currPos;
		nextPath = dorc->path;

		steps = randm(5) + 1;
		nextPos = nextPos + steps < START_POS ? nextPos + steps : START_POS;

		randNum = randm(3);
		if(randNum == 0){
			nextPath = nextPath > PATH_1 ? nextPath - 2 : PATH_1;
		} else if(randNum == 1){
			nextPath = nextPath < PATH_2 ? nextPath + 2 : PATH_2;
		} 
		// else don't change path

		moveEntity(dorc->currPos, dorc->path, dorc->avatar, nextPos, nextPath);

		dorc->path = nextPath;
		dorc->currPos = nextPos;
		usleep(700000);
	}

	moveEntity(dorc->currPos, dorc->path, "", -1, -1);
}

/*
		 purpose:	loop through the array of dorcs and check for a collision between any of them and the given runner
					in:	a pointer to the runner being checked
					in:	the position the runner will be at the end of the current iteration of the main loop
			return:	N/A
side effects: - a message gets printed to the screen if a collision occurs
							- the race's semaphore gets paused during the action then unpaused at the end
*/
void checkCollisions(RunnerType *runner, int pos){
	if(sem_wait(&(race->mutex)) < 0){
		printf("semaphore wait error\n");
		exit(1);
	}
	for(int i = 0; i < race->numDorcs; i++){
		if(race->dorcs[i]->currPos == pos && race->dorcs[i]->path == runner->ent.path){
			printStatus("STATUS",runner->name,"collided with a dorc.");
			runner->health = runner->health > 3 ? runner->health - 3 : 0;	
		}
	}
	if(sem_post(&(race->mutex)) < 0){
		printf("semaphore post error\n");
		exit(1);
	}
}

/*
	purpose:	free all pointers to data in the heap at the end of the program
			 in:	N/A
	 return:	N/A
*/
void freeAll(){
	for(int i = 0; i < race->numRunners; i++){
		free(race->runners[i]);
	}

	for(int i = 0; i < race->numDorcs; i++){
		free(race->dorcs[i]);
	}

	free(race);
}
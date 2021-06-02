#include "defs.h"

int main(){
	int randNum;
	int dorcCol;
	int deadRunners = 0;
	RunnerType *timmy = NULL;
	RunnerType *harold = NULL;
	EntityType *dorc;

	initRunner(&timmy,"Timmy","T",PATH_1);
	initRunner(&harold,"Harold","H",PATH_2);

	RunnerType **runners = {(RunnerType **) calloc(MAX_RUNNERS, sizeof(RunnerType *))};
	runners[0] = timmy;
	runners[1] = harold;


	if(!initRace(runners)){
		printf("Failed to start race, program terminating.\n");
		return -1;
	}
	free(runners);

	do{
		deadRunners = 0;
		randNum = randm(10);

		if(randNum <= 2 && race->numDorcs < MAX_DORCS){
			dorc = NULL;

			if(randNum == 0)
				dorcCol = PATH_1;
			else if(randNum == 1)
				dorcCol = PATH_2;
			else
				dorcCol = (PATH_1 + PATH_2) / 2;

			initEntity(&dorc, "d", dorcCol, END_POS);

			race->dorcs[race->numDorcs] = dorc;
			race->numDorcs++;
			pthread_create(&(dorc->thr), NULL, goDorc, dorc);
		}

		for(int i = 0; i < race->numRunners; i++){
			if(race->runners[i]->dead){
				deadRunners++;
			}
		}

		usleep(250000);
	} while(strcmp(race->winner, "") == 0 && deadRunners != race->numRunners);
	
	for(int i = 0; i < race->numRunners; i++){
		pthread_join(race->runners[i]->ent.thr, NULL);
	}

	for(int i = 0; i < race->numDorcs; i++){
		pthread_cancel(race->dorcs[i]->thr);
	}

	if(strcmp(race->winner,"") != 0){
		printStatus("OUTCOME", race->winner, "won the race!");
	} else{
		printStatus("OUTCOME", "all players","have died.");
	}

	freeAll();

	// Takes you back to the regular command line after program executes
	scrPrt("Press any key to continue...", START_POS+2, 0);
	getchar();
	kill(getpid(), SIGINT);
}
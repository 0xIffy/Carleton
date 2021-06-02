#include "defs.h"

void initNcurses()
{
  initscr();
  curs_set(0);
  clear();
}

void cleanupNcurses(int row)
{
  move(row, 0);
  addstr("Press any key to continue...");
  getch();
  endwin();
}

void scrPrt(char *str, int row, int col)
{
  move(row, col);
  addstr(str);
  refresh();
}

int randm(int max)
{
  double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
  return (int)(r * max);
}

/*
		 purpose:	formulates and prints out a statuc message to the screen
					in:	the typeof status update it is (OUTCOME or STATUS)
					in:	the player(s) the status relates to
					in:	the specific message that should be printed
			return:	N/A
side-effects:	the race's status row property is incremented
*/
void printStatus(char *type, char *player, char *message){
	char statStr[MAX_BUF];
	int statLen = strlen(type) + strlen(player) + strlen(message);

	if(statLen < MAX_BUF - 3){
		sprintf(statStr, "%s: %s %s", type, player, message);
	} else{
		sprintf(statStr, "The length of this message exeeded the maximum buffer capcity.");
	}


	scrPrt(statStr, race->statusRow, STATUS_COL);
	race->statusRow++;
}

/*
		purpose:	update the screen to represent the new location of an entity
				 in:	the previous row of the entity
				 in: the previous column of the entity
				 in:	the avatar of the entity
				 in:	the new row of the entity
				 in:	the new column of the entity
		 return:	N/A
side-efects:	the race's semaphore gets paused during the action then unpaused at the end
*/
void moveEntity(int prevPos, int prevPath, char *a, int nextPos, int nextPath){
	if(sem_wait(&(race->mutex)) < 0){
		printf("semaphore wait error\n");
		exit(1);
	}

	scrPrt("  ", prevPos, prevPath);
	scrPrt(a, nextPos, nextPath);

	if(sem_post(&(race->mutex)) < 0){
		printf("semaphore post error\n");
		exit(1);
	}
}

/*
		purpose:	update the value of a players health on the screen
			 	 in:	the new helth value
				 in:	the column of the players's health bar
	 	 return:	N/A
side-efects:	the race's semaphore gets paused during the action then unpaused at the end
*/
void updateHealth(int newHealth, int col){
	char healthStr[5];

	if(sem_wait(&(race->mutex)) < 0){
		printf("semaphore wait error\n");
		exit(1);
	}

	sprintf(healthStr, "%02d", newHealth);
	scrPrt(healthStr, HEALTH_BAR_ROW, col);

	if(sem_post(&(race->mutex)) < 0){
		printf("semaphore post error\n");
		exit(1);
	}
}
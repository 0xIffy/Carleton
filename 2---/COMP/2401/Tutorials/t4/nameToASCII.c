#include <stdio.h>

int main(){
	char name[20];
	int i = 0;

	printf("Please input a name: ");
	scanf("%s",name);

	while(name[i] != '\0'){
		printf("The ASCII code for %c is %d\n",name[i],name[i]);

		++i;
	}

	return 0;
}
#include<stdio.h>
#include<string.h>

// This is a forward reference
int palindrome(char *s);

int main() {

  char word[30];

    
  printf ("Enter a word or \"q\" to stop: ");
  scanf ("%s", word);

  while (strcmp(word, "q") != 0) {
    palindrome(word);
    printf ("Enter a word or \"q\" to stop: ");
    scanf ("%s", word);
  };

  return 0;

}
  
int palindrome(char *s)
{
  // add code to test for palindrome and print a message  
	char revWord[30];
	int i = 0;

	for(i = 0; i < strlen(s); i++){
		revWord[i] = s[strlen(s)-i-1];
	}
	revWord[i] = '\0';

	if(strcmp(s,revWord) == 0){
		printf("\t\"%s\" is a palindrome\n",s);
	} else{
			printf("\t\"%s\" is not a palindrome\n",s);
	}
}

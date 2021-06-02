#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(){
	int clientSocket, addrSize, bytesReceived;
	struct sockaddr_in  clientAddr;
	int i;

	// int inNum;
	char inStr[80];
  char buffer[80];

	// Create socket
  clientSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (clientSocket < 0) {
    printf("*** CLIENT ERROR: Could open socket.\n");
    exit(-1);
  }

	// Setup address 
  memset(&clientAddr, 0, sizeof(clientAddr));
  clientAddr.sin_family = AF_INET;
  clientAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
  clientAddr.sin_port = htons((unsigned short) SERVER_PORT);

	/* connect to server */

  i = connect(clientSocket, 
              (struct sockaddr *) &clientAddr,
              sizeof(clientAddr));
  if (i<0) {
    printf("client could not connect!\n");
    exit(-1);
  }

/* get input from user and send to server */
  while (1) {
    printf("CLIENT: Enter number to send to primeServer, 'done' to stop:\t\t");
   scanf("%s", inStr);
    // fgets(inStr, sizeof(inStr), stdin);
    // inStr[strlen(inStr)-1] = 0;
    // strcpy(buffer, inNUm);
    strcpy(buffer, inStr);
    printf("CLIENT: Sending \"%s\" to server.\n", buffer);

    sendto(clientSocket, buffer, strlen(buffer), 0,
           (struct sockaddr *) &clientAddr, sizeof(clientAddr));

    // Get response from server, should be "OK"
    addrSize = sizeof(clientAddr);
    bytesReceived = recvfrom(clientSocket, buffer, 80, 0,
		        (struct sockaddr *) &clientAddr, &addrSize);
    buffer[bytesReceived] = 0; // put a 0 at the end so we can display the string
    printf("CLIENT: Got back response \"%s\" from server.\n", buffer);
    
    if ((strcmp(inStr,"done") == 0) || (strcmp(inStr,"stop") == 0))
      break;
  } 

/* close the socket */

  close(clientSocket);

  return 0;
	
}
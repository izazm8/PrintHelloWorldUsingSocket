#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main(){

	char serverMsg[256] = "You have Reached to the server..!";
	char msgFromClient[256];

	//creating server socket
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	//defining server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;	//same thing as 0.0.0.0struct sockaddr_in server_address;

	//binding the socket to our specified IP and port
	bind(serverSocket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(serverSocket, 5);

	int clientSocket = accept(serverSocket, NULL, NULL);


	//send(clientSocket, serverMsg, sizeof(serverMsg), 0);
	recv(clientSocket, &msgFromClient, sizeof(msgFromClient), 0);

	printf("From Server: %s\n",msgFromClient);

	close(serverSocket); 



	return 0;
}

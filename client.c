#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main(){


	//creating an socket
	int net_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specifying the address of socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;	//same thing as 0.0.0.0

	//coneect
	int connectionStatus = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));


	//checking for the error in the conenction
	if(connectionStatus == -1) {
		printf("There was an error in making connection with the socket..\n");
	}

	//Receiving the data from server
	char serverResponse[256];

	char msg[256] = "Hello World..\n";
	send(net_socket, &msg, sizeof(msg), 0);

	//closing the sockeet
	close(net_socket);
	return 0;
}

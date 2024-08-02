#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
	// Disable output buffering
	setbuf(stdout, NULL);
 	setbuf(stderr, NULL);

	// You can use print statements as follows for debugging, they'll be visible when running tests.
	printf("Logs from your program will appear here!\n");

	// Uncomment this block to pass the first stage
	
	int server_fd, client_addr_len;
	struct sockaddr_in client_addr;
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		printf("Socket creation failed: %s...\n", strerror(errno));
		return 1;
	}
	
	// Since the tester restarts your program quite often, setting SO_REUSEADDR
	// ensures that we don't run into 'Address already in use' errors
	int reuse = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
		printf("SO_REUSEADDR failed: %s \n", strerror(errno));
		return 1;
	}
	 // Address of the server, IPv4 family, port 4221, we accept connections from
    // any any IP address
	struct sockaddr_in serv_addr = { .sin_family = AF_INET ,
									 .sin_port = htons(4221),
									 .sin_addr = { htonl(INADDR_ANY) },
									};
	
	if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
		printf("Bind failed: %s \n", strerror(errno));
		return 1;
	}
	
	int connection_backlog = 5;
	if (listen(server_fd, connection_backlog) != 0) {
		printf("Listen failed: %s \n", strerror(errno));
		return 1;
	}
	
	printf("Waiting for a client to connect...\n");
	client_addr_len = sizeof(client_addr);
	
	// Create an ID for the connection you accept
	int clientId = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
	printf("Client connected\n"); //output success message to console

	//Parsing logic from what's his face on Youtube
	char readBuffer[1024];
	int bytesReceived = recv(clientId, readBuffer, sizeof(readBuffer), 0);

	char * requestPath = strtok(readBuffer, " ");
	requestPath = strtok(NULL, " ");

	printf("DEBUG - RequestPath: %s\n", requestPath);

	int bytesSent;

	//create a response variable with the required response
	//HTTP Version + Status Code + Status Message + CRLF + HEADERS (NONE) + CRLF
	//SUCCESS HTTP/1.1 200 OK\r\n\r\n strlen 20
	//404 HTTP/1.1 404 Not Found\r\n\r\n strlen 27
	char *response = NULL;
	if (strcmp(requestPath, "/") == 0) {
		response = "HTTP/1.1 200 OK\r\n\r\n";
	}
	else {
		response = "HTTP/1.1 404 Not Found\r\n\r\n";
	}
	printf("DEBUG - RESPONSE: %s\m", response);
	bytesSent = send(clientId, response, strlen(response), 0);

	//sizeof or strlen work
	//sizeof will return the size of the data? memory allocated?
	//strlen returns the length of the string

	if (bytesSent < 0)
	{
		printf("Send failed\n");
		return 1;
	}
	
	close(server_fd);

	return 0;

}
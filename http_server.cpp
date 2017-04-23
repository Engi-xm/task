#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BACKLOG 10
#define MAX_DATA_SIZE 100
#define HTTP_200 "HTTP/1.1 200 OK"
#define HTTP_400 "HTTP/1.1 400 Bad Request"
#define HTTP_404 "HTTP/1.1 404 Not Found"

using namespace std;

int main(int argc, char const *argv[]) {
	int status, pid;
	int yes = 1; // setsockopt variable
	int bytes_received;
	char rec_buf[MAX_DATA_SIZE]; // receive buffer
	int socket_fd, new_fd; // listen on socket_fd, serve connections on new_fd
	struct addrinfo hints;
	struct addrinfo *serv_info;  // will point to the results
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t their_addr_size; // connector's address size
	FILE *file_to_send; // file requested by client

	if(argc != 3) {
		cout << "usage: html_sever port root_dir\n";
		return 1;
	}

	// initialize hints struct
	memset(&hints, 0, sizeof(hints)); // make sure the struct is empty
	hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

	// getaddrinfo
	// TODO: change cout to gai_strerror
	if(getaddrinfo(NULL, argv[1], &hints, &serv_info) != 0) { // if unsuccessful
		cout << "getaddrinfo error"; // print error
		return 1; 
	}

	// create socket
	socket_fd = socket(serv_info->ai_family, serv_info->ai_socktype, serv_info->ai_protocol); // open socket
	
	// TODO: add setsockopt (reuse ports)

	// bind socket
	if(bind(socket_fd, serv_info->ai_addr, serv_info->ai_addrlen) == -1) { // if binding failed
		cout << "bind error"; // print error
		return 1;
	}

	// cleanup
	freeaddrinfo(serv_info);

	// listen on socket
	if(listen(socket_fd, BACKLOG) == -1) { // if unsuccessful
		cout << "listen error"; // print error
		return 1;
	}

	// TODO: clear zombies
	
	while(1) { // accept loop
		their_addr_size = sizeof(their_addr);
		new_fd = accept(socket_fd, (struct sockaddr*)&their_addr, &their_addr_size); // accept connection
		if(new_fd == -1) { // if unsuccessful
			cout << "accept error"; // print error
			continue;
		}

		if((pid = fork()) < 0) // if unsuccessful
			cout << "fork error"; // print error
		else if(pid == 0) { // child process
			close(socket_fd); // close listener
			if((bytes_received = recv(new_fd, rec_buf, MAX_DATA_SIZE - 1, 0)) == -1) { // receive request
				send(new_fd, HTTP_400, strlen(HTTP_400), 0); // send http400
				cout << "receive error"; // print error
				exit(1); // terminate child
			}
			// file_to_send = fopen(file_req+argv[2])
			// if(file_to_send == NULL) {
			// 	send http404
			// } else {
			// 	send http200 and file
			close(new_fd); // close socket
			exit(0); // terminate child
		}
		close(new_fd); // close new connection on parent
	}

	return 0;
}
#include <errno.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

//server
int main() {
	int sockfd, newsock, valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buf[100] = {0};

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd == -1) {
		printf("Unable to create socket %d\n", errno);
		return -1;
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(9889);

	if(bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		printf("Unable to bind the socket with address\n");
		return -1;
	}

	if(listen(sockfd, 3)<0) {
		printf("Failed to make socket passive\n");
		return -1;
	}

	if((newsock = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addrlen) < 0 )) {
		printf("Failed to accept the connection\n");
		return -1;
	}

	printf("Waiting for client to send msg\n");


	valread = read(newsock, buf, 100);
	printf("------- %ld\n", strlen(buf));
	printf("Okay %s", buf);
	printf("read");

	close(sockfd);

	return 0;
}

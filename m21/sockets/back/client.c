#include <sys/types.h>          /* See NOTES */
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {

	int sockfd;
	struct sockaddr_in address;
	char *str = "Hello World";
	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0) {
		printf("Failed to create socket\n");
		return -1;
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(9889);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		printf("Failed to create connection\n");
		return -1;
	}

	send(sockfd, str, strlen(str), 0);
	printf("Sent\n");

	return 0;
}	

	


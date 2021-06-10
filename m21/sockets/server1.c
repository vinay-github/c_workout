#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define PORT 8989

void * thread_func(void *soc) {
	char buffer[1024] = {0};
	char *hello = "This is world";
	int so = *(int *)soc;

	read( so , buffer, 1024);
	printf("%s\n",buffer );
	
	send(so , hello , strlen(hello) , 0 );
	return 0;
}

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server";
	
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	pthread_t pid[3];
	int i = 0;

	while(1) {
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}

		pthread_create(&pid[i], NULL, thread_func, (void *) &new_socket);
		pthread_join(pid[i], NULL);
		i++;

	}

	valread = read( new_socket , buffer, 1024);
	printf("%s\n",buffer );
	
	send(new_socket , hello , strlen(hello) , 0 );
	
	return 0;
}


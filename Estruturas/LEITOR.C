#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#define TRUE 1

int main(void)
{
	int sock, length;
	struct sockaddr_in server;
	int msgsock;
	char buf[1024];
	int rval, i;

	/* Create Socket */
	sock=socket(AF_INET, SOCK_STREAM, 0);
	if (sock<0) {
		perror("opening stream socket");
		exit(1);
	}
	
	/* Name socket using wildcards */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port=0;
	if (bind(sock,(struct sockaddr *) &server, sizeof server) < 0) {
		perror("binding stream socket");
		exit(1);
	}

	/* Find out assigned port number and print it out */
	length=sizeof server;
	if (getsockname(sock, (struct sockaddr *) &server, &length)<0) {
		perror("getting socket name");
		exit(1);
	}
	printf("Socket port #%d\n",ntohs(server.sin_port));
	
	/* Start setting connections */
	listen(sock,5);
	do {
		msgsock=accept(sock,(struct sockaddr *) 0, (int *) 0);
		if (msgsock==-1)
			perror("accept");
		else do {
			bzero(buf, sizeof buf);
			if ((rval=read(msgsock,buf,1024))<0)
				perror("reading stream message");
			i=0;
			if (rval==0)
				printf("Ending connection\n");
			else printf("-->%s\n",buf);
		     } while (rval!=0);
		close (msgsock);
	} while (TRUE);

	/*
	 * Since this program has an infinite loop, socket "sock"is
	 * never explicitly closed. However, all sockets will be closed
	 * automatically when a process is killed or terminates normally
	 */

	exit(0);
}
	

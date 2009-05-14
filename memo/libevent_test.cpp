#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/* sockets */
#include <sys/types.h>
#include <sys/socket.h>

/* for non blocking */
#include <fcntl.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <pthread.h>

/* for libevent */
#include <event.h>

#define MAKE_UDP 1

void readEv(int fd, short event, void* arg) {
	int len;
	char *buf = static_cast<char*>(malloc(255));
	int *ev_no = static_cast<int*>(arg);
	if (ev_no == NULL) {
		// implementation error ???
	}
#ifdef MAKE_UDP
	socklen_t l = sizeof(struct sockaddr);
	struct sockaddr_in cAddr;
#endif

	printf("DNS_read called with %s fd: %d, event: %d, #: %d\n",
		event_get_method(), fd, event, *ev_no);

#ifdef MAKE_UDP
	len = recvfrom(fd, buf, 254, 0, (struct sockaddr*)&cAddr, &l);
#else
	len = recv(fd, buf, 254, 0);
#endif

	if (len == -1) {
#ifdef MAKE_UDP
		perror("recvfrom()");
#else
		perror("recv");
#endif
		return;
	} else if (len == 0) {
		printf("Connection Closed\n");
		return;
	}

	buf[len] = '\0';

	printf("READ: %s from %d\n", buf, cAddr.sin_port);
}

int main() {
	int sock;
	int yes = 1;
	int len = sizeof(struct sockaddr);
	struct sockaddr_in addr;

#ifdef MAKE_UDP
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
#else
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
#endif
		perror("socket");
		return 1;
	}

	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
		perror("setsockopt");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(9001);
	addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(addr.sin_zero), 8);

	if (bind(sock, (struct sockaddr*)&addr, len) < 0) {
		perror("bind");
		return 1;
	}

#ifndef MAKE_UDP
	if (listen(sock, 16) < 0) {
		perror("listen");
		return 1;
	}
#endif

	printf("Listening now...\n");

	int event_number = 1;

	event_init();
	{
		struct event ev;
		event_set(&ev, sock, EV_READ | EV_PERSIST, readEv, &(event_number));
		event_add(&ev, NULL);
		event_number++;
	}
	event_dispatch();

	printf("Done!\n");
	return 1;
}



#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
 


#include <stdio.h>
#include <sys/types.h>
#include "iostream"
#include "winsock2.h"
#include "ws2tcpip.h"





int
lookup_host(const char *host)
{
	struct addrinfo hints, *res;
	int errcode;
	char addrstr[100];
	void *ptr;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags |= AI_CANONNAME;

	errcode = getaddrinfo(host, NULL, &hints, &res);
	if (errcode != 0)
	{
		perror("getaddrinfo");
		return -1;
	}

	printf("Host: %s\n", host);
	while (res)
	{
		inet_ntop(res->ai_family, res->ai_addr->sa_data, addrstr, 100);

		switch (res->ai_family)
		{
		case AF_INET:
			ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
			break;
		case AF_INET6:
			ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
			break;
		}
		inet_ntop(res->ai_family, ptr, addrstr, 100);
		printf("IPv%d address: %s (%s)\n", res->ai_family == PF_INET6 ? 6 : 4,
			addrstr, res->ai_canonname);
		res = res->ai_next;
	}

	return 0;
}

int
main()
{
	lookup_host("w520");
	char *hostname = "localhost";
	struct addrinfo hints, *res;
	struct in_addr addr;
	int err;

	memset(&hints, 0, sizeof(hints));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = AF_INET;

	if ((err = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
		printf("error %d\n", err);
		return 1;
	}

	addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;

	printf("ip address : %s\n", inet_ntoa(addr));

	freeaddrinfo(res);

	return 0;
}

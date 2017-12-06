// server
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>

using namespace std;

int main()
{
	// winsock startup
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);

	// if !=0 , then error
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}


	// address that we will bind our listening socket to 
	SOCKADDR_IN addr;

	// length of the address
	int addrlen = sizeof(addr);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // broadcast locally
	addr.sin_port = htons(1111);  //port
	addr.sin_family = AF_INET;    // ipv4
	

	//create the socket to listen to the new connection
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	// bind address to the socket
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	// places sListen socket in  a state
	listen(sListen, SOMAXCONN);


	//socket to hold the client connection
	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen);  //accept a new connection

	if (newConnection == 0) // fail to accept connection
	{
		std::cout << "Failed to accept the clients connection. \n";
	}
	else
	{
		std::cout << "client connected \n";
	}
		
	system("pause");


	return 0;
}
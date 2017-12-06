//client

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
	if(WSAStartup(DLLVersion, &wsaData) !=0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK|MB_ICONERROR);
		exit(1);
	}



	// address that we will bind our listening socket to 
	SOCKADDR_IN addr;

	// length of the address
	int addrlen = sizeof(addr);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // broadcast locally
	addr.sin_port = htons(1111);  //port
	addr.sin_family = AF_INET;    // ipv4


	// create a socket
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if(connect(Connection, (SOCKADDR*)&addr, addrlen)!=0)
	{
		MessageBoxA(NULL, "fail to connect", "ERROR", MB_OK || MB_ICONERROR);
		return 0; // failed to connect
	}

	std::cout << "Connected!\n";
	system("pause");
	return 0;
}

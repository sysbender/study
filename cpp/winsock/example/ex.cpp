#include "iostream"
#include "winsock2.h"
#include "ws2tcpip.h"

#pragma comment(lib,"WS2_32.lib")
using namespace std;

void main()
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 2), &data);

	SOCKET client;
	struct addrinfo hints, *res;
	char seraddr[] = "192.168.1.103";
	char port[] = "5500";
	memset(&hints, 0, sizeof(addrinfo));

	hints.ai_flags = AI_PASSIVE;    //设置参数
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	char cname[100];
	gethostname(cname, 100);    //获得主机的名称
	cout << "hostname = " << cname;
	int rc = getaddrinfo(cname, port, &hints, &res);    //利用主机名称获取本地地址
	if (rc == WSANO_DATA)
		cout << "Parse addr failed." << endl;

	cout << "addr=" << res->ai_addr;
	char buff[100] = "wo shi zhongchangshou.";
	DWORD bufflen = 100;
	//将本地地址转换成字符串显示
	//WSAAddressToString(res->ai_addr, res->ai_addrlen, NULL, buff, &bufflen);
	cout << "connect to address is : " << buff << endl;

	//使用解析得到的地址信息城建套接字
	client = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (client == INVALID_SOCKET)
		cout << "Create socket failed." << endl;

	//连接到本地服务器
	rc = connect(client, res->ai_addr, res->ai_addrlen);
	if (rc == SOCKET_ERROR)
		cout << "Connect to server failed." << endl;
	else
		cout << "Connection to server..." << endl;
	WSABUF buf;
	//下面创建三个数据结构，用于传送数据
	struct data { char buf[100]; };
	buf.buf = (char*)new struct data;
	buf.len = sizeof(data);

	DWORD bytes = 0, flag = 0;
	while (1)
	{
		cin.getline(buf.buf, 100);    //输入需要传送的数据
		if (WSASend(client, &buf, 1, &bytes, flag, NULL, NULL) != SOCKET_ERROR)
		{
			cout << "Send :" << bytes << " bytes!" << endl;
			cout << "Send data : " << buf.buf << endl;
		}
		else
			break;
		//是否同时接收信息，如果需要接收只需要将去掉即可

	}

	int exit;
	cout << "Enter a int data to exit. ";
	cin >> exit;
	closesocket(client);
	freeaddrinfo(res);        //该参数记得需要删除
	WSACleanup();
}
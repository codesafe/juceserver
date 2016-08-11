#include <Windows.h>
#include <winsock.h>

#define PORT 8888
#define SOCKET_BUFFER 1024

struct SocketBuffer
{
	int		totalsize;		// ��ü ����
	int		currentsize;	// �������� ���� ��ġ (��/���� ���)
	char	buffer[SOCKET_BUFFER];
	SocketBuffer()
	{
		totalsize = -1;
		currentsize = 0;
		memset(buffer, 0, SOCKET_BUFFER);
	}
};


class Network
{
public:
	Network()
    {
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		{
			Logger::outputDebugString("error\r\n");
		}

		serversock = socket(AF_INET, SOCK_STREAM, 0);
		if (serversock == INVALID_SOCKET)
			Logger::outputDebugString("ERROR opening socket");

		ZeroMemory(&serv_addr, sizeof(struct sockaddr_in));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(PORT);

		int status = bind(serversock, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in));
		if (status == SOCKET_ERROR)
			Logger::outputDebugString("Bind Error\n");

		listen(serversock, 5);
		Logger::outputDebugString("Socket created!");

		clisock = -1;
    }

    ~Network()
    {
    }

    void run()
    {
		if (clisock == -1)
		{
			ZeroMemory(&cli_addr, sizeof(struct sockaddr_in));
			int sockLen = sizeof(struct sockaddr_in);
			clisock = accept(serversock, (struct sockaddr*)&cli_addr, &sockLen);
			if (clisock == INVALID_SOCKET)
			{
				Logger::outputDebugString("Accept Error\n");
				closesocket(serversock);
				//WSACleanup();
				return;
			}

			// client socket --> nonblock
			unsigned long arg = 1;
			if (ioctlsocket(clisock, FIONBIO, &arg) != 0) return;
		}
		else
		{

			fd_set read_flags, write_flags;
			struct timeval waitd;          // the max wait time for an event
			int sel;

			waitd.tv_sec = 0;
			waitd.tv_usec = 0;
			FD_ZERO(&read_flags);
			FD_ZERO(&write_flags);
			FD_SET(clisock, &read_flags);

			sel = select(clisock + 1, &read_flags, &write_flags, (fd_set*)0, &waitd);
			if (FD_ISSET(clisock, &read_flags))
			{
				FD_CLR(clisock, &read_flags);

				char in[SOCKET_BUFFER];
				memset(&in, 0, sizeof(in));

				char buffer[SOCKET_BUFFER];
				int readn = recv(clisock, buffer, SOCKET_BUFFER, 0);
				if (readn > 0)
				{
					SocketBuffer recvbuf;
					recvbuf.totalsize = readn;
					recvbuf.totalsize = readn;
					readn = 0;
				}
				else
				{
					// disconnected
					closesocket(clisock);
					clisock = -1;
				}
			}


			// �������� ������ �����ٷ� ����
			if (sendbuffer.totalsize > 0)
				FD_SET(clisock, &write_flags);

			// ����
			if (FD_ISSET(clisock, &write_flags))
			{
				FD_CLR(clisock, &write_flags);
				int sendsize = ::send(clisock, sendbuffer.buffer + sendbuffer.currentsize, sendbuffer.totalsize - sendbuffer.currentsize, 0);
				if (sendbuffer.totalsize == sendbuffer.currentsize + sendsize)
				{
					sendbuffer.totalsize = -1;
					sendbuffer.currentsize = 0;
					memset(sendbuffer.buffer, 0, SOCKET_BUFFER);
				}
				else
				{
					sendbuffer.currentsize += sendsize;
				}
			}

		}

    }

	bool	sendpacket(int packetsize, char *packet)
	{
		if (clisock == -1) return false;

		sendbuffer.currentsize = 0;
		sendbuffer.totalsize = packetsize+sizeof(int);

		memcpy(sendbuffer.buffer, (void*)&packetsize, sizeof(int));
		memcpy(sendbuffer.buffer+sizeof(int), packet, packetsize);


		return true;
	}


private:

	std::deque<SocketBuffer>	recvbufferlist;
	SocketBuffer sendbuffer;

	
	SOCKET serversock;
	SOCKET clisock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
};


/*
#include <Windows.h>
#include <winsock.h>

#include <deque>

#ifdef WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

SOCKET sock;
struct sockaddr_in server;

#define SERVER_ADD			"127.0.0.1"
#define SERVER_PORT			8888
#define SOCKET_BUFFER		4096

struct SocketBuffer
{
	int		totalsize;		// ��ü ����
	int		currentsize;	// �������� ���� ��ġ (��/���� ���)
	char	buffer[SOCKET_BUFFER];
	SocketBuffer()
	{
		totalsize = -1;
		currentsize = 0;
		memset(buffer, 0, SOCKET_BUFFER);
	}
};

std::deque<SocketBuffer>	recvbufferlist;

//////////////////////////////////////////////////////////////////////////



// Read packet for parse
bool	recvpacket(SocketBuffer *buffer)
{
	if( !recvbufferlist.empty() )
	{
		buffer->totalsize = recvbufferlist[0].totalsize;
		buffer->currentsize = recvbufferlist[0].currentsize;
		memcpy(buffer->buffer, recvbufferlist[0].buffer, SOCKET_BUFFER);
		recvbufferlist.pop_front();
		return true;
	}

	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR)
		return -1;


	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) return -1;

	// puts("Socket created");

	memset((void *)&server, 0x00, sizeof(server));
	server.sin_addr.s_addr = inet_addr(SERVER_ADD);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	int err = ::connect(sock, (struct sockaddr *)&server, sizeof(server));
	if ( err < 0)
		return -1;


	while (true)
	{
		char in[SOCKET_BUFFER];
		memset(&in, 0, sizeof(in));

		int recvsize = ::recv(sock, in, sizeof(in), 0);
		if (recvsize <= 0)
		{
			closesocket(sock);
			break;
		}

		int psize = (int&)*in;
		//int psize;
		//memcpy(&psize, in, sizeof(int));
		printf("len %d : %s\n", psize, in+sizeof(int));
	}
	
	return 0;
}


*/
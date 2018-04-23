#ifndef CLIENT_H
#define CLIENT_H
#include <winsock.h>

class Client{
    SOCKET sock;
    char* text;
    SOCKET createConn();
    void sendSmth(SOCKET s, char c[]);
    void recvSmth(SOCKET s, char c[]);
    char* nullText();
    void nonBlockSock(SOCKET s);
public:
    Client();
    void run();
    void stop();
    void sendMsg(char *c);
    char* recvMsg();
};

#endif // CLIENT_H

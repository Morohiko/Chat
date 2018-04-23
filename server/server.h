#ifndef SERVER_H
#define SERVER_H
#include <winsock.h>
#include <list>
using namespace std;
class server{
    SOCKET mainSocket;
    list<SOCKET> *socketList;
    SOCKET createConn();
    char *text;
    void nonBlockSock(SOCKET s);
    char* checkSocketList();
    void sendSmth(SOCKET s, char c[]);
    void recvSmth(SOCKET s, char c[]);
    SOCKET newSock(SOCKET s);//
    char* nullText();
public:
    server();
    void run();
    void stop();
    void sendMsg(char *text);
    char* expectMsg();
};

#endif // SERVER_H

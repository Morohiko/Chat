#include "server.h"
#include "tools.h"
#include <winsock.h>
#include <iostream>
#include <list>
#include <typeinfo>
#include <exception>
using namespace std;

#define SIZETEXT 100

server::server(){}

SOCKET server::createConn(){
    SOCKET s;
    WSADATA ws;
    if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
        cout << "error wsastartup" << WSAGetLastError() << endl;
    if (INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM, 0)))
        cout << "error invalid socket" << WSAGetLastError() << endl;
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(1234);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(s, (struct sockaddr *)&sin, sizeof(struct sockaddr));
    if (FAILED(listen(s, SOMAXCONN)))
        cout << "listen error" << WSAGetLastError() << endl;
    return s;
}

void server::sendSmth(SOCKET s, char c[]){
    if (SOCKET_ERROR == (send(s, c, strlen(c)+1, 0)))
        cout << "error send = " << WSAGetLastError() << endl;
}

void server::recvSmth(SOCKET s, char c[]){
    if (SOCKET_ERROR == (recv(s, c, 100, 0))){
        cout << "error recv = " << WSAGetLastError() << endl;
    }
}

void server::nonBlockSock(SOCKET s){
    BOOL l = TRUE;
    if (SOCKET_ERROR == ioctlsocket (s, FIONBIO, (unsigned long* ) &l))
        cout<<"error nonBlockSock = "<< WSAGetLastError();
}

SOCKET server::newSock(SOCKET s){//
    SOCKET new_sock;
    sockaddr_in new_ca;
    int new_len = sizeof (new_ca);
    ZeroMemory(&new_ca, sizeof (new_ca));
    if (FAILED(new_sock = accept(s, (sockaddr*)&new_ca, &new_len))){
        return NULL;
    }
    return new_sock;
}

list<SOCKET> *socketList;

char* server::expectMsg(){
    SOCKET s = newSock(mainSocket);
    if (s!=NULL){
        socketList->push_back(s);
        return "connected";
    }
    char *txt = new char[100];
    txt = checkSocketList();
    if (strlen(txt)>0){
        return txt;
    }
    closesocket(s);
    return "";
}

void server::sendMsg(char *text){
    list<SOCKET>::iterator iter = socketList->begin();
    while(iter != socketList->end()){
        sendSmth(*iter, text);
        iter++;
    }
}
char* server::checkSocketList(){
    text = nullText();
    for(list<SOCKET>::iterator iter = socketList->begin(); iter!=socketList->end(); ++iter){
        recvSmth(*iter, text);
        if(strlen(text)>0){
            return text;
        }
    }
    return text;
}

char* server::nullText(){
    for(int i = 0;  i<SIZETEXT; i++){
        text[i] = '\0';
    }
    return text;
}

void server::run(){
    mainSocket = createConn();
    nonBlockSock(mainSocket);
    socketList = new list<SOCKET>();
    text = new char[SIZETEXT];
}

void server::stop(){
    closesocket(mainSocket);
    for(list<SOCKET>::iterator it = socketList->begin(); it!=socketList->end(); it++){
        closesocket(*it);
    }
    delete(socketList);
}


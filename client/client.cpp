#include "client.h"
#include "tools.h"
#include "errorlog.h"
#include <iostream>
#include <winsock.h>
#include <string>

using namespace std;

#define SIZETEXT 100

Client::Client(){}

SOCKET Client::createConn(){
    SOCKET s;
    WSADATA ws;
    if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
        cout<<"error wsastartup"<<endl;
    if (INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM, 0)))
        cout<<"error invalid socket"<<endl;
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(1234);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(s, (struct sockaddr *)&sin, sizeof(struct sockaddr));

    if (SOCKET_ERROR == connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr)))
        cout<<"error conected"<<endl; 
    return s;
}

void Client::nonBlockSock(SOCKET s){
    BOOL l = TRUE;
    if (SOCKET_ERROR == ioctlsocket (s, FIONBIO, (unsigned long* ) &l))
        cout<<"error nonBlockSock = "<< WSAGetLastError();
}

void Client::sendSmth(SOCKET s, char c[]){
    if (SOCKET_ERROR == (send(s, c, strlen(c)+1, 0)))
        cout<<"error send = " << WSAGetLastError();
}

void Client::recvSmth(SOCKET s, char c[]){
    if (SOCKET_ERROR == (recv(s, c, 100, 0)))
        cout<<"error recv = " << WSAGetLastError();
}

SOCKET sock;

void Client::run(){
    sock = createConn();
    nonBlockSock(sock);
    text = new char[SIZETEXT];
    cout<<"run"<<endl;
}

void Client::stop(){
    closesocket(sock);
}

char* Client::recvMsg(){
    text = nullText();
    if (sock == NULL) {
        return "";
    }
    recvSmth(sock, text);
    return text;
}

void Client::sendMsg(char *c){
    if (sock == NULL) {
        return;
    }
    sendSmth(sock, c);
    delete(c);
}


char* Client::nullText(){
    for(int i = 0;  i<SIZETEXT; i++){
        text[i] = '\0';
    }
    return text;
}


#include "mainwindow.h"
#include "client.h"
#include "tools.h"
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLineEdit>
using namespace std;

#define INTERVAL 100

Client *cl;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    init();
    cl = new Client();
}

MainWindow::~MainWindow(){}

void MainWindow::init(){
    vLayout->addWidget(msgList, 0, 0);
    vLayout->addWidget(msg, 0, 0);
    hLayout->addWidget(btnConn, 0, 0);
    hLayout->addWidget(btnSend, 0, 0);
    vLayout->addLayout(hLayout, 0);
    vLayout->addWidget(lbl, 0, 0);
    msg->setBaseSize(600, 50);
    msgList->setBaseSize(600, 400);
    btnConn->setText("connect");
    btnSend->setText("Send");
    lbl->setText("Text");
    frame->show();
    tmr->setInterval(INTERVAL);
    tmr->stop();
    connect(tmr, SIGNAL(timeout()), this, SLOT(run()));
    connect(btnConn, SIGNAL(clicked()), this, SLOT(conn()));
    connect(btnSend, SIGNAL(clicked()), this, SLOT(sendMsg()));
}

void MainWindow::pushText(char *c){
    QString str1;
    str1 = str1.fromStdString(c);
    if (strlen(c)<1) return;
    str1 = msgList->toPlainText() + '\n' + str1;
    msgList->setText(str1);
}

void MainWindow::conn(){
    if (tmr->isActive()) {
        btnConn->setText("connect");
        cl->stop();
        tmr->stop();
        return;
    }
    btnConn->setText("discon");
    cl->run();
    tmr->start();
}

void MainWindow::run(){
    while(true){
        char *c = cl->recvMsg();
        if (strlen(c)==0) return;
        pushText(c);
    }
}

void MainWindow::sendMsg(){
    QString str = msg->text();
    const char* text1 = str.toStdString().c_str();
    char *text2 = (char *)text1;
    cl->sendMsg(text2);
}


#include "mainwindow.h"
#include "server.h"
#include "tools.h"
#include <iostream>
//#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QTimer>
using namespace std;

#define INTERVAL 100

server *s;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    init();
    s = new server();
}

MainWindow::~MainWindow(){}

void MainWindow::init(){
    text->show();
    btn->setText("start");
    text->setBaseSize(600, 400);
    vLayout->addWidget(text);
    vLayout->addWidget(btn);
    frame->show();
    tmr->setInterval(INTERVAL);
    connect(btn, SIGNAL(clicked()), this, SLOT(start()));
    connect(tmr, SIGNAL(timeout()), this, SLOT(run()));
}

void MainWindow::start(){
    if (tmr->isActive()) {
        btn->setText("start");
        s->stop();
        tmr->stop();
        return;
    }
    btn->setText("stop");
    s->run();
    tmr->start();
}

void MainWindow::run(){
    char *c = s->expectMsg();
    if (strlen(c)==0) return;
    s->sendMsg(c);
    pushText(c);
}

void MainWindow::pushText(char *c){
    QString str1;
    str1 = str1.fromStdString(c);
    if (strlen(c)<1) return;
    str1 = text->toPlainText() + '\n' + str1;
    text->setText(str1);
}

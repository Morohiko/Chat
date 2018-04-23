#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QTimer>

//Client *client;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QHBoxLayout *hLayout = new QHBoxLayout();
    QFrame *frame = new QFrame();
    QVBoxLayout *vLayout = new QVBoxLayout(frame);
    QPushButton *btnConn = new QPushButton();
    QPushButton *btnSend = new QPushButton();
    QLabel *lbl = new QLabel();
    QTextEdit *msgList = new QTextEdit();
    QLineEdit *msg = new QLineEdit();
    QTimer *tmr = new QTimer(this);
    void init();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void pushText(char *c);
    MainWindow* getThis();
private slots:
    void sendMsg();
    void run();
    void conn();
};

#endif // MAINWINDOW_H

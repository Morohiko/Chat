#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QTimer>
//namespace Ui {
class MainWindow;
//}

class MainWindow : public QMainWindow{
    Q_OBJECT
    QFrame *frame = new QFrame();
    QTextEdit *text = new QTextEdit();
    QPushButton *btn = new QPushButton();
    QVBoxLayout *vLayout = new QVBoxLayout(frame);
    QTimer *tmr = new QTimer(this);
    void init();
    void pushText(char *c);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void start();
    void run();

private:
//    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

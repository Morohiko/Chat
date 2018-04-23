//#include "tools.h"
//#include <qstring.h>
//#include <iostream>
//using namespace std;

//void copy(char* c1, char* c2){
//    while (*c2){
//        *c1 = *c2;
//        c1++; c2++;
//    }
//    *c1 = '\0';
//}
//void addToList(char* c1, char* c2){
//    while (*c1) {
//        c1++;
//    }
//    c1--;
//    while (*c2){
//        *c1 = *c2;
//        c1++; c2++;
//    }
//    *c1 = '\n'; c1++; *c1 = '\0';
//}

//QString charToQString(char *c){
//    QChar ch = '1';
//    QString str;
//    char *chIt = (char *)&ch;
//    cout<< "c = " << c << endl;
//    do {
//        *chIt = *c;
//        chIt++; c++;
//        *chIt = *c;
//        c++; chIt--;
//        str.append(ch);
//    } while(*c != '\0');
//    return str;
//}


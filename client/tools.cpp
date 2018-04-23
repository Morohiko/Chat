//#include "tools.h"
//#include <cstring>
//#include <qstring.h>
//#include <iostream>
//#include <QTextEdit>
//using namespace std;

//int getSizeWord(char* c){
//    int i = 0;
//    while(*c){
//        i++; c++;
//    }
//    return i;
//}

//bool firstBigest(char* c1, char* c2){
//    int i1 = getSizeWord(c1);
//    int i2 = getSizeWord(c2);
//    if (i1>i2) {
//        return true;
//    }else{
//        return false;
//    }
//}

////char* toListByte(QString str){
////    QByteArray ba = str.toLatin1();
////    const char *c = ba.data();
////    return c;
////}

//char* combWords(QString s, char* c){
//    int size = s.size()+strlen(c)+1;
//    char *c1 = new char[size];

//}

//char* combWords(char* c1, char* c2){
//    char *c3 = (strlen(c1)>strlen(c2))? new char[strlen(c1)] : new char[strlen(c2)];
//    char *buff = c3;
//    while (*c2){
//        *buff = *c2;
//        buff++; c2++;
//    }
//    *buff = ':'; buff++; *buff = ' ';
//    while (*c1){
//        *buff = *c1;
//        buff++; c1++;
//    }
//    *buff = ';'; buff++; *buff = '\0';
//    return c3;
//}

// char* qstringToChar(QString str){
//    const char* text1 = str.toStdString().c_str();
//    char *text2 = (char *)text1;
//    return text2;
//    char *text = new char(str.size()*2+1);
//    char *textIter = &text[0];
//    char *c = nullptr;
//    QChar strite = '1';
//    for(int i = 0; i < str.size(); i++){
//        strite = str.at(i);
//        c = (char *)&strite;
//        while(*c){
//            //cout<<"while = "<<*c<<", sizeof = "<<sizeof(strite)<< endl;
//            *textIter = *c;
//            textIter++; c++;
//        }
//        //*textIter = *c;
//        //textIter++; c++;
//        //*textIter = *c;
//        //textIter++;
//    }
//    *textIter = '\0';
//    return text;
//}

//QString charToQString(char *c){
//    QString str1;
//    str1 = str1.fromStdString(c);
//    cout<<"c = " << *c <<endl;
//    return str1;
//    QChar ch = 'й';
//    QString str;
//    ch.unicode();
//    cout<< "c = " << c << endl;
//    do {
//        char *chIt = (char *)&ch;
//        while(*chIt){
//            cout<<"while"<<endl;
//            *chIt = *c;
//            chIt++; c++;
//        }
//        cout<<"after while"<<endl;
//        str.append(ch);
//    } while(*(c) != '\0');
//    return str;
//}



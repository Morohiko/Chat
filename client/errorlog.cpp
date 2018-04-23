#include "errorlog.h"
#include <cstring>
ErrorLog::ErrorLog(){
    log = new char[1];
}

void ErrorLog::pushError(char *err){
    int size = strlen(err) + strlen(log);
    char* buff = &log[0];
    char* buff1 = buff;
    log = new char[size + 2];
    int i = 0;
    while(*buff){
        log[i] = *buff;
        buff++; i++;
    }
    while(*err){
        log[i] = *err;
        err++; i++;
    }
    log[i++] = '\n'; log[i] = '\0';
    delete(buff1);
}

void ErrorLog::resetLog(){
    log = new char[1];
}
char* ErrorLog::getLog(){
    return log;
}


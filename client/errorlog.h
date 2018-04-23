#ifndef ERRORLOG_H
#define ERRORLOG_H

class ErrorLog{
    char *log;
public:
    ErrorLog();
    void pushError(char *err);
    void resetLog();
    char* getLog();
};

#endif // ERRORLOG_H

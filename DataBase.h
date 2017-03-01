#ifndef BASE_H
#define BASE_H
#include "vector.h"
#include <cstring>
#include "structs.h"
#include <cstdio>
#define MAX_BUF_LEN 1024
class DataBase
{
private:
    Vector <field> data;
public:
    class DataBaseException
    {
    public:
        const char * reason;
        DataBaseException():
            reason("default reason")
        {}
        DataBaseException(const char * reason_):
            reason(reason_)
        {}
        const char * toString() const
        {
            return reason;
        }
    };
public:
    //DataBase();
    DataBase(const char * path) throw(DataBaseException);
    DataBase(FILE * file) throw(DataBaseException);
    DataBase(const DataBase & copy);
    //~DataBase();

    void push_back(const field & copy);
    void freeVector();
    void deleteField(const field & copy);
    void deleteField(unsigned int index);

    bool isContentsData(const char data[10]) const;
    bool isContentsID(int id) const;
    bool isContentsItem(const char * item) const;
    bool isContentsPrice(double price) const;

    void getIntervalData(const char dataBegin[10],const char dataEnd[10],DataBase & result) const;
    void getIntervalID(int idBegin, int idEnd, DataBase & result) const;
    void getIntervalItem(const char * itemBegin,const char * itemEnd,DataBase & result) const;
    void getIntervalPrice(double priceBegin, double priceEnd, DataBase & result) const;

    void printData(); // debug function
};
int stringToField(const char * str, field & result,char * buf,char * buf_data);
#endif

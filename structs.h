#ifndef STRUCTS_H
#define STRUCTS_H
#include <cstdio>
#include <cstring>
struct field
{
	int user_id;
    char * item = NULL;
	double price;
    char data[12];
    field(const field & copy):
        user_id(copy.user_id),
        price(copy.price)
    {
        memcpy(data,copy.data,12);
        int len = strlen(copy.data);
        data = new char[len];
        memcpy(data,copy.data,len);
    }
    field & operator = (const field & copy)
    {
        user_id = copy.user_id;
        price = copy.price;
        memcpy(data,copy.data,12);
        int len = strlen(copy.item);
        if(item)
            delete [] item;
        item = new char [len];
        memcpy(item,copy.item,len);
    }
};
#endif 

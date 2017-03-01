#include "DataBase.h"
#include <cstdio>
int stringToField(const char * str,field & result,char * buf,char * buf_data)
{
    //memset(buf,0,MAX_BUF_LEN);
    //memset(buf_data,0,MAX_BUF_LEN);
    if(sscanf(str,"%i %s %lf %s",&(result.user_id),buf,&(result.price),buf_data) != 4)
        return 0;
    int len = 0;
    while(buf[len] != 0 && len < MAX_BUF_LEN)
        len ++;
    if(result.item != NULL)
        delete [] (result.item);
    result.item = new char [len];
    //std :: cout << buf << std :: endl;
    memset(result.item,0,len);
    memcpy(result.item,buf,len);
    memcpy(result.data,buf_data,12);
    return 1;
}
DataBase :: DataBase (const char * path) throw(DataBase :: DataBaseException)
{
    FILE * file = fopen(path,"r");
    char * buf = new char [MAX_BUF_LEN];
    char * bufItem = new char [MAX_BUF_LEN];
    char * bufData = new char [MAX_BUF_LEN];
    if(!file)
        throw DataBase :: DataBaseException("cannot open file");
    field tmp;
    while(!feof(file))
    {
        memset(buf,0,MAX_BUF_LEN);
        memset(bufData,0,MAX_BUF_LEN);
        memset(bufItem,0,MAX_BUF_LEN);
        fgets(buf,MAX_BUF_LEN,file);
        if(ferror(file))
            throw DataBase :: DataBaseException("error while reading from file");
        if(!stringToField(buf,tmp,bufItem,bufData))
            throw DataBase :: DataBaseException("unknown string in file");
       // std :: cout << tmp.item << "                    item" << std :: endl;
        data.push_back(tmp);
    }
    fclose(file);
    delete [] buf;
    delete [] bufItem;
    delete [] bufData;
}
DataBase :: DataBase(FILE *file) throw(DataBase ::DataBaseException)
{
    if(!file)
        throw DataBase :: DataBaseException("file is invalid in costrunctor");
    char * buf = new char [MAX_BUF_LEN];
    char * bufItem = new char [MAX_BUF_LEN];
    char * bufData = new char [MAX_BUF_LEN];
    field tmp;
    while(!feof(file))
    {
        memset(buf,0,MAX_BUF_LEN);
        memset(bufItem,0,MAX_BUF_LEN);
        memset(bufData,0,MAX_BUF_LEN);
        fgets(buf,MAX_BUF_LEN,file);
        if(ferror(file))
            throw DataBase :: DataBaseException ("error while reading");
        if(!stringToField(buf,tmp,bufItem,bufData))
            throw DataBase :: DataBaseException("string is invalid");
        data.push_back(tmp);
    }
    fclose(file);
    delete [] buf;
    delete [] bufItem;
    delete [] bufData;
}
void DataBase :: printData()
{
    for(int  i=0; i< data.size(); i++)
        std :: cout <<data[i].user_id<< " " <<data[i].item << " " <<  data[i].price << " " << data[i].data << std :: endl;
}

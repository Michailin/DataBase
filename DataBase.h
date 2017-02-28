#ifndef BASE_H
#define BASE_H
#include "structs.h"
#include <stdint.h>
class DataBaseException
{
public:
	const char * message;
	DataBaseException():
		message("standart exception")
	{}
	DataBaseException(const char * message_)
	message(message_)
	{}
	std :: ostream & operator << (std :: ostream & os) const;
}
class DataBase
{
	unsigned int size;
	unsigned int capacity;
	field * data;

	void reallocData();
	void allocMemory(size_t amount);

public :
	~DataBase();
	DataBase();
	DataBase(field * data_, int len);
	DataBase(int capacity);
	DataBase(const DataBase & copy);


	void addInBase(const field & data);
	void addInBase(field * data);
	void readBaseFromFile(const char * pathToFile) throw(DataBaseException);
	void writeBaseToFile(const char * pathToFile) throw (DataBaseException);


	DataBase * getRangeUser_id(int user_id_begin, int user_id_end) const;
	DataBase * getRangeItem(const char * item_begin, const char * item_end) const;
	DataBase * getRangePrice(int price_begin, int price_end) const;
	DataBase * getRangeData(cosnt char * data_begin, const char * data_end) const;


	bool isContainsUser_id(int user_id) const;
	bool isContainsItem(const char * item , int len) const;
	bool isContainsPrice(int price) const;
	bool isContainsData(const char * data) const;
}
#endif

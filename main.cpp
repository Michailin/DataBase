#include <iostream>
#include "vector.h"
#include <algorithm>
#include <cstdio>
#include "DataBase.h"
int main()
{
    try
    {
        std :: cout << "yes" << std :: endl;
        DataBase data("/home/dmitry/Projects/DataBase/output");
        //std :: cout << "yes" << std :: endl;
        data.printData();
    }
    catch (DataBase :: DataBaseException e)
    {
        std :: cout << e.toString() << std :: endl;
    }

    return 0;
}

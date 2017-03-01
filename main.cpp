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
        DataBase data("/home/dmitry/DataBase/output");
        data.printData();
    }
    catch (DataBase :: DataBaseException e)
    {
        std :: cout << e.toString() << std :: endl;
    }

    return 0;
}

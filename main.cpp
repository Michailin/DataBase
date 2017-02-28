#include <iostream>
#include "vector.h"
int main()
{
    Vector <int> tmp;
    //tmp.reallocMem(1999);
   // for(int i = 0; i < 100000; i++)
    //    tmp.push_back(i);
   // for(int i = 0; i < tmp.size();i++)
    //    std :: cout << tmp[i] << std :: endl;
    tmp.freeVector();
    for(int i = 0;i < 19; i++)
        tmp.push_back(i);
    try
    {
        tmp.removeData(2);
        tmp.removeData(2);
        tmp.removeData(134);
    }
    catch(Vector <int> :: VectorException e)
    {
        std :: cout << e.toString() << std :: endl;
    }

    for(int i = 0; i < tmp.size(); i++)
        std :: cout << tmp[i] << std :: endl;
    return 0;
}

#include <iostream>
#include "vector.h"
int main()
{
    int i = 199;
    Vector <int> tmp;
    tmp.push_back(i);
    tmp.push_back(i + 10);
    for(Vector<int> :: iterator i = tmp.getBeginIterator(); i < tmp.getEndIterator();i++)
        std :: cout << *i << std :: endl;
    return 0;
}

#include <iostream>
#include "vector.h"
#include <algorithm>
void print(int it)
{
    std :: cout << it << std :: endl;\
}
int main()
{
    Vector <int> tmp;
    for(int i = 0; i < 1000; i++)
        tmp.push_back(i);

    std :: for_each(tmp.getBeginIterator(),tmp.getEndIterator(),print);
    return 0;
}

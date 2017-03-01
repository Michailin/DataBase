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
    for(int i = 0; i < 1000000; i++)
        tmp.push_back(i);
    Vector <int> tpq;
    tpq = tmp;
    std :: for_each(tpq.getBeginIterator(),tpq.getEndIterator(),print);
    return 0;
}

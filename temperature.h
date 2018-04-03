#include <iostream>
#include <sstream>
#include <cassert>
//тут все прототипы и структура
struct  Temperature{
    double temp;
    char scale;
};
istream & operator >> (istream& in, Temperature& Temp);
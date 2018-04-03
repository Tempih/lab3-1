//тут дополнительные функции
#include "temperature.h"
istream & operator >> (istream& in, Temperature& Temp){
    in >> Temp.temp;
    in >> Temp.scale;
};
double convert(const Temperature& Temp, char scaleTo){
    double Kelvins;
    if(scaleTo == Temp.scale){
        return Temp.temp;
    };
    switch (Temp.scale){
    case 'K':
    case 'k':
        Kelvins = Temp.temp;
        break;
    case 'F':
    case 'f':
        Kelvins = (5*(Temp.temp - 32))/9 + 273.15;
        break;
    case 'C':
    case 'c':
        Kelvins = Temp.temp - 273.15;
        break;
    };
    scaleTo = Temp.scale;
    switch (scaleTo){
    case 'K':
    case 'k':
        return Kelvins;
        break;
    case 'F':
    case 'f':
        return ((9.0/5)*(Kelvins - 273) + 32);
        break;
    case 'C':
    case 'c':
        return Kelvins - 273.15;
        break;
    };
};
bool operator < (const Temperature& lhs, const Temperature& rhs){
    return convert(lhs, 'K') < convert(rhs, 'K');
};
Temperature operator - (const Temperature& lhs, Temperature& rhs){
    Temperature retTemp;
    retTemp.temp = convert(lhs, 'K') - convert(rhs, 'K');
    retTemp .scale = 'K';
    return retTemp;
};
Temperature operator / (const Temperature& lhs, Temperature& rhs){
    Temperature retTemp;
    retTemp.temp = convert(lhs, 'K') / convert(rhs, 'K');
    retTemp .scale = 'K';
    return retTemp;
}
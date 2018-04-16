//
// Created by u211-05 on 16.04.2018.
//
#include <iostream>
#ifndef LAB01_TEMPERATURE_H
#define LAB01_TEMPERATURE_H
enum Scale
{
    Kelvin,
    Celsiy,
    Farenheit,
};

struct Temperature
{
    double value;
    Scale scale;
};
std::istream& operator >> (std::istream& in, Temperature& t);
Temperature convert (const Temperature& t, Scale scale);
bool operator < (Temperature t1, Temperature t2);
bool operator > (Temperature t1, Temperature t2);
#endif //LAB01_TEMPERATURE_H

//
// Created by u211-05 on 16.04.2018.
//
#include <iostream>
#include <sstream>
#include <cassert>
#include "temperature.h"
using namespace std;

void test_temperature_input ()
{
    
    // создать поток в памяти с примерами
    istringstream in ("15K");
    //считать значение в переменную
    Temperature result;
    in >> result;
    //проверить значение шкалы
    assert (result.value == 15);
    assert (result.scale == Kelvin);

    // создать поток в памяти с примерами
    istringstream in_2 ("23F");
    //считать значение в переменную
    in_2 >> result;
    //проверить значение шкалы
    assert (result.value == 23);
    assert (result.scale == Farenheit);

    // создать поток в памяти с примерами
    istringstream in_3 ("46C");
    //считать значение в переменную
    in_3 >> result;
    //проверить значение шкалы
    assert (result.value == 46);
    assert (result.scale == Celsiy);


    istringstream in_4 ("-15K");
    in_4 >> result;
    assert(!in_4);

    istringstream in_5 ("23Y");
    in_5 >> result;
    assert(!in_5);

    istringstream in_6 ("bC");
    in_6 >> result;
    assert(!in_6);
}

int main ()
{
    test_temperature_input();
}

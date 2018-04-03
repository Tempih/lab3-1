#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>

using namespace std;
char Scale[] = "CKF";
struct  Temperature{
    double temp;
    char scale;
};
istream & operator >> (istream& in, Temperature& Temp);
istream & operator >> (istream& in, Temperature& Temp){
    in >> Temp.temp;
    in >> Temp.scale;
};
void test_temperature_input(){
    Temperature Temp;
    string inp = "10C";
    istringstream iss(inp);
    iss >> Temp;
    assert(Temp.temp == 10);
    assert(Temp.scale == 'C');
    istringstream issC("0K");
    issC >> Temp;
    assert(Temp.temp == 0);
    assert(Temp.scale == 'K');
    istringstream issF("-400F");
    issF >> Temp;
    assert(Temp.temp == -400);
    assert(Temp.scale == 'F');
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
int
main() {
    test_temperature_input();
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
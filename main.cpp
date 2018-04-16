#include <iostream>
#include <vector>
using namespace std;

#include "temperature.h"



int
main() {

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<Temperature> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
        if (!cin) { cerr <<"Necorrectniyi vvod";
        return 1; }
    }


    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    Temperature min = numbers[0];
    Temperature max = numbers[0];
    for (Temperature number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    max = convert(max, min.scale);

    vector<size_t> counts(column_count);
    for (Temperature number : numbers) {
        number = convert(number, min.scale);
        size_t column = (size_t)((number.value - min.value) / (max.value - min.value) *
                column_count);
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
    };
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

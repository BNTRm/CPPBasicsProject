
#include <iostream>
#include <string>

using namespace std;

extern int a, b, c, d;

int main()
{
    // #2
    int number, diff;

    cout << "Enter the number: ";
    cin >> number;

    diff = number <= 21 ? number - 21 : (number - 21) * 2;

    cout << diff << endl << endl;

    // #3*
    int * arrPtr, array[3][3][3] = {
        { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} },
        { {19, 20, 21}, {22, 23, 24}, {25, 26, 27} },
        { {28, 29, 30}, {31, 32, 33}, {34, 35, 36} }
    };

    arrPtr = &array[1][1][1];

    cout << *arrPtr << endl << endl; // Должно быть 23

    // #4**
    float result = a * (b + (static_cast<float>(c) / d)); // Должно быть 20.25

    cout << result << endl;

    return 0;
}
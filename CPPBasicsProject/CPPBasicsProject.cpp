
#include <iostream>

using namespace std;

int main()
{
    // #1
    cout << "Task #1" << endl;

    int a, b;

    cout << "Enter number A: ";
    cin >> a;
    cout << "Enter number B: ";
    cin >> b;

    cout << "Is number in 10-20 range: ";
    if (a + b > 9 && a + b < 21)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << endl;

    // #2
    cout << "Task #2" << endl;

    const int c = 7;
    const int d = 3;

    if ((c == 10 && d == 10) || c + d == 10)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << endl;

    // #3
    cout << "Task #3" << endl;

    cout << "Odd numbers: ";
    for (int i = 1; i <= 50; i++)
    {
        if (i % 2 == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl << endl;

    // #4*
    cout << "Task #4*" << endl;

    unsigned int prime;
    cout << "Enter number: ";
    cin >> prime;

    bool isPrime = true;
    for (size_t i = 2; i < prime; i++)
    {
        if (prime % i == 0)
        {
            isPrime = false;
        }
    }

    cout << "Is number is Prime: ";
    if (isPrime)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << endl;

    // #5*
    cout << "Task #5*" << endl;

    unsigned short year;
    while (true) // Цикл для проверки того, что ввели число именно из диапазона 1-3000
    {
        cout << "Enter a Year (1-3000): ";
        cin >> year;

        if (year >= 1 && year <= 3000) {
            break;
        }
        else
        {
            cout << "Year is not in 1-3000 range" << endl << "Please Re";
        }
    }

    bool isLeap = true;
    if (year % 4 == 0) // Если делится без остатка на 4, то идем дальше
    {
        if (year % 100 == 0) // Если делится без остатка на 100, то нужно проверить, не 400 ли это
        {
            if (year % 400 != 0)
            {
                isLeap = false;
            }
        }
    }
    else
    {
        isLeap = false;
    }

    cout << "Year is Leap: ";
    if (isLeap)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
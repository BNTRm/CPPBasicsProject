
#include <iostream>
#include <fstream>
#include "MyLib.h"

using namespace std;

#define IN_RANGE(x, y) (x >= 0 && x < y ? true : false)
inline void task2()
{
    int num;

    cin >> num;

    cout << (IN_RANGE(num, 10) ? "True" : "False") << endl;
}

#define ARR_SIZE 10
inline void task3()
{
    int* arr = new int[ARR_SIZE];

    cout << "Enter " << ARR_SIZE << " numbers: " << endl;
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        cin >> arr[i];
    }

    MyLib::sortArr(arr, ARR_SIZE);
    MyLib::printArr(arr, ARR_SIZE);
}

#pragma pack(push, 1)
struct Employee
{
    long id;
    string fName, lName;
    int age;
    float salary;
    short experience;
};
#pragma pack(pop)

void printEmployee(Employee* emp)
{
    cout << "ID: " << emp->id << endl;
    cout << emp->lName << " " << emp->fName << ", " << emp->age << endl;
    cout << "Salary: $" << emp->salary << "/month" << endl;
    cout << "Experience: " << emp->experience << " year(s)" << endl;

    cout << "Size: " << sizeof(emp) << " bytes" << endl;
}

void saveEmployeeToFile(Employee* emp)
{
    ofstream fout("employee.txt");

    if (fout.is_open())
    {
        fout << "Employee:{id:" << emp->id << ";fName:" << emp->fName << ";lName:";
        fout << emp->lName << ";age:" << emp->age << ";salary:" << emp->salary;
        fout << ";experience:" << emp->experience << ";}," << endl;

        fout.close();
    }
    else
    {
        cout << "Can't open file" << endl;
    }
}

inline void task4()
{
    Employee* emp = new Employee;

    emp->id = 1;
    emp->fName = "Viktor";
    emp->lName = "Malchits";
    emp->age = 24;
    emp->salary = 100'000.00;
    emp->experience = 3;

    printEmployee(emp);

    saveEmployeeToFile(emp);
}

// Файлы для задания: MyLib.cpp, MyLib.h
inline void task5()
{
    const short size = 10;
    float* arr = MyLib::initArr(size);

    MyLib::printArr(arr, size);
    MyLib::positiveAndNegativeCount(arr, size);
}

int main()
{
    //task1();

    //task2();

    //task3();

    task4();

    //task5();

    return 0;
}
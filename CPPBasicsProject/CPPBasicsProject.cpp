
#include <iostream>

using namespace std;

void printArray(double arr[], unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printArray(int arr[], unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

inline void task1()
{
    const unsigned size = 4;
    double arr[size] = { 3.14, 9.8, 123.456, 42.0 };

    printArray(arr, size);

    cout << endl;
}

void inverseBinArray(int arr[], unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = arr[i] == 1 ? 0 : 1;
    }
}

inline void task2()
{
    const unsigned size = 5;
    int arr[size] = { 1, 0, 0, 1, 1 };

    printArray(arr, size);
    inverseBinArray(arr, size);
    printArray(arr, size);

    cout << endl;
}

const int TASK_3_ARR_SIZE = 8;

bool fillArray(int* arr)
{
    int newArr[] = { 1, 4, 7, 10, 13, 16, 19, 22 };

    for (size_t i = 0; i < TASK_3_ARR_SIZE; i++)
    {
        arr[i] = newArr[i];
    }

    return true;
}

inline void task3()
{
    int arr[TASK_3_ARR_SIZE];

    if (fillArray(arr))
    {
        cout << "Array successfully filled" << endl;
        printArray(arr, TASK_3_ARR_SIZE);
    }

    cout << endl;
}

const short TASK_4_ARR_SIZE = 10;

// Алгоритм не работает для значений > TASK_4_ARR_SIZE
void shiftArray(int* arr, short shift)
{
    int shiftedArr[TASK_4_ARR_SIZE];

    for (size_t i = 0; i < TASK_4_ARR_SIZE; i++)
    {
        if (shift > 0)
        {
            if (i < shift)
            {
                shiftedArr[i] = arr[TASK_4_ARR_SIZE - (shift - i)];
            }
            else
            {
                shiftedArr[i] = arr[i - shift];
            }
        }
        else
        {
            if (i - shift < TASK_4_ARR_SIZE)
            {
                shiftedArr[i] = arr[i - shift];
            }
            else
            {
                shiftedArr[i] = arr[- shift - (TASK_4_ARR_SIZE - i)];
            }
        }
    }

    for (size_t i = 0; i < TASK_4_ARR_SIZE; i++)
    {
        arr[i] = shiftedArr[i];
    }
}

inline void task4()
{
    int arr[TASK_4_ARR_SIZE];

    for (size_t i = 0; i < TASK_4_ARR_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    cout << "Input array: " << endl;
    printArray(arr, TASK_4_ARR_SIZE);

    short shift;

    cout << "Enter shift number: ";
    cin >> shift;

    shiftArray(arr, shift);

    cout << "Shifted array: ";
    printArray(arr, TASK_4_ARR_SIZE);

    cout << endl;
}

const short TASK_5_ARR_SIZE = 5;

int leftSum(int* arr, int index)
{
    int sum = 0;

    for (size_t i = 0; i <= index; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int rightSum(int* arr, int index)
{
    int sum = 0;

    for (size_t i = index + 1; i < TASK_5_ARR_SIZE; i++)
    {
        sum += arr[i];
    }

    return sum;
}

bool checkBalance(int* arr)
{
    for (size_t i = 0; i < TASK_5_ARR_SIZE - 1; i++)
    {
        if (leftSum(arr, i) == rightSum(arr, i))
        {
            return true;
        }
    }

    return false;
}

inline void task5()
{
    int arr1[] = { 1, 1, 1, 2, 1 };
    int arr2[] = { 2, 1, 1, 2, 1 };
    int arr3[] = { 10, 1, 2, 3, 4 };
    int arr4[] = { 4, 5, 6, 10, 5 };
    int arr5[] = { 20, 30, 40, 50, 60 };

    const string isBalancedText = " Is balanced: ", trueText = "True", falseText = "False";

    printArray(arr1, TASK_5_ARR_SIZE);
    cout << isBalancedText << (checkBalance(arr1) ? trueText : falseText) << endl;

    printArray(arr2, TASK_5_ARR_SIZE);
    cout << isBalancedText << (checkBalance(arr2) ? trueText : falseText) << endl;

    printArray(arr3, TASK_5_ARR_SIZE);
    cout << isBalancedText << (checkBalance(arr3) ? trueText : falseText) << endl;

    printArray(arr4, TASK_5_ARR_SIZE);
    cout << isBalancedText << (checkBalance(arr4) ? trueText : falseText) << endl;

    printArray(arr5, TASK_5_ARR_SIZE);
    cout << isBalancedText << (checkBalance(arr5) ? trueText : falseText) << endl;
}

int main()
{
    task1();

    task2();

    task3();

    task4();

    task5();

    return 0;
}
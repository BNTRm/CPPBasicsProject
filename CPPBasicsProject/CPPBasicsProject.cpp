
#include <iostream>
#include <fstream>

using namespace std;

void fillArrWithPowsOfTwo(int* arr, short size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = pow(2, i);
    }
}

void printArr(int* arr, short size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

inline void task1()
{
    int* arrPtr;
    short n;

    cout << "Enter array size: ";
    cin >> n;

    arrPtr = new int[n];

    fillArrWithPowsOfTwo(arrPtr, n);

    printArr(arrPtr, n);

    delete[] arrPtr;
    arrPtr = nullptr;
}

const short TASK_2_MATRIX_SIZE = 4;

void initMatrix(int** matrix, short size)
{
    for (size_t i = 0; i < TASK_2_MATRIX_SIZE; i++)
    {
        matrix[i] = new int[TASK_2_MATRIX_SIZE];
    }
}

void fillMatrixWithRands(int** matrix, short size)
{
    for (size_t i = 0; i < TASK_2_MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < TASK_2_MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % 1000;
        }
    }
}

void printMatrix(int** matrix, short size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void deleteMatrix(int** matrix, short size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
}

inline void task2()
{
    int** matrixPtr;
    matrixPtr = new int* [TASK_2_MATRIX_SIZE];

    initMatrix(matrixPtr, TASK_2_MATRIX_SIZE);

    fillMatrixWithRands(matrixPtr, TASK_2_MATRIX_SIZE);

    printMatrix(matrixPtr, TASK_2_MATRIX_SIZE);

    deleteMatrix(matrixPtr, TASK_2_MATRIX_SIZE);
}

const string TASK_3_SOME_TEXT[] = {
    "For although a man is judged by his actions, by what he has said and done, ",
    "a man judges himself by what he is willing to do, by what he might have said, ",
    "or might have done – a judgment that is necessarily hampered, bot only by the scope ",
    "and limits of his imagination, but by the ever-changing measure of his doubt and self-esteem."
};

void writeTextToFile(string filename)
{
    ofstream fout(filename);

    for (size_t i = 0; i < 4; i++)
    {
        fout << TASK_3_SOME_TEXT[i] << endl;
    }

    fout.close();
}

void writeInvertTextToFile(string filename)
{
    ofstream fout(filename);

    for (size_t i = 0; i < 4; i++)
    {
        fout << TASK_3_SOME_TEXT[3 - i] << endl;
    }

    fout.close();
}


struct Filenames
{
    string filename1;
    string filename2;
};

inline Filenames task3()
{
    string filename1, filename2;

    while (true)
    {
        cout << "Enter filename 1: ";
        cin >> filename1;

        cout << "Enter filename 2: ";
        cin >> filename2;

        if (filename1 == filename2)
        {
            cout << "Filenames are identical" << endl;
            continue;
        }

        break;
    }

    writeTextToFile(filename1);
    writeInvertTextToFile(filename2);

    // Возможно, это не очень правильно, но это избавляет от дублирования кода для 4 задания
    Filenames filenames = { filename1, filename2 };

    return filenames;
}

inline void task4()
{
    Filenames filenames = task3();

    string filename;

    cout << "Enter result filename: ";
    cin >> filename;

    ifstream fin1(filenames.filename1);
    ifstream fin2(filenames.filename2);

    ofstream fout(filename);

    if (fin1.is_open() && fin2.is_open())
    {
        const size_t size = 255;
        char buf[size];

        while (!fin1.eof())
        {
            fin1.getline(buf, size);

            fout << buf << endl;
        }

        while (!fin2.eof())
        {
            fin2.getline(buf, size);

            fout << buf << endl;
        }

        fin1.close();
        fin2.close();
    }
    else
    {
        cout << "Error: can not open file(s)" << endl;
    }
}

bool isWordInFile(string word, string filename)
{
    string buf;

    ifstream fin(filename);

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> buf;

            if (buf == word)
            {
                fin.close();

                return true;
            }
        }

        fin.close();

        return false;
    }
    else
    {
        cout << "Error: can not open file" << endl;
    }
}

inline void task5()
{
    string word, filename, buf;

    cout << "Enter a word: ";
    cin >> word;

    cout << "Enter a filename: ";
    cin >> filename;

    if (isWordInFile(word, filename))
    {
        cout << "Word is IN file" << endl;
    }
    else
    {
        cout << "Word is NOT IN file" << endl;
    }
}

int main()
{
    //task1();

    //task2();

    //task3();

    //task4();

    task5();

    return 0;
}
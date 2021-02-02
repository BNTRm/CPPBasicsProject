
#include <iostream>

using namespace std;

int main()
{
    // #1
    short int shortIntVar = 32'767;
    int intVar = 2'147'483'647;
    long long longLongVar = 9'223'372'036'854'775'807;
    char charVar = 'a';
    bool boolVar = true;
    float floatVar = 123.456;
    double doulbeVar = 1.7E+308;

    // #2
    enum TicTacToeEnum { TICTACTOE_EMPTY, TICTACTOE_X, TICTACTOE_O };

    // #3
    TicTacToeEnum ticTacToeArr[3];

    ticTacToeArr[0] = TICTACTOE_X;
    ticTacToeArr[1] = TICTACTOE_X;
    ticTacToeArr[2] = TICTACTOE_O;

    // #4*
    struct TicTacToeField
    {
        TicTacToeEnum grid[3][3];
        bool isXsTurn;
        bool isXWin;
        bool isOWin;
    };

    TicTacToeField field = 
    {
        {
            { TICTACTOE_X, TICTACTOE_O, TICTACTOE_EMPTY },      // X O -
            { TICTACTOE_EMPTY, TICTACTOE_X, TICTACTOE_O },      // - X O
            { TICTACTOE_EMPTY, TICTACTOE_EMPTY, TICTACTOE_X }   // - - X
        },
        false,
        true,
        false
    };

    cout << field.grid[1][1] << " "; // Центральная клетка со значением X, т.е. 1
    cout << field.grid[2][1] << " "; // Нижняя центральная клетка с пустым значением, т.е. 0
    cout << field.isXWin << " "; // X победил, значит здесь true, т.е. 1
    cout << field.isOWin << endl << endl; // А O проиграл, значит здесь false, т.е. 0
    // Итоговый вывод должен быть 1 0 1 0

    // #5**
    union IntFloatCharUnion
    {
        int intVar;
        float floatVar;
        char charVar;
    };
    struct UnionStructure
    {
        IntFloatCharUnion typeUnion;
        bool isInt;
        bool isFloat;
        bool isChar;
    };

    UnionStructure someStructure;
    someStructure.typeUnion.floatVar = 3.14; // Инициализируем float-значение
    someStructure.isFloat = true; // И ставим соответствующий флаг

    cout << someStructure.typeUnion.floatVar << " " << someStructure.isFloat << endl << endl;

    someStructure.typeUnion.charVar = 'z'; // Теперь используем char-значение
    someStructure.isFloat = false; // Ставим соответствующий флаг
    someStructure.isChar = true; // И убираем устаревший флаг

    cout << someStructure.typeUnion.floatVar << " " << someStructure.isFloat << endl; // Теперь вместо 3.14 будет мусор и isFloat = 0
    cout << someStructure.typeUnion.charVar << " " << someStructure.isChar << endl << endl;

    // Забегая вперед, к условиям, можно использовать примерно такие структуры
    someStructure.isInt = false;
    if (someStructure.isInt)
    {
        cout << someStructure.typeUnion.intVar << endl;
    }
    else if (someStructure.isFloat)
    {
        cout << someStructure.typeUnion.floatVar << endl;
    }
    else if (someStructure.isChar)
    {
        cout << someStructure.typeUnion.charVar << endl;
    }

    return 0;
}
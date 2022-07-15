// ZadchaO8ferj.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int board[8][8];

void setQueen(int i, int j)
{
    for (int x = 0; x < 8; ++x)
    {
        ++board[x][j];
        ++board[i][x];
        int foo;
        foo = j - i + x;
        if (foo >= 0 && foo < 8)
            ++board[x][foo];
        foo = j + i - x;
        if (foo >= 0 && foo < 8)
            ++board[x][foo];
    }
    board[i][j] = -1;
}

void resetQueen(int i, int j)
{
    for (int x = 0; x < 8; ++x)
    {
        --board[x][j];
        --board[i][x];
        int foo;
        foo = j - i + x;
        if (foo >= 0 && foo < 8)
            --board[x][foo];
        foo = j + i - x;
        if (foo >= 0 && foo < 8)
            --board[x][foo];
    }
    board[i][j] = 0;
}

bool tryQueen(int i)
{
    bool result = false;
    for (int j = 0; j < 8; ++j)
    {
        if (board[i][j] == 0)
        {
            setQueen(i, j);
            if (i == 7)
                result = true;
            else
            {
                if (!(result = tryQueen(i + 1)))
                    resetQueen(i, j);
            }
        }
        if (result)
            break;
    }
    return result;
}

int main()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = 0;
    tryQueen(0);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == -1)
                cout << "Q ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

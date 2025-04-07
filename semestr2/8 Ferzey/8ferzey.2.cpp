#include <iostream>
#include <iomanip>

using namespace std;

int board[8][8];

int chk(int c, int r)
{
    for (int i = 0; i < c; ++i)
    {
        // Проверка горизонтали
        if (board[i][r]) return 0;
        // Проверка диагонали
        if (r - c + i >= 0) if (board[i][r - c + i]) return 0;
        if (r + c - i < 8) if (board[i][r + c - i]) return 0;
    }
    return 1;
}

int vert(int i) // Установка i-й вертикали
{
    if (i == 8) return 1;
    for (int j = 0; j < 8; ++j)
        if (chk(i, j))
        {
            board[i][j] = 1;
            if (vert(i + 1)) return 1;
            board[i][j] = 0;
        }
    return 0;
}

int main(int argc, char* argv[])
{
    vert(0);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cout << (board[i][j] ? "$" : "+");
        cout << endl;
    }
}

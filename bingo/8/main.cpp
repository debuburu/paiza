#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<char>> bingo;
    for (int i = 0; i < 3; i++)
    {
        vector<char> row;
        string line;
        getline(cin, line);
        for (char c : line)
        {
            row.push_back(c);
        }
        bingo.push_back(row);
    }
    int bingo_line = 0;

    const char ok_symbol = '#';

    // 横ビンゴ
    bingo_line += (bingo[0][0] == ok_symbol && bingo[0][0] == bingo[0][1] && bingo[0][1] == bingo[0][2]) ? 1 : 0;
    bingo_line += (bingo[1][0] == ok_symbol && bingo[1][0] == bingo[1][1] && bingo[1][1] == bingo[1][2]) ? 1 : 0;
    bingo_line += (bingo[2][0] == ok_symbol && bingo[2][0] == bingo[2][1] && bingo[2][1] == bingo[2][2]) ? 1 : 0;

    // 縦ビンゴ
    bingo_line += (bingo[0][0] == ok_symbol && bingo[0][0] == bingo[1][0] && bingo[1][0] == bingo[2][0]) ? 1 : 0;
    bingo_line += (bingo[0][1] == ok_symbol && bingo[0][1] == bingo[1][1] && bingo[1][1] == bingo[2][1]) ? 1 : 0;
    bingo_line += (bingo[0][2] == ok_symbol && bingo[0][2] == bingo[1][2] && bingo[1][2] == bingo[2][2]) ? 1 : 0;

    // 斜めビンゴ
    bingo_line += (bingo[0][0] == ok_symbol && bingo[0][0] == bingo[1][1] && bingo[1][1] == bingo[2][2]) ? 1 : 0;
    bingo_line += (bingo[0][2] == ok_symbol && bingo[0][2] == bingo[1][1] && bingo[1][1] == bingo[2][0]) ? 1 : 0;

    cout << bingo_line << endl;
    return 0;
}
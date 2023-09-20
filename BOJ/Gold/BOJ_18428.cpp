// 2023.09.14
// 18428: 감시 피하기
// 골드 V
// https://www.acmicpc.net/problem/18428

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool isAvoidable(int n, vector<vector<char>>& board, vector<pair<int, int>>& teacherPos)
{
    int deltaX[4]{ 1,-1,0,0 };
    int deltaY[4]{ 0,0,1,-1 };

    for (pair<int, int> tPos : teacherPos)
    {
        int ty = tPos.first;
        int tx = tPos.second;
        for (int dir = 0; dir < 4; dir++)
        {
            for (int i = 1; ; i++)
            {
                int nextY = ty + deltaY[dir] * i;
                int nextX = tx + deltaX[dir] * i;
                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
                    break;
                if (board[nextY][nextX] == 'O' || board[nextY][nextX] == 'T')
                    break;
                if (board[nextY][nextX] == 'S')
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(int n, vector<vector<char>>& board, vector<pair<int, int>>& teacherPos, int obstacles, int cury, int curx)
{
    if (obstacles != 3)
    {
        int x = curx;
        for (int y = cury; y < n; y++)
        {
            for (; x < n; x++)
            {
                if (board[y][x] != 'X')
                    continue;
                board[y][x] = 'O';
                if (solve(n, board, teacherPos, obstacles + 1, y, x))
                    return true;
                board[y][x] = 'X';
            }
            x = 0;
        }
    }

    return isAvoidable(n, board, teacherPos);
}


int main()
{
    FASTIO;
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, 'X'));
    vector<pair<int, int>> teacherPos;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 'T')
                teacherPos.push_back({ y,x });
        }
    }

    // solve
    cout << (solve(n, board, teacherPos, 0, 0, 0) ? "YES" : "NO");
}
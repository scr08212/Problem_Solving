// 2023.09.14
// 9663: N-Queen
// °ñµå IV
// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int output = 0;

bool check(int n, vector<int>& board, int y)
{
    for (int i = 1; i <= y; i++)
    {
        if (abs(board[y] - board[y - i]) == i || board[y] - board[y - i] == 0)
            return false;
    }

    return true;
}

void solve(int n, vector<int>& board, int y)
{
    if (y == n)
    {
        output++;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        board[y] = x;
        if (check(n, board, y))
            solve(n, board, y + 1);
    }
}

int main()
{
    FASTIO;

    int n;
    cin >> n;

    vector<int> board(n, 0);
    solve(n, board, 0);

    cout << output;
}
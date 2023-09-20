// 2023.09.20
// 2828: 사과 담기 게임
// 실버 V
// https://www.acmicpc.net/problem/2828

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

int main()
{
    FASTIO;

    int n, m, j;
    cin >> n >> m >> j;
    vector<int> applesLoc(j, 0);
    for (int i = 0; i < j; i++)
        cin >> applesLoc[i];

    // solve

    int move = 0;
    int basketBegin = 1;
    for (int appleLoc : applesLoc)
    {
        int basketEnd = basketBegin + m - 1;

        if (appleLoc < basketBegin || basketEnd < appleLoc)
        {
            int dir = appleLoc < basketBegin ? -1 : 1; // -1: left  1: right
            int distance = dir == -1 ? basketBegin - appleLoc : appleLoc - basketEnd;
            move += distance;
            basketBegin += distance * dir;
        }
    }

    cout << move;
}
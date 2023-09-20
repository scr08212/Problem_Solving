// 2023.09.12
// 10971: 외판원 순회 2
// 실버 II
// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int solve(int n, int o, int start, int visitedCount, int cost, vector<vector<int>>& costs, vector<bool>& visited)
{
    if (start == o && visitedCount == n)
        return cost;

    int c = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (costs[start][i] == 0)
            continue;
        if (visited[i])
            continue;
        if (i == o && visitedCount != n - 1)
            continue;

        visited[i] = true;
        c = min(c, solve(n, o, i, visitedCount + 1, cost + costs[start][i], costs, visited));
        visited[i] = false;
    }

    return c;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<vector<int>> costs(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int r = 0; r < n; r++)
            cin >> costs[i][r];

    // Solve
    int output = INT_MAX;
    for (int start = 0; start < n; start++)
    {
        vector<bool> visited(n, false);
        output = min(output, solve(n, start, start, 0, 0, costs, visited));
    }

    cout << output;
}
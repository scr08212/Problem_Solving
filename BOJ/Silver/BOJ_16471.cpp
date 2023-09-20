// 2023.09.20
// 16471: 작은 수 내기
// 실버 III
// https://www.acmicpc.net/problem/16471

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

bool solve(int n, vector<int>& jNums, vector<int>& oNums)
{
    // two Pointer
    int jIndex = 0;
    int oIndex = 0;
    int count = 0;
    int needScore = (n + 1) / 2;

    while (jIndex < n && oIndex < n)
    {
        int jNum = jNums[jIndex];
        int oNum = oNums[oIndex];

        if (jNum >= oNum)
        {
            oIndex++;
        }
        else
        {
            count++;
            jIndex++;
            oIndex++;
            if (count == needScore)
                return true;
        }
    }

    return false;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;

    vector<int> jNums(n, 0), oNums(n, 0);

    for (int i = 0; i < n; i++)
        cin >> jNums[i];
    for (int i = 0; i < n; i++)
        cin >> oNums[i];

    sort(jNums.begin(), jNums.end());
    sort(oNums.begin(), oNums.end());

    cout << (solve(n, jNums, oNums) ? "YES" : "NO");
}
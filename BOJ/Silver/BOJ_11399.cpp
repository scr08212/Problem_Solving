// 2023.09.20
// 11399: ATM
// ½Ç¹ö IV
// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> times(n, 0);

    for (int i = 0; i < n; i++)
        cin >> times[i];

    sort(times.begin(), times.end());

    int output = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        prev = prev + times[i];
        output += prev;
    }

    cout << output;
}
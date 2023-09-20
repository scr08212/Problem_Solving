// 2023.09.20
// 2217: 로프
// 실버 IV
// https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int solve(int n, vector<int>& ropes)
{
    // Logic
    int minLength = INT_MAX;
    int count = 0;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        minLength = ropes[i];
        count++;
        int a = minLength * count;

        answer = max(a, answer);
    }

    return answer;
}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> ropes(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end(), greater<int>());
    cout << solve(n, ropes);
}
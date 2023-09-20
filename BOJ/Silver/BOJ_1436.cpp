// 2023.09.12
// 1436: 영화감독 숌
// 실버 V
// https://www.acmicpc.net/problem/1436

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool check(int num)
{
    while (num >= 666)
    {
        if (num % 1000 == 666)
            return true;

        num /= 10;
    }

    return false;
}

int main()
{
    FASTIO;
    int n, i;
    cin >> n;

    for (i = 666; n != 0; i++)
    {
        if (check(i))
        {
            n--;
            continue;
        }
    }

    cout << i - 1;
}
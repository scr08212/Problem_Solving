// 2023.09.12
// 2503: 숫자 야구
// 실버 III
// https://www.acmicpc.net/problem/2503

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool possibles[1000]{ false };
int n;

int getStrikeCount(int* target, int* num)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (target[i] == num[i])
            ret++;
    }

    return ret;
}

int getBallCount(int* target, int* num)
{
    int ret = 0;

    if (target[0] == num[1] || target[0] == num[2]) ret++;
    if (target[1] == num[0] || target[1] == num[2]) ret++;
    if (target[2] == num[0] || target[2] == num[1]) ret++;

    return ret;
}

void erase(int num, int strike, int ball)
{
    int nums[3]
    {
        num / 100,
        (num / 10) % 10,
        num % 10
    };

    for (int i = 123; i < 1000; i++)
    {
        int n[3]{ i / 100, (i / 10) % 10, i % 10 };
        int strikeCount = getStrikeCount(n, nums);
        int ballCount = getBallCount(n, nums);
        if (strikeCount != strike || ballCount != ball)
            possibles[i] = false;
    }
}

int main()
{
    FASTIO;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (j == i)
                continue;
            for (int k = 1; k <= 9; k++)
            {
                if (k == j || k == i)
                    continue;

                possibles[100 * i + 10 * j + k] = true;
            }
        }
    }

    cin >> n;
    while (n--)
    {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        erase(num, strike, ball);
    }

    int output = 0;
    for (int i = 123; i < 1000; i++)
        if (possibles[i])
            output++;

    cout << output;
}
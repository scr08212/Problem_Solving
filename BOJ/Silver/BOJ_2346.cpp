// 2023.10.05
// 2346: 숫자 카드
// 실버 III
// https://www.acmicpc.net/problem/2346

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

int main()
{
    int move[1001]{ 0 };
    deque<int> deq;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> move[i];
        deq.push_back(i);
    }

    while (true)
    {
        int offset = move[deq.front()];
        cout << deq.front() << ' ';
        deq.pop_front();

        if (deq.empty())
            break;

        if (offset > 0)
            offset--;

        while (offset != 0)
        {
            if (offset > 0)
            {
                deq.push_back(deq.front());
                deq.pop_front();
                offset--;
            }
            else
            {
                deq.push_front(deq.back());
                deq.pop_back();
                offset++;
            }
        }
    }
}
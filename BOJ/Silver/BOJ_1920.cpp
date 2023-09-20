// 2023.09.20
// 1920: 수 찾기
// 실버 IV
// https://www.acmicpc.net/problem/1920

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

bool hasTargetNum(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    FASTIO;

    int n, m;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    cin >> m;
    while (m--)
    {
        int target;
        cin >> target;

        cout << hasTargetNum(nums, target) << "\n";
    }
}
// 2023.09.22
// 10830: Çà·Ä Á¦°ö
// °ñµå IV
// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n;
long long int b;
vector<vector<int>> mat;

vector<vector<int>> multiplyMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
	vector<vector<int>> temp = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int value = 0;
			// multiply
			for (int offset = 0; offset < n; offset++)
			{
				value += ((mat1[i][offset] % 1000) * (mat2[offset][j] % 1000)) % 1000;
			}
			temp[i][j] = value;
		}
	}

	return temp;
}

vector<vector<int>> recursive(long long int n)
{
	if (n == 1)
	{
		return mat;
	}
	else if (n % 2 == 0)
	{
		auto m = recursive(n / 2);
		return multiplyMat(m, m);
	}
	else
	{
		return multiplyMat(recursive(n - 1), mat);
	}
}

int main()
{
	FASTIO;

	// Input
	cin >> n >> b;
	mat = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];


	// Solve
	auto output = recursive(b);

	// cout
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << output[i][j] % 1000 << ' ';
		}
		cout << "\n";
	}
}
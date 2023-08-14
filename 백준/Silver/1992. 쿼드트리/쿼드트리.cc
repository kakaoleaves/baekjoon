#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 64;

void quadTree(int x, int y, int n, int arr[][64])
{
	int first = arr[x][y];
	bool flag = true;

	for (int i = x; i < x + n; ++i)
	{
		for (int j = y; j < y + n; ++j)
		{
			if (first != arr[i][j])
			{
				flag = false;
				break;
			}
		}
	}

	if (flag)
	{
		cout << first;
	}
	else
	{
		cout << "(";
		quadTree(x, y, n / 2, arr);
		quadTree(x, y + n / 2, n / 2, arr);
		quadTree(x + n / 2, y, n / 2, arr);
		quadTree(x + n / 2, y + n / 2, n / 2, arr);
		cout << ")";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; // 1 <= n <= 64
	cin >> n;

	int arr[MAX][MAX];

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	quadTree(0, 0, n, arr);



	return 0;
}
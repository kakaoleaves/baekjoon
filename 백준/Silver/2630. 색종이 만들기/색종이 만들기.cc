#include <iostream>
using namespace std;

int white = 0;
int blue = 0;

void cut(int x, int y, int n, int arr[][128])
{
	int color = arr[x][y];
	bool isSame = true;

	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (color != arr[i][j])
			{
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame)
	{
		if (color == 0)
			white++;
		else
			blue++;
	}
	else
	{
		cut(x, y, n / 2, arr);
		cut(x + n / 2, y, n / 2, arr);
		cut(x, y + n / 2, n / 2, arr);
		cut(x + n / 2, y + n / 2, n / 2, arr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;  // 2^1<= n <= 2^7
	int arr[128][128];
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cut(0, 0, n, arr);

	cout << white << '\n' << blue << '\n';

	return 0;
}
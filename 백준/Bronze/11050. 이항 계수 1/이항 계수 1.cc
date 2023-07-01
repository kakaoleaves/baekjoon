#include <iostream>
#include <cmath>
using namespace std;

int pascal[11][11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				pascal[i][j] = 1;
			else
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	int n, k;
	cin >> n >> k;

	cout << pascal[n][k] << '\n';

	return 0;
}
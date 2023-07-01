#include <iostream>
#include <cmath>
using namespace std;

int pascal[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				pascal[i][j] = 1;
			else
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cout << pascal[m][n] << '\n';
	}

	return 0;
}
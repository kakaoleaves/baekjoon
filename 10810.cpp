#include <iostream>
using namespace std;

int main(void)
{
	int n, m, i, j ,k;
	int arr[100] = {};
	cin >> n >> m;

	for (int a = 0; a < m; a++)
	{
		cin >> i >> j >> k;
		for (int b = (i - 1); b < j; b++)
			arr[b] = k;
	}

	for (int a = 0; a < n; a++)
		cout << arr[a] << ' ';
	cout << endl;

	return 0;
}
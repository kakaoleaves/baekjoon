#include <iostream>
using namespace std;

int main(void)
{
	int n, m, i, j;
	int arr[100] = {};
	cin >> n >> m;

	for (int a = 0; a < n; a++)
		arr[a] = a + 1;

	for (int a = 0; a < m; a++)
	{
		cin >> i >> j;
		int temp;
		temp = arr[i - 1];
		arr[i - 1] = arr[j - 1];
		arr[j - 1] = temp;
	}

	for (int a = 0; a < n; a++)
		cout << arr[a] << ' ';
	cout << endl;

	return 0;
}
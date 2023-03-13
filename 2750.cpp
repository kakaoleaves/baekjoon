#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, arr[1000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}
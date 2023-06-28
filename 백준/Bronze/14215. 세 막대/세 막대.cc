#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[3] = { 0, };
	int max = 0;
	int sum = 0;

	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i];
		assert(arr[i] >= 1 && arr[i] <= 100);
		sum += arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	if (sum - max <= max)
		cout << 2 * (sum - max) - 1 << endl;
	else
		cout << sum << endl;

	return 0;
}
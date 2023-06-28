#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[3] = { -1, -1, -1 };
	int sum = 0;
	int max = 0;

	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			if (max < arr[i])
			{
				max = arr[i];
			}
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		if (sum - max <= max)
			cout << "Invalid" << endl;
		else
		{
			if (arr[0] == arr[1] && arr[1] == arr[2])
				cout << "Equilateral" << endl;
			else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
				cout << "Isosceles" << endl;
			else
				cout << "Scalene" << endl;
		}

		max = 0;
		sum = 0;
	}

	return 0;
}
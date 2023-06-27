#include <iostream>
using namespace std;

const int ROW = 9;
const int COL = 9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[ROW][COL] = { 0, };
	int max = 0;
	int max_i = 0;
	int max_j = 0;

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << max << endl;
	cout << max_i + 1 << " " << max_j + 1 << endl;
		
	return 0;
}
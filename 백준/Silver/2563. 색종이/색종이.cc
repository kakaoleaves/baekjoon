#include <iostream>
#include <cstring>
using namespace std;

const int N = 100;
const int M = 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[N][N] = { 0 };
	int n = 0;
	int result = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
			{
				arr[x + j][M - y + k] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1) result++;

	cout << result << endl;
		
	return 0;
}
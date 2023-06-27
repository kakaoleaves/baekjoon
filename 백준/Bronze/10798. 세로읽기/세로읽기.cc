#include <iostream>
#include <cstring>
using namespace std;

const int ROW = 5;
const int COL = 15;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char input[COL + 1];
	char arr[ROW][COL] = { NULL,};
	
	for (int i = 0; i < ROW; i++)
	{
		cin >> input;
		int len = strlen(input);
		for (int j = 0; j < len; j++)
		{
			arr[i][j] = input[j];
		}
	}

	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[j][i] != NULL)
				cout << arr[j][i];
		}
	}
		
	return 0;
}
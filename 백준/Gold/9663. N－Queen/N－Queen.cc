#include <iostream>
#include <vector>
using namespace std;

int solution = 0;

bool isSafe(vector<int>& queens, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (queens[i] == col || abs(queens[i] - col) == row - i)
			return false;
	}
	return true;
}

void backtrack(vector<int>& queens, int n, int row = 0)
{
	if (row == n)
	{
		solution++;
		return;
	}
	for (int col = 0; col < n; col++)
	{
		if (isSafe(queens, row, col))
		{
			queens[row] = col;
			backtrack(queens, n, row + 1);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> queens(n);
	backtrack(queens, n);

	cout << solution << '\n';
	return 0;
}
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

#define SUDOKU_SIZE 9
#define SMALL_SUDOKU_SIZE 3

void print(vector<vector<int>> const& s)
{
	for (auto const& i : s)
	{
		for (auto const& j : i)
			cout << j << " ";
		cout << "\n";
	}
}

bool isSafe(vector<vector<int>>& s, int row, int col, int num)
{
	for (int i = 0; i < SUDOKU_SIZE; i++)
		if (s[row][i] == num)
			return false;

	for (int i = 0; i < SUDOKU_SIZE; i++)
		if (s[i][col] == num)
			return false;

	int smallRow = row - row % SMALL_SUDOKU_SIZE;
	int smallCol = col - col % SMALL_SUDOKU_SIZE;

	for (int i = 0; i < SMALL_SUDOKU_SIZE; i++)
		for (int j = 0; j < SMALL_SUDOKU_SIZE; j++)
			if (s[i + smallRow][j + smallCol] == num)
				return false;
	
	return true;
}

bool solveSudoku(vector<vector<int>>& s, int row, int col)
{
	if (row == SUDOKU_SIZE - 1 && col == SUDOKU_SIZE)
		return true;
	
	if (col == SUDOKU_SIZE)
	{
		row++;
		col = 0;
	}

	if (s[row][col] > 0)
		return solveSudoku(s, row, col + 1);

	for (int num = 1; num <= SUDOKU_SIZE; num++)
	{
		if (isSafe(s, row, col, num))
		{
			s[row][col] = num;

			if (solveSudoku(s, row, col + 1))
				return true;
		}

		s[row][col] = 0;
	}

	return false;
}

int main()
{
	fastio;

	vector<vector<int>> sudoku(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE, 0));

	for (auto& i : sudoku)
		for (auto& j : i)
			cin >> j;

	if (solveSudoku(sudoku, 0, 0))
		print(sudoku);
	else
		cout << "No solution exists";

	return 0;
}
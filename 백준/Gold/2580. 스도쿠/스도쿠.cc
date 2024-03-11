#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<short>> sudoku(9, vector<short>(9, 0));
vector<pair<short, short>> targets;

bool CheckRow(short i, short j, short num) {
	for (int k = 0; k < 9; k++) {
		if (sudoku[i][k] == num) {
			return false;
		}
	}
	return true;
}

bool CheckCol(short i, short j, short num) {
	for (int k = 0; k < 9; k++) {
		if (sudoku[k][j] == num) {
			return false;
		}
	}
	return true;
}

bool CheckSquare(short i, short j, short num) {
		short startRow = i - i % 3;
	short startCol = j - j % 3;
	for (int k = startRow; k < startRow + 3; k++) {
		for (int l = startCol; l < startCol + 3; l++) {
			if (sudoku[k][l] == num) {
				return false;
			}
		}
	}
	return true;
}

void SolveSudoku(int idx) {
	if (idx == targets.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	for (int i = idx; i < targets.size(); i++) {
		short row = targets[i].first;
		short col = targets[i].second;
		for (short j = 1; j <= 9; j++) {
			if (CheckRow(row, col, j) && CheckCol(row, col, j) && CheckSquare(row, col, j)) {
				sudoku[row][col] = j;
				SolveSudoku(idx + 1);
				sudoku[row][col] = 0;
			}
		}
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				targets.push_back({ i, j });
			}
		}
	}

	SolveSudoku(0);

	return 0;
}

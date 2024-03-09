#include <iostream>
#include <vector>
using namespace std;

int n; // 3 <= n <= 3^8
vector<vector<char>> star;

void CantorStar(int x1, int x2, int y1, int y2) {
	if (x2 - x1 < 3 && y2 - y1 < 3) {
		star[x1 + 1][y1 + 1] = ' ';
	}
	else {
		int x = (x2 - x1 + 1) / 3;
		int y = (y2 - y1 + 1) / 3;

		for (int i = x1 + x; i < x1 + 2 * x; i++) {
			for (int j = y1 + y; j < y1 + 2 * y; j++) {
				star[i][j] = ' ';
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!(i == 1 && j == 1)) {
					CantorStar(x1 + i * x, x1 + (i + 1) * x - 1, y1 + j * y, y1 + (j + 1) * y - 1);
				}
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;


	star.resize(n, vector<char>(n, '*'));

	CantorStar(0, n - 1, 0, n - 1);

	for (auto& row : star) {
		for (auto& e : row) {
			cout << e;
		}
		cout << '\n';
	}

	return 0;
}
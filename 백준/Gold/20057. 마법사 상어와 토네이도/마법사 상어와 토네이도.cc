#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n; // 3 <= n <= 499, 홀수
int tor_x;
int tor_y;
int tor_d;
int ans;

const vector<int> dx = { 0, 1, 0, -1 };
const vector<int> dy = { -1, 0, 1, 0 };

const vector<vector<int>> ratio = {
	{
		0, 0, 2, 0, 0,
		0, 10, 7, 1, 0,
		5, 0, 0, 0, 0,
		0, 10, 7, 1, 0,
		0, 0, 2, 0, 0
	},
	{
		0, 0, 0, 0, 0,
		0, 1, 0, 1, 0,
		2, 7, 0, 7, 2,
		0, 10, 0, 10, 0,
		0, 0, 5, 0, 0
	},
	{
		0, 0, 2, 0, 0,
		0, 1, 7, 10, 0,
		0, 0, 0, 0, 5,
		0, 1, 7, 10, 0,
		0, 0, 2, 0, 0
	},
	{
		0, 0, 5, 0, 0,
		0, 10, 0, 10, 0,
		2, 7, 0, 7, 2,
		0, 1, 0, 1, 0,
		0, 0, 0, 0, 0
	}
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	// 시작점에 대한 초기화
	tor_x = n / 2;
	tor_y = n / 2;
	tor_d = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (n == i && j == 1) break; // 마지막에는 한번만 진행
			for (int k = 0; k < i; k++) {
				tor_x += dx[tor_d];
				tor_y += dy[tor_d];

				if (tor_x < 0 || tor_x >= n || tor_y < 0 || tor_y >= n) break;

				int total = board[tor_x][tor_y];

				for (int a = 0; a < 5; a++) {
					int nx = tor_x + a - 2;
					for (int b = 0; b < 5; b++) {
						int ny = tor_y + b - 2;
						int sand = ratio[tor_d][a * 5 + b] * board[tor_x][tor_y] / 100;
						total -= sand;
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) { // 범위를 벗어난 경우
							ans += sand;
						}
						else { // 범위에 있는 경우
							board[nx][ny] += sand;
						}
					}
				}

				int alpha_x = tor_x + dx[tor_d];
				int alpha_y = tor_y + dy[tor_d];

				if (alpha_x < 0 || alpha_x >= n || alpha_y < 0 || alpha_y >= n) { // 알파 위치가 범위를 벗어난 경우
					ans += total;
				}
				else { // 알파 위치가 범위에 있는 경우
					board[alpha_x][alpha_y] += total;
				}

				board[tor_x][tor_y] = 0; // 이동한 위치의 모래를 없애준다.
			}
			tor_d = (tor_d + 1) % 4;

			if (tor_x == 0 && tor_y == 0) break;
		}
	}

	cout << ans << "\n";

	return 0;
}
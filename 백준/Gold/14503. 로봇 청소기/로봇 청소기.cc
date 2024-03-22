#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum {
	DIRTY,
	WALL,
	CLEAN,
	ROBOT
};

vector<int> dx = { -1, 0, 1, 0 };
vector<int> dy = { 0, 1, 0, -1 };

int n, m; // 3 <= n, m <= 50
int r, c; // 로봇 청소기의 좌표
int d; // 로봇 청소기의 방향
vector<vector<int>> room(50, vector<int>(50, 0));
int ans;

void RobotCleaner() {
	if (room[r][c] == DIRTY) {
		room[r][c] = CLEAN;
		ans++;
	} 

	for (int i = 0; i < 4; i++) {
		int next_d = (d + 3) % 4;
		int nx = r + dx[next_d];
		int ny = c + dy[next_d];

		bool x_range = nx >= 0 && nx < n;
		bool y_range = ny >= 0 && ny < m;

		if (x_range && y_range && room[nx][ny] == DIRTY) {
			r = nx;
			c = ny;
			d = next_d;
			RobotCleaner();
			return;
		}
		else {
			d = next_d;
		}
	}

	int back_d = (d + 2) % 4;
	int bx = r + dx[back_d];
	int by = c + dy[back_d];

	bool x_range = bx >= 0 && bx < n;
	bool y_range = by >= 0 && by < m;

	if (x_range && y_range && room[bx][by] != WALL) {
		r = bx;
		c = by;
		RobotCleaner();
	}
	else {
		return;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	room.resize(n, vector<int>(m, 0));

	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];

	RobotCleaner();

	cout << ans << '\n';

	return 0;
}
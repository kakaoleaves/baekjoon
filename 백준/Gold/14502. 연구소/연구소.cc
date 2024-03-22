#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

enum {
	BLANK,
	WALL,
	VIRUS
};

int n, m; // 3 <= n, m <= 8
vector<vector<short>> lab(8, vector<short>(8, BLANK));
vector<pair<int, int>> viruses;
int ans;

void SpreadVirus(vector<vector<short>>& v) {
	queue<pair<int, int>> q;
	for (auto& virus : viruses) {
		q.push(virus);
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;

		if (x - 1 >= 0 && v[x - 1][y] == BLANK) {
			v[x - 1][y] = VIRUS;
			q.push({ x - 1, y });
		}

		if (x + 1 < n && v[x + 1][y] == BLANK) {
			v[x + 1][y] = VIRUS;
			q.push({ x + 1, y });
		}

		if (y - 1 >= 0 && v[x][y - 1] == BLANK) {
			v[x][y - 1] = VIRUS;
			q.push({ x, y - 1 });
		}

		if (y + 1 < m && v[x][y + 1] == BLANK) {
			v[x][y + 1] = VIRUS;
			q.push({ x, y + 1 });
		}
	}

	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			safe += (v[i][j] == BLANK);
		}
	}

	ans = max(ans, safe);
}

void Backtracking(int x, int y, int cnt) {
	if (cnt == 3) {
		// spread virus
		vector<vector<short>> v = lab;
		SpreadVirus(v);
		return;
	}

	for (int i = x; i < n; i++) {
		for (int j = (i == x ? y : 0); j < m; j++) {
			if (lab[i][j] == BLANK) {
				lab[i][j] = WALL;
				Backtracking(i, j, cnt + 1);
				lab[i][j] = BLANK;
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == VIRUS) {
				viruses.push_back({ i, j });
			}
		}
	}

	Backtracking(0, 0, 0);

	cout << ans << '\n';
	
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> office(8, vector<int>(8));
vector<pair<int, int>> cctvs;
int min_blind_spot = 64;

const vector<int> dx = { -1, 0, 1, 0 };
const vector<int> dy = { 0, 1, 0, -1 };
const vector<vector<vector<int>>> cctv_dir = {
	{},
	{ {0}, {1}, {2}, {3} },
	{ {0, 2}, {1, 3} },
	{ {0, 1}, {1, 2}, {2, 3}, {3, 0} },
	{ {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} },
	{ {0, 1, 2, 3} }
};

void backtracking(int idx) {
	if (idx == cctvs.size()) {
		int blind_spot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (office[i][j] == 0) {
					blind_spot++;
				}
			}
		}
		min_blind_spot = min(min_blind_spot, blind_spot);
		return;
	}

	int x = cctvs[idx].first;
	int y = cctvs[idx].second;
	int cctv_num = office[x][y];

	for (int i = 0; i < cctv_dir[cctv_num].size(); i++) {

		vector<vector<int>> temp = office;

		for (int j = 0; j < cctv_dir[cctv_num][i].size(); j++) {
			int dir = cctv_dir[cctv_num][i][j];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (office[nx][ny] == 6) {
					break;
				}
				if (office[nx][ny] == 0) {
					office[nx][ny] = -1;
				}
				nx += dx[dir];
				ny += dy[dir];
			}
		}
		backtracking(idx + 1);
		office = temp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	office.resize(n);

	for (int i = 0; i < n; i++)
	{
		office[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5)
			{
				cctvs.push_back({ i, j });
			}
		}
	}

	backtracking(0);

	cout << min_blind_spot << '\n';
	return 0;
}
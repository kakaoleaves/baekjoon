#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // 2 <= n <= 50
int m; // 1 <= m <= 100
vector<vector<int>> grid;
vector<pair<int, int>> moves;
vector<pair<int, int>> cloud;

int ans;

const vector<int> dirx = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
const vector<int> diry = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

const vector<int> dx = { -1, -1, 1, 1 };
const vector<int> dy = { -1, 1, 1, -1 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	grid.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
		moves.push_back({ d, s });
	}

	// 초기 구름 생성
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cloud.push_back({ i + n - 2, j });
		}
	}

	// 이동
	for (int i = 0; i < m; i++)
	{
		auto [d, s] = moves[i];
		vector<pair<int, int>> water_copy;

		// 구름 이동
		for (int j = 0; j < cloud.size(); j++) {
			auto [y, x] = cloud[j];
			int nx = x + dirx[d] * s;
			int ny = y + diry[d] * s;

			nx = (nx % n + n) % n;
			ny = (ny % n + n) % n;

			grid[ny][nx]++;

			water_copy.push_back({ ny, nx });
		}

		// 구름 제거
		cloud.clear();

		// 물복사 버그
		for (int j = 0; j < water_copy.size(); j++)
		{
			auto [y, x] = water_copy[j];
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (grid[ny][nx] > 0) grid[y][x]++;
			}
		}

		// 구름 생성
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (grid[x][y] >= 2 && find(water_copy.begin(), water_copy.end(), make_pair(x, y)) == water_copy.end())
				{
					grid[x][y] -= 2;
					cloud.push_back({ x, y });
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += grid[i][j];
		}
	}

	cout << ans << "\n";

	return 0;
}
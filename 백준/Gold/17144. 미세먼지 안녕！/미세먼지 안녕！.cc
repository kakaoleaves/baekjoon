#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int r;
int c;
int t;
int ans;
vector<vector<int>> room(51, vector<int>(51, 0));

vector<pair<int, int>> air_cleaner_pos;
const int air_cleaner = -1;
const vector<int> dx = { 0,0,-1,1 };
const vector<int> dy = { -1,1,0,0 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == air_cleaner)
			{
				air_cleaner_pos.push_back({ i,j });
			}
		}
	}

	while (t--)
	{
		vector<vector<int>> temp(51, vector<int>(51, 0));

		// 미세먼지 확산 정보 저장
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (room[i][j] > 0)
				{
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && room[nx][ny] != air_cleaner)
						{
							temp[nx][ny] += room[i][j] / 5;
							temp[i][j] -= room[i][j] / 5;
						}
					}
				}
			}
		}

		// 확산 적용
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				room[i][j] += temp[i][j];
			}
		}

		// 공기청정기 작동
		auto [x1, y] = air_cleaner_pos.front();
		auto [x2, _] = air_cleaner_pos.back();

		for (int i = x1 - 1; i >= 2; i--)
		{
			room[i][1] = room[i - 1][1];
		}

		for (int i = x2 + 1; i < r; i++)
		{
			room[i][1] = room[i + 1][1];
		}

		for (int i = 1; i < c; i++)
		{
			room[1][i] = room[1][i + 1];
			room[r][i] = room[r][i + 1];
		}

		for (int i = 1; i < x1; i++)
		{
			room[i][c] = room[i + 1][c];
		}

		for (int i = r; i > x2; i--)
		{
			room[i][c] = room[i - 1][c];
		}

		for (int i = c; i > y + 1; i--)
		{
			room[x1][i] = room[x1][i - 1];
			room[x2][i] = room[x2][i - 1];
		}

		room[x1][y + 1] = 0;
		room[x2][y + 1] = 0;
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (room[i][j] > 0)
			{
				ans += room[i][j];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
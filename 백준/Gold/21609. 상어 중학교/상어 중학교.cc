#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

vector<int> dr = { -1, 0, 1, 0 };
vector<int> dc = { 0, 1, 0, -1 };

int n; // 격자의 크기; 1 <= n <= 20
int m; // 가능한 색상 수; 1 <= m <= 5

enum { BLACK = 6, RAINBOW = 7 };

vector<vector<int>> board(21, vector<int>(21, 0));
int score = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	board.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;
			if (num == 0) board[i][j] = RAINBOW;
			else if (num == -1) board[i][j] = BLACK;
			else board[i][j] = num;
		}
	}

	while (true)
	{
		vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
		vector<vector<int>> group(n + 1, vector<int>(n + 1, 0));

		int max_size = -1;
		int max_group = -1;
		int max_rainbow = -1;

		for (int r = 1; r <= n; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				int sz = 0;
				int rainbow = 0;
				if (visited[r][c]) continue; // 이미 방문한 셀은 무시 (그룹화되었으므로)
				if (board[r][c] == 0) continue; // 빈 셀은 무시
				if (board[r][c] == BLACK || board[r][c] == RAINBOW) continue; // 검은색 또는 무지개 색상은 무시

				// BFS로 그룹화
				queue<pair<int, int>> q;
				vector<vector<int>> tmp_group = group; // 그룹화 결과를 임시로 저장
				group = vector<vector<int>>(n + 1, vector<int>(n + 1, 0)); // 그룹화 결과 초기화

				// RAINBOW 방문 여부 초기화 (무지개 색상은 모든 색상의 그룹화에 포함가능하므로)
				for (int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)
					{
						if (board[i][j] == RAINBOW)
							visited[i][j] = false;
					}
				}

				q.push({ r, c });
				visited[r][c] = true;
				group[r][c] = r * (n + 1) + c;
				sz++;

				while (!q.empty())
				{
					auto [tr, tc] = q.front(); q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nr = tr + dr[i];
						int nc = tc + dc[i];

						if (nr < 1 || nr > n || nc < 1 || nc > n) continue; // 범위를 벗어난 셀은 무시
						if (visited[nr][nc]) continue; // 이미 방문한 셀은 무시
						if (board[nr][nc] == 0) continue; // 빈 셀은 무시
						if (board[nr][nc] != board[r][c] && board[nr][nc] != RAINBOW) continue; // 색상이 다르면 무시 (무지개 색상은 무시하지 않음)
						if (board[nr][nc] == BLACK) continue; // 검은색은 무시

						if (board[nr][nc] == RAINBOW) rainbow++;

						visited[nr][nc] = true;
						group[nr][nc] = group[r][c];
						q.push({ nr, nc });
						sz++;
					}
				}

				if (sz >= 2)
				{
					if (max_size < sz)
					{
						max_size = sz;
						max_group = group[r][c];
						max_rainbow = rainbow;
					}
					else if (max_size == sz)
					{
						if (max_rainbow < rainbow)
						{
							max_rainbow = rainbow;
							max_group = group[r][c];
						}
						else if (max_rainbow == rainbow)
						{
							if (max_group < group[r][c])
							{
								max_group = group[r][c];
							}
						}
						else
						{
							group = tmp_group;
						}
					}
					else
					{
						group = tmp_group;
					}
				}
				else
				{
					group = tmp_group;
				}
			}
		}

		if (max_group == -1 && max_size == -1) break;

		// 그룹화된 셀 제거
		for (int r = 1; r <= n; r++)
		{
			for (int c = 1; c <= n; c++)
			{
				if (group[r][c] == max_group)
				{
					board[r][c] = 0;
				}
			}
		}

		// 점수 계산
		score += max_size * max_size;

		// 중력 작용
		for (int c = 1; c <= n; c++)
		{
			vector<int> tmp;
			for (int r = 1; r <= n; r++)
			{
				tmp.push_back(board[r][c]);
			}

			int idx = 0;
			while (idx < n)
			{
				auto it = find(tmp.begin() + idx, tmp.end(), BLACK); // 검은색 셀을 찾음
				if (it == tmp.end()) 
				{
					// 남은 부분에 검은색 셀이 없음 -> 바닥까지 중력 작용
					stable_partition(tmp.begin() + idx, tmp.end(), [](int x) { return x == 0; });
					break;
				}
				else
				{
					// 검은색 셀 전까지 중력 작용
					stable_partition(tmp.begin() + idx, it, [](int x) { return x == 0; });
					// 검은색 셀은 그대로 위치 변화가 없고, 다음 타겟은 그 다음임.
					idx = distance(tmp.begin(), it) + 1;
				}
			}

			// 중력 작용 결과를 board에 반영
			for (int r = 1; r <= n; r++)
			{
				board[r][c] = tmp[r - 1];
			}
		}

		// 반시계 방향으로 90도 회전
		vector<vector<int>> tmp_board = board;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = tmp_board[j][n - i + 1];
			}
		}


		// 다시 중력 작용
		for (int c = 1; c <= n; c++)
		{
			vector<int> tmp;
			for (int r = 1; r <= n; r++)
			{
				tmp.push_back(board[r][c]);
			}

			int idx = 0;
			while (idx < n)
			{
				auto it = find(tmp.begin() + idx, tmp.end(), BLACK); // 검은색 셀을 찾음
				if (it == tmp.end())
				{
					// 남은 부분에 검은색 셀이 없음 -> 바닥까지 중력 작용
					stable_partition(tmp.begin() + idx, tmp.end(), [](int x) { return x == 0; });
					break;
				}
				else
				{
					// 검은색 셀 전까지 중력 작용
					stable_partition(tmp.begin() + idx, it, [](int x) { return x == 0; });
					// 검은색 셀은 그대로 위치 변화가 없고, 다음 타겟은 그 다음임.
					idx = distance(tmp.begin(), it) + 1;
				}
			}

			// 중력 작용 결과를 board에 반영
			for (int r = 1; r <= n; r++)
			{
				board[r][c] = tmp[r - 1];
			}
		}
	}

	cout << score << "\n";

	return 0;
}

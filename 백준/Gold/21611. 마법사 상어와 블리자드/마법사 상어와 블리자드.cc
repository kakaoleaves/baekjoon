#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N; // 격자 크기(홀수); 3 <= N <= 49
int M; // 블리자드 구슬을 쏘는 횟수; 1 <= M <= 100

vector<vector<int>> grid(50, vector<int>(50, 0));
vector<pair<int,int>> blizzards(100);

enum {UP = 1, DOWN, LEFT, RIGHT };

const vector<int> dc = { 0, 0, 0, -1, 1 };
const vector<int> dr = { 0, -1, 1, 0, 0 };

int score;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	grid.resize(N + 1, vector<int>(N + 1, 0));
	blizzards.resize(M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int d, s;
		cin >> d >> s;
		blizzards[i] = { d, s };
	}

	const int center = N / 2 + 1;

	for (auto& b : blizzards)
	{
		const auto& [d, s] = b;

		// 1. 구슬을 쏴서 파괴
		for (int i = 1; i <= s; i++)
		{
			int nr = center + dr[d] * i;
			int nc = center + dc[d] * i;

			grid[nr][nc] = 0;
		}


		// 2. 순서에 맞게 구슬을 배열에 넣는다.
		deque<int> tmp;
		int cnt = 1;
		int r, c, dir;
		r = c = center;
		dir = LEFT;

		while (r != 1 || c != 1)
		{
			for (int i = 1; i <= 2; i++)
			{
				for (int j = 1; j <= cnt; j++)
				{
					r += dr[dir];
					c += dc[dir];

					if (grid[r][c] != 0)
					{
						tmp.push_back(grid[r][c]);
					}

					if (r == 1 && c == 1) break;
				}
				if (r == 1 && c == 1) break;

				if (dir == LEFT) dir = DOWN;
				else if (dir == DOWN) dir = RIGHT;
				else if (dir == RIGHT) dir = UP;
				else if (dir == UP) dir = LEFT;
			}
			cnt++;
		}

		// 배열에서 연속 4개 이상 나오는 구슬을 제거한다.

		while (true)
		{
			vector<pair< deque<int>::iterator, deque<int>::iterator>> targets;
			auto it = tmp.begin();
			while (it != tmp.end())
			{
				auto next = find_if(it, tmp.end(), [it](int x) { return x != *it; });

				if (distance(it, next) >= 4)
				{
					targets.push_back({ it, next });
					score += (*it) * distance(it, next);
				}
				it = next;
			}

			if (targets.empty()) break;

			for (const auto& t : targets)
			{
				// 해당 부분을 0으로 만든다
				fill(t.first, t.second, 0);
			}

			// 배열을 정리한다.
			tmp.erase(remove(tmp.begin(), tmp.end(), 0), tmp.end());
		}

		// 배열을 그룹화한다.
		vector<pair<int, int>> groups; //  개수, 번호

		auto it = tmp.begin();
		while (it != tmp.end())
		{
			auto next = find_if(it, tmp.end(), [it](int x) { return x != *it; });

			groups.push_back({ distance(it, next), *it });

			it = next;
		}

		// 배열을 재배열한다.
		tmp.clear();
		for (const auto& g : groups)
		{
			tmp.push_back(g.first);
			tmp.push_back(g.second);
		}

		// 배열을 다시 격자에 넣는다.
		r = c = center;
		dir = LEFT;
		cnt = 1;
		it = tmp.begin();

		grid.assign(N + 1, vector<int>(N + 1, 0));

		while (r != 1 || c != 1)
		{
			for (int i = 1; i <= 2; i++)
			{
				for (int j = 1; j <= cnt; j++)
				{
					r += dr[dir];
					c += dc[dir];

					if (it != tmp.end())
					{
						grid[r][c] = *it;
						it++;
					}
					else
					{
						grid[r][c] = 0;
					}

					if (r == 1 && c == 1) break;
				}
				if (r == 1 && c == 1) break;

				if (dir == LEFT) dir = DOWN;
				else if (dir == DOWN) dir = RIGHT;
				else if (dir == RIGHT) dir = UP;
				else if (dir == UP) dir = LEFT;
			}
			cnt++;
		}

		//cout << "After " << (d) << " " << (s) << endl;
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << grid[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}

	cout << score << endl;

	return 0;
}

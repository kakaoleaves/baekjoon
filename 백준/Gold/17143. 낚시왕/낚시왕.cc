#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <deque>

using namespace std;

int R; // 행; 2 <= r <= 100
int C; // 열; 2 <= c <= 100
int M; // 상어의 수; 0<= m <= r * c

struct Shark
{
	int id; // 상어의 고유 번호; 1<= id <= M
	int r; // 행; 1<= r <= R
	int c; // 열; 1<= c <= C
	int s; // 속력; 0<= s <= 1000
	int d; // 이동 방향; 1<= d <= 4
	int z; // 크기; 1<= z <= 10000

	bool operator<(const Shark& s) const
	{
		return z < s.z;
	}
	bool operator>(const Shark& s) const
	{
		return z > s.z;
	}
};

enum { UP = 1, DOWN, RIGHT, LEFT };
const vector<int> dr = { 0, -1, 1, 0, 0 };
const vector<int> dc = { 0, 0, 0, 1, -1 };

vector<Shark> sharks(10000);
vector<vector<int>> board(101, vector<int>(101));
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> M;

	board.resize(R + 1, vector<int>(C + 1));
	sharks.resize(M + 1);

	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i] = { i, r, c, s, d, z };
		board[r][c] = i; // 상어의 고유 번호를 저장
	}

	deque<int> alive(M, 0);

	for (int i = 0; i < M; i++)
	{
		alive[i] = i + 1;
	}

	sort(alive.begin(), alive.end(), [&](int a, int b) {return sharks[a].z < sharks[b].z; });

	for (int i = 1; i <= C; i++)
	{
		if (alive.empty()) break;

		int caught = -1;

		for (int j = 1; j <= R; j++)
		{
			if (board[j][i] != 0) {
				caught = board[j][i];
				break;
			}
		}

		if (caught != -1)
		{
			ans += sharks[caught].z;
			auto it = find(alive.begin(), alive.end(), caught);
			if (it != alive.end()) alive.erase(it);
		}

		board.assign(R + 1, vector<int>(C + 1, 0));

		vector<int> tmp;

		for (const int& id : alive)
		{
			auto& shark = sharks[id];
			auto& [_, r, c, s, d, z] = shark;

			int nr = r + dr[d] * s;
			int nc = c + dc[d] * s;
			int nd = d;

			if (nr < 1) // 상어가 위로 벗어난 경우
			{
				int mv = 1 - nr; // 벗어난 칸 수

				int q = mv / (R - 1);
				int rest = mv % (R - 1);

				if (rest != 0) q++;
				else rest = R - 1;

				nd = (q % 2 == 0) ? UP : DOWN;
				nr = (nd == DOWN ? 1 + rest : R - rest);
			}
			else if (nr > R) // 상어가 아래로 벗어난 경우
			{
				int mv = nr - R; // 벗어난 칸 수

				int q = mv / (R - 1);
				int rest = mv % (R - 1);

				if (rest != 0) q++;
				else rest = R - 1;

				nd = (q % 2 == 0) ? DOWN : UP;
				nr = (nd == DOWN ? 1 + rest : R - rest);
			}

			if (nc < 1) // 상어가 왼쪽으로 벗어난 경우
			{
				int mv = 1 - nc; // 벗어난 칸 수

				int q = mv / (C - 1);
				int rest = mv % (C - 1);

				if (rest != 0) q++;
				else rest = C - 1;

				nd = (q % 2 == 0) ? LEFT : RIGHT;
				nc = (nd == LEFT ? C - rest : 1 + rest);
			}
			else if (nc > C) // 상어가 오른쪽으로 벗어난 경우
			{
				int mv = nc - C; // 벗어난 칸 수

				int q = mv / (C - 1);
				int rest = mv % (C - 1);

				if (rest != 0) q++;
				else rest = C - 1;

				nd = (q % 2 == 0) ? RIGHT : LEFT;
				nc = (nd == LEFT ? C - rest : 1 + rest);
			}

			r = nr;
			c = nc;
			d = nd;

			if (board[nr][nc] != 0)
				tmp.push_back(board[nr][nc]);
			board[nr][nc] = id; // 상어의 고유 번호를 저장
		}

		for (const int& id : tmp)
		{
			auto it = find(alive.begin(), alive.end(), id);
			if (it != alive.end()) alive.erase(it);
		}
		tmp.clear();
	}

	cout << ans << '\n';

	return 0;
}

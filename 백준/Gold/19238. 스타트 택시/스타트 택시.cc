#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const vector<int> dr = {0, 0, 1, -1};
const vector<int> dc = {1, -1, 0, 0};

int n; // 지도의 크기; 2 <= n <= 20
int m; // 태울 승객의 수; 1 <= m <= 400
int fuel; // 초기 연료의 양; 1 <= fuel <= 500'000

vector<vector<int>> board(21, vector<int>(21, 0)); // 지도
vector<vector<int>> dist(21, vector<int>(21, 0)); // 거리
vector<pair<int, int>> passengers_src(401); // 승객의 위치
vector<pair<int, int>> passengers_dst(401); // 승객의 목적지
vector<bool> is_taken(401, false); // 승객이 태워졌는지 여부
pair<int, int> taxi; // 택시의 위치

enum { BLANK, WALL };

bool is_valid(int r, int c)
{
	return 1 <= r && r <= n && 1 <= c && c <= n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> fuel;

	board.resize(n + 1); dist.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		board[i].resize(n + 1);
		dist[i].resize(n + 1);
	}

	passengers_src.resize(m + 1);
	passengers_dst.resize(m + 1);
	is_taken.resize(m + 1);

	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			cin >> board[r][c];
		}
	}

	auto& [tr, tc] = taxi;
	cin >> tr >> tc;

	for (int i = 1; i <= m; ++i)
	{
		auto& [srcr, srcc] = passengers_src[i];
		cin >> srcr >> srcc;

		auto& [dstr, dstc] = passengers_dst[i];
		cin >> dstr >> dstc;
	}

	while (fuel > 0)
	{
		// 거리 초기화
		for (int r = 1; r <= n; ++r)
		{
			for (int c = 1; c <= n; ++c)
			{
				dist[r][c] = INF;
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;

		dist[tr][tc] = 0;
		pq.push({ 0, {tr, tc} });

		while (!pq.empty())
		{
			auto [cost, pos] = pq.top(); pq.pop();
			auto [cr, cc] = pos;

			if (dist[cr][cc] < cost)
				continue;

			for (int i = 0; i < 4; ++i)
			{
				int nr = cr + dr[i];
				int nc = cc + dc[i];

				if (!is_valid(nr, nc) || board[nr][nc] == WALL)
					continue;

				int next_cost = cost + 1;
				if (dist[nr][nc] > next_cost)
				{
					dist[nr][nc] = next_cost;
					pq.push({ next_cost, {nr, nc} });
				}
			}
		}

		int nearest = -1;

		for (int i = 1; i <= m; i++)
		{
			if (is_taken[i]) continue;
			if (nearest == -1)
			{
				nearest = i;
				continue;
			}

			const auto& [sr, sc] = passengers_src[i];
			const auto& [nr, nc] = passengers_src[nearest];

			if (dist[sr][sc] < dist[nr][nc])
			{
				nearest = i;
			}
			else if (dist[sr][sc] == dist[nr][nc])
			{
				if (sr < nr || (sr == nr && sc < nc))
				{
					nearest = i;
				}
			}
		}

		if (nearest == -1)
		{
			fuel = -1;
			break;
		}

		const auto& [nsr, nsc] = passengers_src[nearest];

		if (dist[nsr][nsc] > fuel)
		{
			fuel = -1;
			break;
		}

		// 승객을 태웠으므로, 승객의 위치를 택시의 위치로 변경
		tr = nsr;
		tc = nsc;
		fuel -= dist[nsr][nsc];

		// 승객의 목적지까지 이동
		const auto& [ndr, ndc] = passengers_dst[nearest];

		// 거리 초기화
		for (int r = 1; r <= n; ++r)
		{
			for (int c = 1; c <= n; ++c)
			{
				dist[r][c] = INF;
			}
		}
		dist[tr][tc] = 0;
		pq.push({ 0, {tr, tc} });

		while (!pq.empty())
		{
			auto [cost, pos] = pq.top(); pq.pop();
			auto [cr, cc] = pos;

			if (dist[cr][cc] < cost)
				continue;

			for (int i = 0; i < 4; ++i)
			{
				int nr = cr + dr[i];
				int nc = cc + dc[i];

				if (!is_valid(nr, nc) || board[nr][nc] == WALL)
					continue;

				int next_cost = cost + 1;
				if (dist[nr][nc] > next_cost)
				{
					dist[nr][nc] = next_cost;
					pq.push({ next_cost, {nr, nc} });
				}
			}
		}

		// 목적지까지의 거리가 연료보다 크다면, 실패
		if (dist[ndr][ndc] > fuel)
		{
			fuel = -1;
			break;
		}

		// 목적지까지 이동
		tr = ndr;
		tc = ndc;
		fuel += dist[ndr][ndc]; // 연료 충전
		is_taken[nearest] = true;

		if (count(is_taken.begin(), is_taken.end(), true) == m)
			break;
	}

	cout << fuel << endl;

	return 0;
}

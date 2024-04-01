#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int n; // 공간의 크기; 2 <= n <= 20
vector<vector<int>> space(20, vector<int>(20)); // 공간의 정보
pair<int, int> shark;   // 상어의 위치
int shark_size = 2;     // 상어의 크기
int shark_eat = 0;      // 상어가 먹은 물고기 수
int t = 0;              // 시간

const vector<int> dr = {0, 0, 1, -1};
const vector<int> dc = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> space[i][j];
            if (space[i][j] == 9)
            {
                shark = { i, j };
                space[i][j] = 0;
            }
        }
    }

    while (true)
    {
        vector<pair<int, int>> fish; // 먹을 수 있는 물고기들의 위치
        vector<vector<int>> dist(n, vector<int>(n, -1)); // 상어로부터의 거리
        queue<pair<int, int>> q;

        // 먹을 수 있는 물고기들의 위치 찾기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (space[i][j] > 0 && space[i][j] < shark_size)
                    fish.push_back({ i, j });
            }
        }

        // 먹을 수 있는 물고기가 없는 경우 종료
        if (fish.empty()) break;

        // 상어로부터의 거리 계산 및 가장 가까운 물고기 위치 구하기
        int min_dist = numeric_limits<int>::max();
        pair<int,int> min_fish = { -1, -1 };

        q.push(shark);
        auto [sr, sc] = shark;
        dist[sr][sc] = 0;

        while (!q.empty())
        {
            auto [r, c] = q.front(); q.pop();

            for (int i = 0; i < 4; i++)
            {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nr >= n || nc < 0 || nc >= n) // 범위를 벗어난 경우
					continue;
				if (dist[nr][nc] != -1 || space[nr][nc] > shark_size) // 이미 방문한 경우 또는 지나갈 수 없는 경우
					continue;

				dist[nr][nc] = dist[r][c] + 1;
				q.push({ nr, nc });
			}
        }

        for (auto it = fish.rbegin(); it != fish.rend(); it++)
        {
            auto [r, c] = *it;
            if (dist[r][c] != -1 && dist[r][c] <= min_dist)
            {
				min_dist = dist[r][c];
				min_fish = { r, c };
			}
		}

        if (min_fish == make_pair(-1, -1)) break;

        // 상어 이동
        auto [fr, fc] = min_fish;
        space[fr][fc] = 0;
        shark = min_fish;
        shark_eat++;
        if (shark_eat == shark_size)
        {
			shark_size++;
			shark_eat = 0;
		}
        t += dist[fr][fc];
    }
  
    cout << t << '\n';

    return 0;
}
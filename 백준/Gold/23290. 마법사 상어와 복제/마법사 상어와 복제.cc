#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int M; // 물고기의 수; 1 <= M <= 10
int S; // 마법을 연습한 횟수; 1 <= S <= 100

struct Fish
{
	int fx; // 물고기의 x좌표; 1 <= fx <= 4
	int fy; // 물고기의 y좌표; 1 <= fy <= 4
	int fd; // 물고기의 방향 : 1 <= fd <= 8
};

const vector<int> dfr = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // 세로(행) : 물고기의 우선순위
const vector<int> dfc = { 0, -1, -1, 0, 1, 1, 1, 0, -1 }; // 가로(열) : 물고기의 우선순위

pair<int, int> shark; // 상어의 위치

enum { UP = 1, LEFT, DOWN, RIGHT }; // 상어의 방향

const vector<int> dsr = { 0, -1, 0, 1, 0};
const vector<int> dsc = { 0, 0, -1, 0, 1};

int key = 1; // 물고기의 ID
unordered_map<int, Fish> fishMap; // key : 물고기의 ID, value: 물고기의 정보
vector<vector<deque<int>>> board(5, vector<deque<int>>(5)); // 4x4 크기의 보드
vector<vector<int>> smell(5, vector<int>(5)); // 냄새의 남은 시간

void backtracking(int cnt, pair<int, int> s, string path, int sum, vector<vector<bool>>& visited, string& max_path, int& max_sum)
{
	if (cnt == 3)
	{
		if (sum > max_sum)
		{
			max_sum = sum;
			max_path = path;
		}
		else if (sum == max_sum)
		{
			if (max_path == "") max_path = path;
			else max_path = min(max_path, path);
		}
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		auto& [sr, sc] = s;
		int nr = sr + dsr[i];
		int nc = sc + dsc[i];

		if (nr < 1 || nr > 4 || nc < 1 || nc > 4) continue;

		int next_sum = sum;
		auto tmp = visited;
		if (!visited[nr][nc]) next_sum += board[nr][nc].size();

		visited[nr][nc] = true;
		backtracking(cnt + 1, { nr, nc }, path + to_string(i), next_sum, visited, max_path, max_sum);
		visited = tmp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> S;

	for (int i = 1; i <= M; ++i)
	{
		int x, y, d;
		cin >> x >> y >> d;
		fishMap[key] = { x, y, d };
		key++;
		board[x][y].push_back(i);
	}

	auto& [sx, sy] = shark;
	cin >> sx >> sy;

	while (S--)
	{
		// 복제 마법을 실행하기 위해 물고기 복사
		vector<Fish> temp;

		for (auto& it : fishMap)
		{
			auto& [id, fish] = it;
			auto& [fx, fy, fd] = fish;

			temp.push_back(fish); // 물고기 복사

			// 물고기 이동
			for (int i = 0; i < 8; i++)
			{
				int nfd = (fd - i + 8) % 8;
				if (nfd == 0) nfd = 8;

				int nfx = fx + dfr[nfd];
				int nfy = fy + dfc[nfd];

				// 범위 나가면 불가능
				if (nfx < 1 || nfx > 4 || nfy < 1 || nfy > 4) continue;
				// 상어의 위치면 불가능
				if (nfx == sx && nfy == sy) continue;
				// 물고기 냄새가 남아있다면 불가능
				if (smell[nfx][nfy] > 0) continue;

				// 이동 가능

				board[fx][fy].pop_front(); // 이전 위치에서 물고기 제거 : 해당되는 물고기는 가장 앞에 있을 수 밖에 없음.
				fx = nfx;
				fy = nfy;
				fd = nfd;
				board[fx][fy].push_back(id); // 새로운 위치에 물고기 추가		
				break;
			}
		}

		// 냄새 시간 감소 : 먼저해야 새로운 냄새는 안 제거함.
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				if (smell[i][j] > 0) smell[i][j]--;
			}
		}

		// 상어가 이동해야 할 곳 결정 : 백트래킹
		string path = ""; // 상어의 이동 경로
		int excepted = 0; // 제외될 물고기 수


		vector<vector<bool>> visited(5, vector<bool>(5));
		backtracking(0, { sx, sy }, path, excepted, visited, path, excepted);

		// 상어 이동
		for (const auto& c : path)
		{
			int dir = c - '0';
			sx += dsr[dir];
			sy += dsc[dir];

			// 해당되는 물고기 제외
			if (!board[sx][sy].empty())
			{
				for (const auto& id : board[sx][sy])
				{
					fishMap.erase(id); // 물고기를 목록에서 제거
				}
				smell[sx][sy] = 2; // 물고기 냄새 남기기
				board[sx][sy].clear(); // board에서 물고기 제거
			}
		}

		// 물고기 복사
		for (const auto& fish : temp)
		{
			auto& [fx, fy, fd] = fish;
			board[fx][fy].push_back(key);
			fishMap[key] = fish;
			key++;
		}
	}

	// 남아있는 물고기 수 출력
	cout << fishMap.size() << '\n';

	return 0;
}

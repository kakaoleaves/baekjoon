#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 4 <= n, m <= 500
vector<vector<int>> paper;
vector<vector<bool>> visited;
int ans;

// 네 가지 테트로미노는 DFS 방식으로 탐색이 가능하다.
void backtracking(int x, int y, vector<int>& v) {
	if (v.size() == 4) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += v[i];
		}
		ans = max(ans, sum);
		return;
	}

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny]) continue;

		visited[nx][ny] = true;
		v.push_back(paper[nx][ny]);
		backtracking(nx, ny, v);
		visited[nx][ny] = false;
		v.pop_back();
	}
}

// ㅗ 모양은 DFS로 탐색이 불가능하다.
void finding(int x, int y) {
	// x, y를 중심으로 ㅗ 모양을 만들 수 있는 네 가지 방식 탐색
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int sum = paper[x][y];
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				flag = false;
				break;
			}
			sum += paper[nx][ny];
		}
		if (flag) ans = max(ans, sum);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	paper.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vector<int> v;
			visited[i][j] = true;
			v.push_back(paper[i][j]);
			backtracking(i, j, v);
			finding(i, j);
			visited[i][j] = false;
		}
	}

	cout << ans << '\n';

	return 0;
}
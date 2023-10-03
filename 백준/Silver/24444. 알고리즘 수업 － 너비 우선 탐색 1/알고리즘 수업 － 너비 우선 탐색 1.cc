#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& visited, int start, int& cnt) {
	queue<int> q;

	visited[start] = ++cnt;

	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		vector<int> nodes = graph[cur];

		for (int node : nodes)
		{
			if (visited[node] == 0) {
				visited[node] = ++cnt;
				q.push(node);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; // 5 <= n <= 100000
	int m; // 1 <= m <= 200000
	int r; // 1 <= r <= n

	cin >> n >> m >> r;
	vector<vector<int>> map(n + 1);
	vector<int> visited(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	for (int i = 1; i < map.size(); i++) {
		sort(map[i].begin(), map[i].end());
	}

	int cnt = 0;
	bfs(map, visited, r, cnt);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}

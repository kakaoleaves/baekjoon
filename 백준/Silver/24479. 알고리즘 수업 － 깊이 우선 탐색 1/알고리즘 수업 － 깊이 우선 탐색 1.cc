#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int start, int& cnt) {
	visited[start] = ++cnt;

	vector<int> nodes = graph[start];

	for (int node : nodes)
		if (visited[node] == 0) dfs(graph, visited, node, cnt);
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
	dfs(map, visited, r, cnt);

	for (int i = 1; i < visited.size(); i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}

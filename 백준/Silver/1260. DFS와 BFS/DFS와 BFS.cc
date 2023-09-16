#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<vector<int>>& graph, int start)
{
	vector<bool> visited(graph.size(), false);
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();

		for (int i = 0; i < graph[x].size(); ++i) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

void dfs(vector<vector<int>>& graph, int start) {
	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> s;

	s.push(start);

	while (!s.empty()) {
		int node = s.top();
		s.pop();

		if (!visited[node]) {
			cout << node << " ";
			visited[node] = true;
		}

		for (int i = (int)graph[node].size() - 1; i >= 0; --i) {
			int next = graph[node][i];
			if (!visited[next]) {
				s.push(next);
			}
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n, m, v;

	cin >> n >> m >> v;

	vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
		int a, b;

		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);

		sort(adj[a].begin(), adj[a].end());
		sort(adj[b].begin(), adj[b].end());
	}

	dfs(adj, v);
	cout << "\n";
	bfs(adj, v);


    return 0;
}
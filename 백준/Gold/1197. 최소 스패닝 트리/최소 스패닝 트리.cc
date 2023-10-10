#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v; // 1 <= v <= 10'000
	int e; // 1 <= e <= 100'000
	int ans = 0;

	cin >> v >> e;

	vector<int> vertices(v + 1);
	vector<vector<pair<int, int>>> graph(v + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b, c; // a, b <= v, c <= 1'000
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	vector<bool> visited(v + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;

		pq.pop();

		if (visited[vertex]) continue;

		visited[vertex] = true;

		ans += cost;

		for (auto& edge : graph[vertex]) {
			int nextVertex = edge.first;
			int nextCost = edge.second;

			if (!visited[nextVertex]) {
				pq.push({ nextCost, nextVertex });
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

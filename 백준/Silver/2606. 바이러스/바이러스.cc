#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int dfs(vector<vector<int>>& graph, int start) {
	int answer = 0;
	vector<bool> visited(graph.size(), false);
	stack<int> s;

	visited[start] = true;
	s.push(start);

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 1; i < graph.size(); i++) {
			if (graph[cur][i] == 1 && !visited[i]) {
				visited[i] = true;
				s.push(i);
				answer++;
			}
		}
	}

	return answer;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; // 컴퓨터의 수, 1 <= n <= 100;
	int m; // 연결되어 있는 쌍의 수

	cin >> n;
	cin >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	vector<int> visited(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cout << dfs(graph, 1) << '\n';

	return 0;
}

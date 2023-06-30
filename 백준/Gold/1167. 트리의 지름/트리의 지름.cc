#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int getDiameter(const vector<list<pair<int, int>>>& graph, int start)
{
	size_t verticesNum = graph.size();
	vector<bool> visited(verticesNum, false);
	vector<int> dist(verticesNum, 0);
	stack<int> s;

	s.push(start);
	visited[start] = true;

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		for (auto& p : graph[cur])
		{
			int dest = p.first;
			int weight = p.second;
			if (!visited[dest])
			{
				visited[dest] = true;
				s.push(dest);
				dist[dest] = dist[cur] + weight;
			}
		}
	}

	return *max_element(dist.begin(), dist.end());
}

auto getDiameterIndex(const vector<list<pair<int, int>>>& graph, int start)
{
	size_t verticesNum = graph.size();
	vector<bool> visited(verticesNum, false);
	vector<int> dist(verticesNum, 0);
	stack<int> s;

	s.push(start);
	visited[start] = true;

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		for (auto& p : graph[cur])
		{
			int dest = p.first;
			int weight = p.second;
			if (!visited[dest])
			{
				visited[dest] = true;
				s.push(dest);
				dist[dest] = dist[cur] + weight;
			}
		}
	}

	return max_element(dist.begin(), dist.end()) - dist.begin();
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int diameter = 0;
	cin >> n;

	vector<list<pair<int, int>>> graph(n);

	for (int i = 0; i < n; i++)
	{
		int start, dest, weight;
		dest = 0;
		cin >> start;
		while (dest != -1)
		{
			cin >> dest;
			if (dest == -1)
				break;
			cin >> weight;
			graph[start - 1].push_back(make_pair(dest - 1, weight));
		}
	}

	int diameterIndex = getDiameterIndex(graph, 0);
	cout << getDiameter(graph, diameterIndex) << '\n';

	return 0;
}
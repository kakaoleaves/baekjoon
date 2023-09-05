#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<vector<int>>& graph, int start)
{
    int answer = 0;
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, 0);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    int maxDist = *max_element(dist.begin(), dist.end());
    for (int d : dist)
    {
        if (d == maxDist) answer++;
    }
    return answer;    
}

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> graph(n + 1);
    
    for (const auto& edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int answer = 0;
    answer = bfs(graph, 1);
    
    return answer;
}
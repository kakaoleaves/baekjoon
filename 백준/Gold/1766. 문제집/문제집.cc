#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 문제의 수, 1 <= n <= 32000
    int m; // 먼저 푸는 것이 좋은 문제에 대한 정보의 개수, 1 <= m <= 100,000

    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;


    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
			pq.push(i);
		}
	}

    while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		cout << now << ' ';

        for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			indegree[next]--;
            if (indegree[next] == 0) {
				pq.push(next);
			}
		}
	}
    
    return 0;
}
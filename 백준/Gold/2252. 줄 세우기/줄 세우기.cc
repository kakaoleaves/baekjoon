#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Color { WHITE, GRAY, BLACK };

void dfs
(int node, vector<vector<int>>& adj, vector<Color>& color, vector<int>& topological) {
    color[node] = GRAY;

    for (int neighbor : adj[node]) {
        if (color[neighbor] == WHITE) {
            dfs(neighbor, adj, color, topological);
        }
    }

    color[node] = BLACK;  // 노드를 방문 완료 상태로 표시
    topological.push_back(node);
}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;  // 학생 수, 1 <= n <= 32000
    int m ; // 키를 비교한 횟수, 1 <= m <= 100000
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<Color> color(n + 1, WHITE);
    vector<int> topological;

    for (int i = 0; i < m; i++) {
		int a, b;  // a가 b보다 키가 작다.
		cin >> a >> b;
		adj[a].push_back(b);
	}

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) {
			dfs(i, adj, color, topological);
		}
	}

    reverse(topological.begin(), topological.end());

    for (int i = 0; i < topological.size(); i++) {
		cout << topological[i] << ' ';
	}

    return 0;
}
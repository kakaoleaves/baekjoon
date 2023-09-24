#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Color { WHITE, GRAY, BLACK };

bool dfs
(int node, vector<vector<int>>& adj, vector<Color>& color, vector<int>& topological) {
    color[node] = GRAY;

    for (int i = 1; i < adj.size(); i++) {
        if (adj[node][i] == 1) {
            if (color[i] == GRAY) {
				return false;
			}
            else if (color[i] == WHITE) {
                if (!dfs(i, adj, color, topological)) {
					return false;
				}
			}
		}
	}

    color[node] = BLACK;  // 노드를 방문 완료 상태로 표시
    topological.push_back(node);
    return true;
}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; // 테스트 케이스의 수, 1 <= t <= 100
 
    cin >> t;
    while (t--) {
        int n; // 팀의 수, 2 <= n <= 500
        vector<int> last; // 작년 등수
        int m; // 상대적으로 등수가 바뀐 쌍의 수, 0 <= m <= 25000

        cin >> n;
        last.assign(n, 0);

        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        vector<Color> color(n + 1, WHITE);
        vector<int> topological;
        bool isPossible = true;

        for (int i = 0; i < n; i++) {
            cin >> last[i];
            for (int j = 0; j < i; j++) {
				adj[last[j]][last[i]] = 1;
			}
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            int a, b;  // a가 b보다 키가 작다.
            cin >> a >> b;
            if (adj[a][b] == 1) {
                adj[a][b] = 0;
                adj[b][a] = 1;
            }
            else {
                adj[a][b] = 1;
				adj[b][a] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (color[i] == WHITE) {
                if (!dfs(i, adj, color, topological)) {
					isPossible = false;
					break;
				}
			}
		}

        if (!isPossible) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}

        reverse(topological.begin(), topological.end());

        for (int i = 0; i < topological.size(); i++) {
            cout << topological[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
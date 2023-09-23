#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

enum Color { WHITE, GRAY, BLACK };

const int MAX_V = 10000;

vector<vector<int>> adj(MAX_V + 1);
vector<vector<int>> reverse_adj(MAX_V + 1);
vector<Color> color(MAX_V + 1, WHITE);
vector<int> discovered(MAX_V + 1, -1);
vector<int> finished(MAX_V + 1, -1);
int t = 0;
vector<vector<int>> scc;

void dfs(int node) {
    color[node] = GRAY;
    t++;
    discovered[node] = t;

    for (int neighbor : adj[node]) {
        if (color[neighbor] == WHITE) {
            dfs(neighbor);
        }
    }

    color[node] = BLACK;  // 노드를 방문 완료 상태로 표시
    t++;
    finished[node] = t; 

}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int v; // 1 <= v <= 10'000
    int e; // 1 <= e <= 100'000
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

    // reverse 
    for (int node = 1; node <= v; ++node) {
        for (int neighbor : adj[node]) {
			reverse_adj[neighbor].push_back(node);
		}
	}

    for (int node = 1; node <= v; ++node) {
        if (color[node] == WHITE) {
            dfs(node);
        }
    }

    // 정점의 종료 시간을 기준으로 내림차순 정렬
    vector<pair<int, int>> order;
    for (int i = 1; i <= v; ++i) {
		order.push_back({ finished[i], i });
	}
    sort(order.begin(), order.end(), greater<pair<int, int>>());

    // dfs를 다시 수행하며 SCC를 찾는다.
    color = vector<Color>(MAX_V + 1, WHITE);
    for (int i = 0; i < v; ++i) {
        int node = order[i].second;

        if (color[node] == WHITE) {
			vector<int> new_scc;
			stack<int> s;
			s.push(node);
			color[node] = GRAY;

            while (!s.empty()) {
				int curr = s.top();
				s.pop();
				new_scc.push_back(curr);
                for (int neighbor : reverse_adj[curr]) {
                    if (color[neighbor] == WHITE) {
						s.push(neighbor);
						color[neighbor] = GRAY;
					}
				}
			}
			scc.push_back(new_scc);
		}
	}

    // scc 출력
    for (auto& component : scc) {
        sort(component.begin(), component.end());
	}
    sort(scc.begin(), scc.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.front() < b.front();
    });

    cout << scc.size() << '\n';
    for (auto& component : scc) {
        for (int node : component) {
			cout << node << ' ';
		}
		cout << -1 << '\n';
	}


    return 0;
}
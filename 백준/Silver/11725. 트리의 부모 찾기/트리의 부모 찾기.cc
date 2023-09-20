#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& tree, vector<int>& parent, int start) {
	queue<int> q;
	q.push(start);

    while (!q.empty()) {
        int node = q.front();
		q.pop();

        const vector<int>& children = tree[node];

        for (const auto& child : children) {
            if (parent[child] == 0) {
				parent[child] = node;
				q.push(child);
			}
        }
    }
}

int main()
{
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 노드의 개수, 2 <= n <= 100'000
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }


    vector<int> parent(n + 1, 0);

    bfs(tree, parent, 1);

    for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

    return 0;
}
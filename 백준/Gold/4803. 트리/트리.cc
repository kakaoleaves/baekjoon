#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0) {
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

    void unionSets(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
		} else {
			parent[rootB] = rootA;
            rank[rootA]++;
		}
    }

    int findSet(int a) {
		if (parent[a] == a) return a;
		return parent[a] = findSet(parent[a]);
	}

    int countSet() {
		int cnt = 0;
        for (int i = 0; i < parent.size(); ++i) {
			if (parent[i] == i) cnt++;
		}
		return cnt;
	}
};

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 정점의 개수, n <= 500
    int m; // 간선의 개수, m <= n(n-1)/2
    int idx = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        
        DisjointSet ds(n + 1);
        vector<bool> cycle(n + 1, false);

        while (m--) {
            int u, v;
            cin >> u >> v;

            int rootU = ds.findSet(u);
            int rootV = ds.findSet(v);
            if (rootU == rootV) {
				cycle[rootU] = true;
            }
            else {
				ds.unionSets(u, v);
			}
        }

        for (int i = 1; i <= n; ++i) {
            if (cycle[i]) {
                int root = ds.findSet(i);
                if (root != i) {
					cycle[root] = false;
				}
            }
        }

        int tree = ds.countSet() - (int)count(cycle.begin(), cycle.end(), true) - 1;

        cout << "Case " << idx++ << ": ";

        switch (tree) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << tree << " trees.\n";
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
	vector<int> rank;
public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

    int findSet(int a) {
        if (parent[a] == a) return a;
        return parent[a] = findSet(parent[a]);
    }

    void unionSets(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else {
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB])
                rank[rootA]++;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n; // 1 <= n <= 1'000'000, 집합 개수 n + 1
    int m; // 1 <= m <= 100'000, 연산의 개수
    cin >> n >> m;

    DisjointSet ds(n + 1);

    while (m--) {
        bool op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            ds.unionSets(a, b);
        }
        else {
			if (ds.findSet(a) == ds.findSet(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
    }

    return 0;
}
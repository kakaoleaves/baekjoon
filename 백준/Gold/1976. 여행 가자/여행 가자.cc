#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0) {
        // 초기화
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // MAKE-SET
        }
    }

    // FIND-SET 연산
    int findSet(int a) {
        if (parent[a] == a) return a;
        return parent[a] = findSet(parent[a]); // 경로 압축
    }

    // UNION (rank 기반 합병)
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

    int n; // n <= 200, 도시의 수
    int m; // m <= 1000, 여행 계획에 속한 도시의 수

    cin >> n >> m;
    vector<vector<int>> adj (n + 1, vector<int>(n + 1, 0));
    vector<int> plan (m, 0);

    DisjointSet ds(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) ds.unionSets(i, j);
        }
    }

    for (int i = 0; i < m; ++i)
        cin >> plan[i];

    int root = ds.findSet(plan.front());

    for (int i = 1; i < m; ++i) {
        if (root != ds.findSet(plan[i])) {
			cout << "NO";
			return 0;
		}
	}

    cout << "YES";

    return 0;
}
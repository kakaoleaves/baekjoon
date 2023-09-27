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

    int n; // 점의 개수, 3 <= n <= 500'000
    int m; // 차례의 수, 3 <= m <= 1'000'0000

    cin >> n >> m;

    DisjointSet ds(n);
    int a, b;
    int end = 0;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        
        if (end > 0) continue;

        int rootA = ds.findSet(a);
        int rootB = ds.findSet(b);

        if (rootA == rootB) // cycle
            end = i;
        else
            ds.unionSets(a, b);
    }

    cout << end << '\n';

    return 0;
}
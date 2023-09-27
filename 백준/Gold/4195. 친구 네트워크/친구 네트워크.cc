#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
    explicit DisjointSet(int n) : parent(n), rank(n, 1) {
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

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
            rank[rootB] += rank[rootA];
        }
        else {
            parent[rootB] = rootA;
            rank[rootA] += rank[rootB];
        }
    }

    int getRank(int a) {
		return rank[findSet(a)];
	}
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t; // 테스트 케이스의 수
   
    cin >> t;

    while (t--) {
        int f; // 친구 관계의 수, <= 100,000

        cin >> f;
        string a, b;

        DisjointSet ds(2 * f);
        map<string, int, less<>> nameMap;

        while (f--) {
            cin >> a >> b;
            auto ita = nameMap.find(a);
            int aIdx = 0, bIdx = 0;
            // a에 대한 처리
            if (ita == nameMap.end()) {
                aIdx = (int) nameMap.size();
                nameMap.insert({ a, aIdx });
            }
            else {
                aIdx = ita->second;
            }

            // b에 대한 처리
            auto itb = nameMap.find(b);
            if (itb == nameMap.end()) {
                bIdx = (int)nameMap.size();
                nameMap.insert({ b, bIdx });
            }
            else {
                bIdx = itb->second;
            }
            ds.unionSets(aIdx, bIdx);

            cout << ds.getRank(aIdx) << '\n';
        }
    }

    return 0;
}
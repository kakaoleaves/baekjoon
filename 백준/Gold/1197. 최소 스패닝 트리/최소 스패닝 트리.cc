#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int findSet(int a)
	{
		if (parent[a] == a) return a;
		return parent[a] = findSet(parent[a]);
	}

	void unionSet(int a, int b)
	{
		int rootA = findSet(a);
		int rootB = findSet(b);

		if (rootA == rootB) return;
		
		if (rank[rootA] > rank[rootB]) {
			parent[rootB] = rootA;
		}
		else {
			parent[rootA] = rootB;
			if (rank[rootA] == rank[rootB]) {
				rank[rootB]++;
			}
		}
	}
};

int v;
int e;
int ans;
vector<pair<int, pair<int, int>>> edges(100001);

void Init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	
	edges.resize(e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { c, {a, b} };
	}	

	// sort by cost
	sort(edges.begin(), edges.end());
}

void Kruskal()
{
	DisjointSet ds(v + 1);

	for (int i = 0; i < e; i++) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int c = edges[i].first;

		if (ds.findSet(a) == ds.findSet(b)) continue;

		ds.unionSet(a, b);
		ans += c;
	}
}

int main()
{
	Init();
	Kruskal();
	cout << ans << '\n';
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 50001;
const int LOG = 16;

vector<int> tree[MAX_N];
int parent[LOG][MAX_N];		// jump table
int depth[MAX_N];			// 각 노드 깊이
bool visited[MAX_N];		// 방문 여부

int n, m;

void dfs(int node, int par) {
	visited[node] = true;
	parent[0][node] = par;

	for (int child : tree[node]) {
		if (!visited[child]) {
			depth[child] = depth[node] + 1;
			dfs(child, node);
		}
	}
}

void preprocess() {
	dfs(1, -1);

	for (int i = 1; i < LOG; ++i) {
		for (int node = 1; node <= n; ++node) {
			if (parent[i - 1][node] != -1) {
				parent[i][node] = parent[i - 1][parent[i - 1][node]];
			}
			else {
				parent[i][node] = -1;
			}
		}
	}
}

int findLCA(int x, int y) {
	// 1. 깊이 맞추기
	if (depth[x] < depth[y]) swap(x, y); // 항상 x가 더 깊게
	int diff = depth[x] - depth[y];

	for (int i = LOG - 1; i >= 0; --i) {
		if (diff & (1 << i)) { // 차이가 2^i인 경우 위로 점프
			x = parent[i][x];
		}
	}

	// 2. 두 노드가 같아지면 공통 조상 반환
	if (x == y) return x;

	// 3. 공통 조상을 찾을 때까지 위로 이동
	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[i][x] != parent[i][y]) {
			x = parent[i][x];
			y = parent[i][y];
		}
	}

	return parent[0][x]; // 바로 위 부모가 LCA
}

void addEdge(int u, int v) {
	tree[u].push_back(v);
	tree[v].push_back(u);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		addEdge(u, v);
	}

	// 전처리
	preprocess();

	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);

		int lca = findLCA(x, y);
		printf("%d\n", lca);
	}

	return 0;
}
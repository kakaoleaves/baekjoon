#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100010;
vector<int> v[MAX];
int parents[MAX];
int visited[MAX];

void dfs(int start) {
	visited[start] = 1;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (visited[next] == 1) continue;
		parents[next] = start;
		dfs(next);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a;
		int b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}


	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parents[i]);
	}

	return 0;
}
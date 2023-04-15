#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100010;
vector<int> v[MAX];
int parents[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	parents[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (parents[next] == 0) {
				parents[next] = cur;
				q.push(next);
			}
		}
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

	bfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parents[i]);
	}

	return 0;
}
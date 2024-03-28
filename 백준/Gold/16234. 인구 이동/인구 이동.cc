#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int l;
int r;
int day;
vector<vector<int>> map;
vector<vector<int>> graph;

const vector<int> dx = { 0, 0, 1, -1 };
const vector<int> dy = { 1, -1, 0, 0 };

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

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l >> r;

	int nations = n * n;

	map.assign(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	while (true) {
		// 그래프 초기화
		graph = vector<vector<int>>(nations, vector<int>());

		// 인구 이동 가능 여부에 대한 그래프 그리기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						int diff = abs(map[i][j] - map[nx][ny]);
						if (diff >= l && diff <= r)
						{
							graph[i * n + j].push_back(nx * n + ny);
							graph[nx * n + ny].push_back(i * n + j);
						}
					}
				}
			}
		}

		// 국가들이 이동할 필요가 없을 경우
		if (all_of(graph.begin(), graph.end(), [](const vector<int>& v) { return v.empty(); }))
			break;

		// 인구 이동 : Disjoint Set 활용 
		DisjointSet ds(nations);

		// 인구 이동 가능한 국가들을 하나의 집합으로 묶기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < graph[i * n + j].size(); k++)
				{
					int nx = graph[i * n + j][k];
					if (ds.findSet(i * n + j) != ds.findSet(nx))
						ds.unionSets(i * n + j, nx);
				}
			}
		}

		vector<int> sum(nations, 0);
		vector<int> cnt(nations, 0);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int root = ds.findSet(i * n + j);
				sum[root] += map[i][j];
				cnt[root]++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int root = ds.findSet(i * n + j);
				map[i][j] = sum[root] / cnt[root];
			}
		}

		day++;
	} 

	cout << day << "\n";

	return 0;
}
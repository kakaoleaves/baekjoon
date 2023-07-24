#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MAX_COST = 10000;

int main()
{
	fastio;

	int n; // 2 <= n <= 100'000
	vector<int> dists; // 1 <= dist[i] <= 1'000'000'000
	vector<int> costs; // 1 <= cost[i] <= 1'000'000'000
	long long ans = 0;

	cin >> n;

	dists.resize(n - 1);
	costs.resize(n);

	int min_cost = MAX_COST;

	for (auto& dist : dists)
		cin >> dist;

	for (auto& cost : costs)
		cin >> cost;

	for (int i = 0; i < n - 1; i++)
	{
		if (costs[i] < min_cost)
			min_cost = costs[i];

		ans += (long long)min_cost * dists[i];
	}

	cout << ans << '\n';

	return 0;
}
// Baekjoon #14889
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (auto &i : graph)
		for (auto &j : i)
			cin >> j;

    int min = 100 * 10;

	for (int i = 0; i < (1 << n); i++)
	{
		vector<int> start;
		vector<int> link;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				start.push_back(j);
			else
				link.push_back(j);
		}

		if (start.size() != n / 2)
			continue;

		int start_sum = 0;
		int link_sum = 0;
		for (int j = 0; j < n / 2; j++)
		{
			for (int k = 0; k < n / 2; k++)
			{
				if (j == k)
					continue;
				start_sum += graph[start[j]][start[k]];
				link_sum += graph[link[j]][link[k]];
			}
		}

		int diff = abs(start_sum - link_sum);
		if (diff < min)
			min = diff;
	}

	cout << min << '\n';
    
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bitonicSubSequence(vector<int>& arr)
{
	int n = arr.size();

	vector<int> lis(n, 1); // Longest Increasing Subsequence
	vector<int> lds(n, 1); // Longest Decreasing Subsequence

	// LIS
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j]) // strictly increasing
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j]) // strictly decreasing
				lds[i] = max(lds[i], lds[j] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, lis[i] + lds[i] - 1);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;			// 1 <= n <= 1000
	vector<int> v;

	cin >> n;
	v.resize(n);

	for (auto& i : v)
		cin >> i;	// 1 <= v[i] <= 1000

	cout << bitonicSubSequence(v) << '\n';

	return 0;
}
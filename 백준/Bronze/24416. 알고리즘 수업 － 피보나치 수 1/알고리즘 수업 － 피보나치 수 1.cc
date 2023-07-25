#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int recursiveFib(int n, int& count)
{
	if (n == 1 || n == 2)
	{
		count++;
		return 1;
	}
	return recursiveFib(n - 1, count) + recursiveFib(n - 2, count);
}

int dynamicProgFib(int n, int& count)
{
	vector<int> dp(n + 1);
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		count++;
	}
	return dp[n];
}

int main()
{
	fastio;

	int n;
	int recursiveCount = 0;
	int dynamicCount = 0;

	cin >> n;

	recursiveFib(n, recursiveCount);
	dynamicProgFib(n, dynamicCount);

	cout << recursiveCount << " " << dynamicCount << '\n';

	return 0;
}
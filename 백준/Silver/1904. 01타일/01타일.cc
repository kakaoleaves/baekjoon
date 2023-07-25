#include <iostream>
#include <map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MOD = 15746;

int zeroOneTile(int n)
{
	vector<int> memo(n + 1, 0);

	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i <= n; i++)
		memo[i] = (memo[i - 1] + memo[i - 2]) % MOD;

	return memo[n];
}

int main()
{
	fastio;

	int n;
	cin >> n;

	cout << zeroOneTile(n) << '\n';

	return 0;
}
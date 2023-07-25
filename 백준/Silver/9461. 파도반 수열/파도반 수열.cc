#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int MAX = 100;

long long PadovanSequence(int n, vector<long long>& memo)
{
	if (n <= 3) return memo[n];

	for (int i = 4; i <= n; i++)
	{
		memo[i] = memo[i - 2] + memo[i - 3];
	}

	return memo[n];
}

int main()
{
	fastio;

	int t;
	int n;
	vector<long long> memo(MAX + 1, 0);
	memo[1] = memo[2] = memo[3] = 1;

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << PadovanSequence(n, memo) << '\n';
	}

	return 0;
}
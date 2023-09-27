#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 동전 종류, 1<= n <= 100
    int k; // 동전 가치 합, 1 <= k <= 10,000
    vector<int> coins;
    vector<int> dp;

    cin >> n >> k;
    coins.resize(n);
    dp.resize(k + 1, 0);

    for (int& coin : coins)
        cin >> coin;

    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = 1; i <= k; ++i)
        {
			if (i - coin >= 0)
				dp[i] += dp[i - coin];
		}
	}

    cout << dp[k] << '\n';


    return 0;
}
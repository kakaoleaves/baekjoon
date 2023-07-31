#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1<= n <= 10000
    cin >> n;

    vector<int> v(n);
    vector<int> dp(n + 1);
    for (auto& i : v) {
		cin >> i; // 0 <= i <= 1000
	}

    dp[0] = 0;
    dp[1] = v[0];
    dp[2] = v[0] + v[1];
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + v[i - 1], dp[i - 3] + v[i - 2] + v[i - 1]));
	}

    cout << dp[n] << '\n';


    return 0;
}
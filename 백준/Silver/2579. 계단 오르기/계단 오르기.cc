#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(2, 0));

    for (auto& i : v) {
		cin >> i;
	}

    if (n > 0)
    {
        dp[0][0] = v[0];
        dp[0][1] = 0;
    }

    if (n > 1) {
		dp[1][0] = v[1];
		dp[1][1] = v[0] + v[1];
	}

    for (int i = 2; i < n; i++)
    {
        // 두 계단을 올라 연속 계단 수가 1인 경우
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + v[i];

        // 한 계단을 올라 연속 계단 수가 2인 경우
        dp[i][1] = dp[i - 1][0] + v[i];
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';

    return 0;
}
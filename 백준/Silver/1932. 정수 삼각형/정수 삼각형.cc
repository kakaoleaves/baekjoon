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
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
			cin >> triangle[i][j];
		}
	}

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i-1][0] + triangle[i][0];
		dp[i][i] = dp[i-1][i-1] + triangle[i][i];
	}

    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';

    return 0;
}
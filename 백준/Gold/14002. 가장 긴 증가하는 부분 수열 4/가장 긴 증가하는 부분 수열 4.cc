#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1 <= n <= 1000
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[i].push_back(v[i]);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j] && dp[i].size() < dp[j].size() + 1) {
                dp[i] = dp[j];
                dp[i].push_back(v[i]);
            }
        }
    }

    const vector<int>& ansVector = *max_element(dp.begin(), dp.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
     });

    cout << ansVector.size() << "\n";

    for (const auto& ans : ansVector) {
        cout << ans << " ";
    }

    return 0;
}
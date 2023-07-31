#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1<= n <= 1000
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n, 1);
 
    for (auto& i : v) {
		cin >> i;
	}

    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}

    cout << *max_element(dp.begin(), dp.end()) << '\n';


    return 0;
}
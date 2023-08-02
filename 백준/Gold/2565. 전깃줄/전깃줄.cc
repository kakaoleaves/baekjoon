#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cable {
    int a;
    int b;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1 <= n <= 100
    cin >> n;

    vector<Cable> cables(n);
    
    for (auto& cable : cables) {
		cin >> cable.a >> cable.b;
	}

    sort(cables.begin(), cables.end(), [](const Cable& a, const Cable& b) {
		return a.a < b.a;
	});

    vector<int> dp(n, 1); // dp[i] : i번째 케이블을 사용했을 때 최대 연결 개수

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (cables[i].b > cables[j].b) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

    cout << n - *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
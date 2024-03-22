#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 16;

int n; // 1 <= n <= 15
vector<int> t(MAX); // 1 <= t <= 5; 기간
vector<int> p(MAX); // 1 <= p <= 1000; 금액
vector<int> dp(MAX); // dp[i] = i번째 날까지의 최대 이익

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	t.resize(n); p.resize(n); dp.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i < n; i++) {
		if (i + t[i] <= n) {
			dp[i] = p[i]; // i번째 날에 일이 가능하다면, dp에 금액을 추가
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (j + t[j] <= i && i + t[i] <= n) {
				// j번째 일의 상담은 i번째 일에 영향을 미치지 않으므로, 갱신 가능
				dp[i] = max(dp[i], dp[j] + p[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
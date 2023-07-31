#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n; // 1 <= n <= 1'000'000
    vector<int> v(n);
    vector<int> dp; 

    for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

    // LIS : dp[i]는 길이가 i인 증가하는 부분 수열의 마지막 원소 중 최솟값
    for (const auto& e : v) {
		auto it = lower_bound(dp.begin(), dp.end(), e); // dp에서 e보다 크거나 같은 첫번째 원소의 위치를 반환
        if (it == dp.end()) {
			dp.push_back(e); // e가 dp의 모든 원소보다 크다면 dp에 e를 추가
        }
        else {
			*it = e; // 아니라면 해당 위치의 값을 e로 갱신
		}
	}

    cout << dp.size() << '\n';

    return 0;
}
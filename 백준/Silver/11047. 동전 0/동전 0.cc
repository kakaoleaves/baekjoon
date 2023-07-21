#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;

	int n; // 1 <= n <= 10
	int k; // 1 <= k <= 100,000,000
	vector<int> v;

	cin >> n >> k;
	v.resize(n);

	for (auto &i : v)
		cin >> i;

	int cnt = 0; // 필요한 동전 개수

	for (auto it = v.rbegin(); it != v.rend(); it++) {
		if (k == 0) break; // k원을 만들었으면 종료
		if (*it > k) continue; // 동전이 k원보다 크면 패스
		cnt += k / *it;
		k %= *it;
	}

	cout << cnt << '\n';
   
	return 0;
}
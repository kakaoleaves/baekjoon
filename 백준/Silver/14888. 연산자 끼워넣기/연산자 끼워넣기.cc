#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int n; // 2 <= n <= 11
vector<int> v(11);
vector<int> op(4); // +, -, *, /

int mx = numeric_limits<int>::min();
int mn = numeric_limits<int>::max();

void backtrack(int idx, int sum)
{
	if (idx == n) {
		mx = std::max(mx, sum);
		mn = std::min(mn, sum);
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) backtrack(idx + 1, sum + v[idx]);
			else if (i == 1) backtrack(idx + 1, sum - v[idx]);
			else if (i == 2) backtrack(idx + 1, sum * v[idx]);
			else if (i == 3) backtrack(idx + 1, sum / v[idx]);
			op[i]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	backtrack(1, v[0]);

	cout << mx << '\n' << mn << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> v;
vector<bool> checked;

int mn = numeric_limits<int>::max();

void backtracking(int idx, int num) {
	if (num == n / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (checked[i] && checked[j]) start += v[i][j] + v[j][i];
				else if (!checked[i] && !checked[j]) link += v[i][j] + v[j][i];
			}
		}
		mn = min(mn, abs(start - link));
		return;
	}

	for (int i = idx; i < n; i++) {
		if (!checked[i]) {
			checked[i] = true;
			backtracking(i + 1, num + 1);
			checked[i] = false;		
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	v.resize(n, vector<int>(n));
	checked.resize(n, false);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	checked[0] = true;

	backtracking(1, 1);

	cout << mn << '\n';

	return 0;
}
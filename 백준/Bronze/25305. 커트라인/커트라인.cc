#include <iostream>
#include <cassert>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    multiset<int, greater<int>> ms;

    cin >> n >> k;
    assert(n >= 1 && n <= 1000);
    assert(k >= 1 && k <= n);

    for (int i = 0; i < n; i++) {
		int score;
		cin >> score;
        assert(score >= 0 && score <= 10000);
		ms.insert(score);
	}

    auto it = ms.begin();
    advance(it, k - 1);
    cout << *it << endl;

    return 0;
}
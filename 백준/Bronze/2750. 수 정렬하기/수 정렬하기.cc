#include <iostream>
#include <set>
using namespace std;

int n; // 1 <= n <= 1000
int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
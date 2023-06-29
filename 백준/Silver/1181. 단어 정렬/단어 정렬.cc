#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct compare {
    bool operator()(const string& a, const string& b) const {
        if (a.length() == b.length()) {
			return a < b;
		}
        else {
			return a.length() < b.length();
		}
	}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    assert(n >= 1 && n <= 20000);

    set<string, compare> s;
    for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		assert(str.length() >= 1 && str.length() <= 50);
		s.insert(str);
	}

    for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << '\n';
	}

    return 0;
}
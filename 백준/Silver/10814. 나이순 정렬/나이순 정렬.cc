#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multimap<int, string> m;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        assert(age >= 1 && age <= 200);
        assert(name.length() >= 1 && name.length() <= 100);
        m.insert(make_pair(age, name));
    }

    for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

    return 0;
}
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int sz = str.size();

	for (int i = 0; i < sz; i++) {
		for (int j = sz - i; j > 0; j--) {
			s.insert(str.substr(i, j));
		}
	}

	cout << s.size() << '\n';

	return 0;
}
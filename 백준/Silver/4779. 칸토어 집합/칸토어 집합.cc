#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n; // 0 <= n <= 12

void CantorSet(string& s, int start, int end) {
	if (end - start < 3) {
		return; // base case
	}
	int third = (end - start) / 3;

	for (int i = start + third; i < start + 2 * third; i++) {
		s[i] = ' ';
	}

	CantorSet(s, start, start + third);
	CantorSet(s, start + 2 * third, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		int length = static_cast<int>(pow(3, n));
		string s(length, '-');
		CantorSet(s, 0, length);
		cout << s << '\n';
	}

	return 0;
}
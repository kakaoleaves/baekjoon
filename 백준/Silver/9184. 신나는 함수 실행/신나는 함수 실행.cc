#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct triple {
	int a;
	int b;
	int c;

	bool operator<(const triple& other) const
	{
		if (a != other.a) return a < other.a;
		if (b != other.b) return b < other.b;
		return c < other.c;
	}

};

int w(int a, int b, int c, map<triple, int>& table)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20, table);

	triple t = { a, b, c };
	if (table.count(t)) return table[t];

	if (a < b && b < c) return table[t] = w(a, b, c - 1, table) + w(a, b - 1, c - 1, table) - w(a, b - 1, c, table);
	return table[t] = w(a - 1, b, c, table) + w(a - 1, b - 1, c, table) + w(a - 1, b, c - 1, table) - w(a - 1, b - 1, c - 1, table);
}

int main()
{
	fastio;

	int a;
	int b;
	int c;
	map<triple, int> table;

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c, table) << '\n';
	}

	return 0;
}
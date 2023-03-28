#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (T const& i : v) {
		os << i << " ";
	}
	return os;
}

int main(void)
{
	int n, m, i, j;
	vector <int> v;

	cin >> n >> m;

	for (int a = 1; a <= n; a++)
	{
		v.push_back(a);
	}

	for (int a = 0; a < m; a++)
	{
		cin >> i >> j;
		reverse(v.begin() + i - 1, v.begin() + j);
	}

	cout << v << endl;

	return 0;
}
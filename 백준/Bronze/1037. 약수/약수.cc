#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	if (n % 2 == 0)
		cout << v[0] * v[n - 1] << '\n';
	else
		cout << v[n / 2] * v[n / 2] << '\n';

	return 0;
}
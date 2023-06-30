#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int m;
	int element;

	set<int> a;
	int count = 0;

	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		cin >> element;
		a.insert(element);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> element;
		if (a.find(element) != a.end())
			count++;
	}

	cout << n + m - 2 * count << '\n';

	return 0;
}
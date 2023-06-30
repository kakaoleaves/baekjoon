#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int m;
	set<int> s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << s.count(num) << '\n';
	}

	return 0;
}
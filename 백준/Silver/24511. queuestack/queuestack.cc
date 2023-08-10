#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;				// 1 <= n <= 100'000
	int m;				// 1 <= m <= 100'000
	vector<int> a;		// a[i] = 0 or 1
	vector<int> b;		// 1 <= b[i] <= 1'000'000'000
	deque<int> dq;

	cin >> n;

	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	b.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		if (a[i] == 0)
			dq.push_back(b[i]);
	}

	cin >> m;

	while (m--)
	{
		int num;
		cin >> num;
		dq.push_front(num);
		cout << dq.back() << ' ';
		dq.pop_back();
	}


	return 0;
}
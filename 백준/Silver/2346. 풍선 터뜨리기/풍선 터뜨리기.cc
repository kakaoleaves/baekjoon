#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	deque<pair<int, int>> dq(n);

	for (int i = 0; i < n; ++i)
	{
		dq[i].first = i + 1;
		cin >> dq[i].second;
	}

	while (!dq.empty())
	{
		cout << dq.front().first << ' ';
		int temp = dq.front().second;
		dq.pop_front();

		if (dq.empty())
			break;

		if (temp > 0)
		{
			for (int i = 0; i < temp - 1; ++i)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < -temp; ++i)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}
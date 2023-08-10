#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;		// 1 <= n <= 1000
	cin >> n;

	queue<int> q;
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	int cnt = 1;

	while (!q.empty())
	{
		if (q.front() == cnt)
		{
			cnt++;
			q.pop();
			continue;
		}
		
		if (!s.empty() && s.top() == cnt)
		{
			cnt++;
			s.pop();
			continue;
		}

		s.push(q.front());
		q.pop();
	}

	while (!s.empty() && s.top() == cnt)
	{
		cnt++;
		s.pop();
	}

	cout << (cnt == n + 1 ? "Nice" : "Sad") << endl;

	return 0;
}
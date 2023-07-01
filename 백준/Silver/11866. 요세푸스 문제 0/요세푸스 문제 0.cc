#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int m;
	cin >> n >> m;

	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < m - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">\n";

	return 0;
}
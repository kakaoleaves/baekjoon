#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dps(int a)
{
	if (a == m)
	{
		for (int i = 0; i < m; i++) 
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[a] = i + 1;
			dps(a + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	dps(0);
	return 0;
}
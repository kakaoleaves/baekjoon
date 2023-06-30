#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	unordered_map<int, int> cardmap;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		cardmap[num]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num = 0;
		cin >> num;
		cout << cardmap[num] << " ";
	}

	return 0;
}
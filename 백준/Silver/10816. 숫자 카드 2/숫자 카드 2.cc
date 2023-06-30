#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<int> cardmap(500002);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cardmap[i];
	}

	sort(cardmap.begin(), cardmap.begin() + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num = 0;
		cin >> num;
		cout << upper_bound(cardmap.begin(), cardmap.begin() + n, num) - lower_bound(cardmap.begin(), cardmap.begin() + n, num) << " ";
	}

	return 0;
}
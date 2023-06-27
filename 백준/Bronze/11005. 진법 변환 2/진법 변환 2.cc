#include <iostream>
using namespace std;

const int MAX = 32;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int b;
	char ans[MAX] = { NULL };
	int len = 0;

	cin >> n >> b;
	while (n > 0)
	{
		int r = n % b;
		ans[len++] = r < 10 ? (char)r + '0' : (char)(r - 10) + 'A';
		n /= b;
	}

	for (int i = len - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int gcd = 1;
		for (int j = 1; j <= min(a, b); j++)
		{
			if (a % j == 0 && b % j == 0)
				gcd = j;
		}
		int lcm = a * b / gcd;
		cout << lcm << '\n';
	}

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;

	if (a % b == 0)
		cout << a << "\n";
	else if (b % a == 0)
		cout << b << "\n";
	else
	{
		int gcb = 1;
		for (int i = 1; i <= min(a, b); i++)
		{
			if (a % i == 0 && b % i == 0)
				gcb = i;
		}
		cout << gcb * (a / gcb) * (b / gcb) << "\n";
	}

	return 0;
}
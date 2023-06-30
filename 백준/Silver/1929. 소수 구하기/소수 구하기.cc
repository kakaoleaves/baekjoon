#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i <= sqrt(n); i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		if (isPrime(i))
			cout << i << '\n';
	}

	return 0;
}
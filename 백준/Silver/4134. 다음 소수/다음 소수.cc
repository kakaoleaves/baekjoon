#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned int n)
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

unsigned int findNextPrime(unsigned int n)
{
	while (!isPrime(n))
		n++;
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		unsigned int num;
		cin >> num;

		cout << findNextPrime(num) << '\n';
	}

	return 0;
}
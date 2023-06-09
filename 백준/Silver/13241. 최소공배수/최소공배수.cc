#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long lcm(int a, int b)
{
	return (long long)a * b / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << '\n';

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int gcd = 1;
	int lcm = 1;

	for (int i = 0; i < min(b, d); i++)
	{
		if (b % (i + 1) == 0 && d % (i + 1) == 0)
		{
			gcd = i + 1;
		}
	}

	lcm = (b * d) / gcd;

	int numerator = a * (lcm / b) + c * (lcm / d);
	int denominator = lcm;

	for (int i = 0; i < min(numerator, denominator); i++)
	{
		if (numerator % (i + 1) == 0 && denominator % (i + 1) == 0)
		{
			gcd = i + 1;
		}
	}

	cout << numerator / gcd << " " << denominator / gcd << "\n";

	return 0;
}
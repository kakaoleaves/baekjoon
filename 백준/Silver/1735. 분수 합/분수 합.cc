#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int numerator = a * d + b * c;
	int denominator = b * d;

	int gcd_num = gcd(numerator, denominator);

	cout << numerator / gcd_num << " " << denominator / gcd_num << "\n";

	return 0;
}
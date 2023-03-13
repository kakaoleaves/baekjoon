#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, price;
	cin >> a >> b >> c;

	if (a == b && b == c)
	{
		price = 10000 + a * 1000;
	}
	else if (a == b || a == c || b == c)
	{
		price = 1000 + (a == b ? a : c) * 100;
	}
	else
	{
		price = max(max(a, b), c) * 100;
	}
	cout << price;

	return 0;
}
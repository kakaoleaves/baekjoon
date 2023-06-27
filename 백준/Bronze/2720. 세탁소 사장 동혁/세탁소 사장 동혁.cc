#include <iostream>
using namespace std;

const int QUARTER	= 25;
const int DIME		= 10;
const int NICKEL	= 5;
const int PENNY		= 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test;
	int c;

	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> c;
		int q = c / QUARTER;
		c %= QUARTER;
		int d = c / DIME;
		c %= DIME;
		int n = c / NICKEL;
		c %= NICKEL;
		int p = c / PENNY;
		c %= PENNY;
		cout << q << " " << d << " " << n << " " << p << "\n";
	}

	return 0;
}
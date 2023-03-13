#include <iostream>
using namespace std;


int main(void)
{
	int a, b, c, h, m;
	cin >> a >> b;
	cin >> c;

	h = (b + c) / 60 + a;
	m = (b + c) % 60;
	if (h >= 24) h %= 24;

	cout << h << ' ' << m << endl;

	return 0;
}
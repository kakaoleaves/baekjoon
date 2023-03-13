#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	int x, n, a, b, sum = 0;
	cin >> x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}

	cout << (sum == x ? "Yes" : "No") << endl;

	return 0;
}
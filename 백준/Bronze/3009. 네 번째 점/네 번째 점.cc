#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (x1 == x2)
		cout << x3 << " ";
	else if (x1 == x3)
		cout << x2 << " ";
	else
		cout << x1 << " ";

	if (y1 == y2)
		cout << y3 << "\n";
	else if (y1 == y3)
		cout << y2 << "\n";
	else
		cout << y1 << "\n";

	return 0;
}
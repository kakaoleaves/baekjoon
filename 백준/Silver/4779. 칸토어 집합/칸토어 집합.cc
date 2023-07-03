#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void cantoring(int idx, int n)
{
	if ((idx / n) % 3 == 1)
		cout << " ";
	else
	{
		if (n / 3 == 0)
			cout << "-";
		else
			cantoring(idx, n / 3);
	}
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n)
	{
		int k = (int)pow(3, n);
		for (int i = 0; i < k; i++)
		{
			cantoring(i, k);
		}
		cout << "\n";
	}

	return 0;
}
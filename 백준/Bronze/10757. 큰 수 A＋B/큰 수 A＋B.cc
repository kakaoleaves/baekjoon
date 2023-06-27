#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10001;
char a[MAX];
char b[MAX];
char total[MAX] = { '0' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;

	int len_a = strlen(a);
	int len_b = strlen(b);

	int len_total = max(len_a, len_b);

	int carry = 0;
	int temp = 0;

	for (int i = 0; i < len_total; i++)
	{
		temp = carry;

		if (i < len_a)
		{
			temp += a[len_a - i - 1] - '0';
		}

		if (i < len_b)
		{
			temp += b[len_b - i - 1] - '0';
		}

		carry = temp / 10;
		total[len_total - i - 1] = temp % 10 + '0';
	}

	if (carry > 0)
	{
		cout << carry;
	}

	cout << total;

	return 0;
}
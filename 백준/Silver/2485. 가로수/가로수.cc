#include <iostream>
#include <vector>
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

	int n;
	vector<int> v;
	cin >> n;

	int first;
	int second;
	int prev;
	int count = 0;

	cin >> first;
	cin >> second;
	cin >> prev;

	v.push_back(second - first);
	v.push_back(prev - second);
	int gcd_num = gcd(v[0], v[1]);

	for (int i = 3; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num - prev);
		gcd_num = gcd(gcd_num, v[i - 1]);
		prev = num;
	}

	for (int i = 0; i < n - 1; i++)
	{
		count += (v[i] / gcd_num) - 1;
	}

	cout << count << '\n';

	return 0;
}
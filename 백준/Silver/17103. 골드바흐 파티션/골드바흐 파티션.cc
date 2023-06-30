#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> v;
	cin >> n;
	int maximum = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		maximum = max(maximum, num);
	}

	vector<bool> prime(maximum + 1, true);
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(maximum); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= maximum; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int goldbach= 0;
		for (int j = 2; j <= v[i] / 2; j++)
		{
			if (prime[j] && prime[v[i] - j])
			{
				goldbach++;
			}
		}
		cout << goldbach << "\n";
	}
	
	return 0;
}
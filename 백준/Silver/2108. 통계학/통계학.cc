#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

const int ELEMENT_SIZE = 8001;
const int MAX = 4000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long sum = 0;
	multiset<int> s;
	vector<int> v(ELEMENT_SIZE, 0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
		sum += num;
		v[num + MAX]++;
	}

	int mean = (int)((double)sum / n + (sum > 0 ? 0.5 : -0.5));
	int median = *next(s.begin(), n / 2);
	int mode = 0;
	int mode_max = 0;
	bool is_second = false;
	for (int i = 0; i < ELEMENT_SIZE; i++)
	{
		if (v[i] > mode_max)
		{
			mode_max = v[i];
			mode = i - MAX;
			is_second = false;
		}
		else if (v[i] == mode_max && !is_second)
		{
			mode = i - MAX;
			is_second = true;
		}
	}

	int range = *s.rbegin() - *s.begin();

	cout << mean << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range << '\n';

	return 0;
}
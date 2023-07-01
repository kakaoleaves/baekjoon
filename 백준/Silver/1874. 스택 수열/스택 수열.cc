#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int cur = 0;
	vector<char> v;
	stack<int> s;

	cin >> n;

	bool isStackSequence = true;
	bool isAllPushed = false;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (isStackSequence == false) continue;

		while (cur < num)
		{
			cur++;
			s.push(cur);
			v.push_back('+');
		}

		if (s.top() == num)
		{
			s.pop();
			v.push_back('-');
		}
		else
		{
			isStackSequence = false;
		}
	}

	if (isStackSequence)
	{
		for (auto c : v)
		{
			cout << c << '\n';
		}
	}
	else
	{
		cout << "NO" << '\n';
	}

	return 0;
}
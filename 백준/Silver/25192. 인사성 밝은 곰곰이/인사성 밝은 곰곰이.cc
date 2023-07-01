#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<unordered_set<string>> v;

	int count = 0;

	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;
		if (str == "ENTER")
		{
			unordered_set <string> s;
			v.push_back(s);
		}
		else
		{			
			v.back().insert(str);
		}
	}

	for (auto it = v.begin(); it != v.end(); it++)
	{
		count += (*it).size();
	}

	cout << count << endl;

	return 0;
}
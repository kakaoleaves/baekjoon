#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const string CHONGCHONG = "ChongChong";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	unordered_set<string> s;

	cin >> n;

	while (n--)
	{
		string s1;
		string s2;

		cin >> s1 >> s2;

		if (s.empty() && s1 != CHONGCHONG && s2 != CHONGCHONG)
			continue;
		else if (s1 == CHONGCHONG || s2 == CHONGCHONG)
		{
			s.insert(s1);
			s.insert(s2);
		}
		else
		{
			if (s.find(s1) != s.end())
				s.insert(s2);
			else if (s.find(s2) != s.end())
				s.insert(s1);
		}
	}

	cout << s.size() << '\n';

	return 0;
}
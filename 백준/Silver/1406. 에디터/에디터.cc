#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str; // 최대 100000 글자
	cin >> str;

	list<char> strlist;

	for (int i = 0; i < str.size(); i++)
	{
		strlist.push_back(str[i]);
	}

	auto cursor = strlist.end();

	int m; // 1 <= m <= 500000
	cin >> m;

	while (m--)
	{
		char cmd;
		cin >> cmd;
		switch (cmd) {
		case 'L':
			if (cursor != strlist.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != strlist.end())
				cursor++;
			break;
		case 'B':
			if (cursor != strlist.begin())
			{
					cursor--;
					cursor = strlist.erase(cursor);
			}
			break;
		case 'P':
			char c;
			cin >> c;
			strlist.insert(cursor, c);
			break;
		default:
			break;
		}
	}

	for (const char& c : strlist) cout << c;
	cout << '\n';

	return 0;
}
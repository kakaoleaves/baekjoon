#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t; // 테스트 케이스 수
	cin >> t;

	while (t--)
	{
		string str; // 입력한 문자열
		cin >> str;
		
		list<char> l;
		auto cursor = l.end();

		for (int i = 0; i < str.size(); i++)
		{
			switch (str[i]) {
			case '-':
				if (cursor != l.begin()) cursor = l.erase(--cursor);
				break;
			case '<':
				if (cursor != l.begin()) cursor--;
				break;
			case '>':
				if (cursor != l.end()) cursor++;
				break;
			default:
				l.insert(cursor, str[i]);
				break;
			}
		}

		for (const char& c : l) cout << c;
		cout << '\n';
	}

	return 0;
}
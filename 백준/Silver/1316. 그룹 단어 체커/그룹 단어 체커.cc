#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n, isGroupWord;
	char input[101];

	cin >> n;
	isGroupWord = n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		int len = strlen(input);
		int alphabet[26] = { 0, };
		for (int j = 0; j < len; j++)
		{
			if (alphabet[input[j] - 'a'] == 0)
			{
				alphabet[input[j] - 'a'] = 1;
			}
			else
			{
				if (input[j] != input[j - 1])
				{
					isGroupWord--;
					break;
				}
			}
		}
	}

	cout << isGroupWord << endl;

	return 0;
}
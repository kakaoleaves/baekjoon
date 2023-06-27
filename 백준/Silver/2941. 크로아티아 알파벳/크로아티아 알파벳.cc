#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char input[101];
	int len = 0;
	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		if (((input[i] == 'c' || input[i] == 'd') && input[i + 1] == '-') ||
			((input[i] == 'l' || input[i] == 'n') && input[i + 1] == 'j') ||
			((input[i] == 'c' || input[i] == 's' || input[i] == 'z') && input[i + 1] == '='))
		{
			len++;
			i++;
		}
		else if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=')
		{
			len++;
			i += 2;
		}
		else
		{
			len++;
		}
	}

	cout << len << endl;

	return 0;
}

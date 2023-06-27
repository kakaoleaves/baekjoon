#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[101];
	char reversed[101];

	cin.getline(str, 101);

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		reversed[i] = str[len - i - 1];
	}
	reversed[len] = '\0';

	if (strcmp(str, reversed) == 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}
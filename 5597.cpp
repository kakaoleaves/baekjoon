#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	int n;
	set <int> s;

	for (int i = 0; i < 30; i++)
		s.insert(i+1);

	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		s.erase(n);
	}

	for (set<int>::iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		cout << *itr <<endl;
	}

	return 0;
}
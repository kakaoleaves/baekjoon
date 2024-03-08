#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int m;
vector<string> pokemons(100001);
unordered_map<string, int> nameToIndex;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		pokemons[i] = name;
		nameToIndex[pokemons[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string query;
		cin >> query;
		if (isdigit(query[0])) {
			int idx = stoi(query);
			cout << pokemons[idx] << "\n";
		}
		else {
			cout << nameToIndex[query] << "\n";
		}
	}

	return 0;
}
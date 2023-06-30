#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;

    vector<string> pokemon_v;
    map<string, int> pokemon_um;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string pokemon;
		cin >> pokemon;
        pokemon_v.push_back(pokemon);
        pokemon_um.insert(make_pair(pokemon, i + 1));
	}

    for (int i = 0; i < m; i++)
    {
        string question;
        cin >> question;
        char c = question[0];
        if (isdigit(c))
        {
			cout << pokemon_v[stoi(question) - 1] << "\n";
		}
		else 
        {
            cout << pokemon_um[question] << "\n";
        }
    }

    return 0;
}
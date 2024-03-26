#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> v(21, false);
	int m;

	cin >> m;

	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			int x;
			cin >> x;
			v[x] = true;
		}
		else if (cmd == "remove") {
			int x;
			cin >> x;
			v[x] = false;
		}
		else if (cmd == "check") {
			int x;
			cin >> x;
			cout << v[x] << '\n';
		}
		else if (cmd == "toggle") {
			int x;
			cin >> x;
			v[x] = !v[x];
		}
		else if (cmd == "all") {
			v = vector<bool>(21, true);
		}
		else if (cmd == "empty") {
			v = vector<bool>(21, false);
		}
	}

	return 0;
}
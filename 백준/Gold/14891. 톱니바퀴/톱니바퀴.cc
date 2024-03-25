#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> cogs(4, vector<char>(8));
vector<pair<int, int>> rotations(100);
int k;
int score;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	for (int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++)
			cogs[i][j] = s[j];
	}

	cin >> k;
	rotations.resize(k);
	for (int i = 0; i < k; i++)
	{
		int num, dir;
		cin >> num >> dir;
		rotations[i] = { num - 1, dir };
	}

	for (auto& info : rotations) {
		vector<int> dirs(4);
		int num = info.first;
		int dir = info.second;
		dirs[num] = dir;

		// 오른쪽
		for (int i = num + 1; i <= 3; i++) {
			if (cogs[i][6] != cogs[i - 1][2]) {
				dirs[i] = -dirs[i - 1];
			}
			else {
				break;
			}
		}

		// 왼쪽
		for (int i = num - 1; i >= 0; i--) {
			if (cogs[i][2] != cogs[i + 1][6]) {
				dirs[i] = -dirs[i + 1];
			}
			else {
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (dirs[i] == 1) { // 시계방향
				rotate(cogs[i].rbegin(), cogs[i].rbegin() + 1, cogs[i].rend());
			}
			else if (dirs[i] == -1) { // 반시계방향
				rotate(cogs[i].begin(), cogs[i].begin() + 1, cogs[i].end());
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (cogs[i][0] == '1') {
			score += (1 << i);
		}
	}

	cout << score << '\n';

	return 0;
}
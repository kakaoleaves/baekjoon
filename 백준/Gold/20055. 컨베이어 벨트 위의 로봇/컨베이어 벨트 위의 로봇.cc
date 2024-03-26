#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int n;
int k;
vector<int> a(200);
list<int> robot;
int up;
int down;
int stage;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	a.resize(2 * n);

	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}

	up = 0;
	down = n - 1;

	while (k > 0) {
		// 1. 벨트가 한 칸 회전한다.
		up = (up - 1 + 2 * n) % (2 * n);
		down = (down - 1 + 2 * n) % (2 * n);

		// 로봇이 내려가는 위치에 있으면 내려준다.
		if (!robot.empty() && robot.back() == down) {
			robot.pop_back();
		}

		// 2. 로봇이 한 칸 이동한다.
		list<int> next_robot;
		for (auto it = robot.rbegin(); it != robot.rend(); it++) {
			int cur = *it;
			int next = (cur + 1) % (2 * n);

			if (!next_robot.empty() && find(next_robot.begin(), next_robot.end(), next) != next_robot.end()) {
				// 이미 로봇이 있는 경우
				next_robot.push_front(cur);
			}
			else if (a[next] > 0) {
				// 이동할 수 있는 경우
				a[next]--; if (a[next] == 0) k--;
				if (next != down) {
					next_robot.push_front(next); // 내려가는 위치가 아니면 그냥 이동
				}
			}
			else { // 이동할 수 없는 경우
				next_robot.push_front(cur);
			}
		}

		robot = next_robot;

		// 3. 올라가는 위치에 로봇이 없으면 로봇을 하나 올린다.
		if (find(robot.begin(), robot.end(), up) == robot.end() && a[up] > 0) {
			a[up]--; if (a[up] == 0) k--;
			robot.push_front(up);
		}

		stage++;
	}

	cout << stage << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct FireBall {
	int id; // 고유 번호
	int r; // 행
	int c; // 열
	int m; // 질량 (1 ~ 1000)
	int s; // 속도 (1 ~ 1000)
	int d; // 방향 (0 ~ 7)
};

int n; // 격자 크기
int m; // 파이어볼 개수
int k; // 이동 명령
vector<FireBall> fireballs;

const int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	fireballs.resize(m);

	for (int i = 0; i < m; i++) {
		fireballs[i].id = i;
		cin >> fireballs[i].r >> fireballs[i].c >> fireballs[i].m >> fireballs[i].s >> fireballs[i].d;
		fireballs[i].r--;
		fireballs[i].c--;
	}

	while (k--) {
		unordered_map<int, vector<int>> board;

		// 파이어볼을 이동시킨다
		for (auto& fb : fireballs) {
			int nr = fb.r + dr[fb.d] * fb.s;
			int nc = fb.c + dc[fb.d] * fb.s;

			nr = (nr % n + n) % n;
			nc = (nc % n + n) % n;

			int pos = (nr << 6) | nc;
			board[pos].push_back(fb.id);

			fb.r = nr;
			fb.c = nc;
		}

		vector<FireBall> new_fireballs;

		for (auto& [pos, ids] : board) {
			if (ids.empty()) continue;
			else if (ids.size() == 1) {
				// 이동한 파이어볼이 하나인 경우 그대로 저장
				auto target = fireballs[ids.front()];
				auto new_id = new_fireballs.size();
				target.id = new_id;
				new_fireballs.push_back(target);
				continue;
			}
			// 이동한 파이어볼이 두 개 이상인 경우

			int sum_m = 0;
			int sum_s = 0;

			int first_d = fireballs[ids.front()].d % 2;
			// 모두 홀수이거나 모두 짝수인 경우
			bool sum_d = all_of(
				ids.begin(), ids.end(),
				[&](int id) { return fireballs[id].d % 2 == first_d; }
			);

			for (int id : ids) {
				sum_m += fireballs[id].m;
				sum_s += fireballs[id].s;
			}

			int new_m = sum_m / 5;

			if (new_m == 0) continue; // 질량이 0인 파이어볼은 소멸

			int new_s = sum_s / ids.size();

			auto new_id = new_fireballs.size();
			for (int i = 0; i < 4; i++) {
				FireBall newFireBall = { new_id, pos >> 6, pos & 63, new_m, new_s, sum_d ? i * 2 : i * 2 + 1 };
				new_fireballs.push_back(newFireBall);
				new_id++;
			}
		}
		fireballs = new_fireballs;
	}

	int sum = 0;
	for (const auto& fb : fireballs) {
		sum += fb.m;
	}

	cout << sum << '\n';

	return 0;
}
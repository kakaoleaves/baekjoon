#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int n; // 지도의 크기; 2< = n <= 100
int l; // 경사로 길이' 1 <= l <= n
vector<vector<int>> map(100, vector<int>(100, 0)); // 지도
int ans; // 지나갈 수 있는 길의 개수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            vector<int> road;

            for (int k = 0; k < n; k++)
            {
				if (j == 0) road.push_back(map[i][k]);
				else road.push_back(map[k][i]);
			}

            vector<bool> ramp(n, false);

            int cur_idx = 0;
            while (cur_idx < n -1)
            {
                auto cur = road.begin() + cur_idx;
                auto next = find_if(cur + 1, road.end(), [&](int x) { return x != *cur; });

                // 마지막까지 같은 높이인 경우 : 통과!
                if (next == road.end()) { cur_idx = n - 1; break; }

                // 높이 차가 1보다 큰 경우 : 불가능!
                auto diff = *next - *cur;
                if (abs(diff) > 1) break;

                // 오르막길
                if (diff == 1)
                {
                    auto dist = distance(cur, next);
                    if (dist < l) break; // 경사로를 놓을 수 없는 경우 : 불가능!

                    auto ramp_start = ramp.begin() + cur_idx + dist - l;
                    auto ramp_end = ramp.begin() + cur_idx + dist;

                    if (find(ramp_start, ramp_end, true) != ramp_end) break; // 경사로를 놓을 수 없는 경우 : 불가능!
                    fill(ramp_start, ramp_end, true);
                    cur_idx += dist; // cur이 next가 됨
                }
                // 내리막길
                else
                {
                    auto nn = find_if (next + 1, road.end(), [&](int x) { return x != *next; });
                    auto dist_nn = distance(next, nn);
                    if (dist_nn < l) break; // 경사로를 놓을 수 없는 경우 : 불가능!

                    auto dist_n = distance(cur, next);
                    auto ramp_start = ramp.begin() + cur_idx + 1;
                    auto ramp_end = ramp.begin() + cur_idx + 1 + l;

                    if (find(ramp_start, ramp_end, true) != ramp_end) break; // 경사로를 놓을 수 없는 경우 : 불가능!
                    fill(ramp_start, ramp_end, true);

                    cur_idx += l;
                }
            }
            if (cur_idx == n - 1)
            {
                ans++;
            }       
        }
    }

    cout << ans << '\n';

    return 0;
}
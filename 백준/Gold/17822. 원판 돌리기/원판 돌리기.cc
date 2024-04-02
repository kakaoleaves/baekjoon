#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

int n; // 원판의 수(원판의 반지름); 2 <= n <= 50
int m; // 원판 당 적힌 정수의 수; 2 <= m <= 50
int t; // 회전시킨 수; 1 <= t <= 50

struct RotateInfo
{
    int x, d, k;
};

enum { CLOCKWISE, COUNTERCLOCKWISE };

vector<vector<int>> circle(51, vector<int>(50)); // 원판
vector<RotateInfo> rotateInfos(50); // 회전 정보

int ans; // 원판에 적힌 수의 합

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    
    for (int i = 1; i <= n; i++) // 반지름의 길이의 편의성으로 1부터 시작
    {
        for (int j = 0; j < m; j++) // 내부는 0부터 시작
        {
			cin >> circle[i][j];
		}
    }

    for (int i = 0; i < t; i++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        rotateInfos[i] = { x, d, k };
	}

    for (int i = 0; i < t; i++)
    {
        const auto& [x, d, k] = rotateInfos[i];

        // 번호가 x의 배수인 원판을 d 방향으로 k칸 회전한다.
        for (int j = 1; j <= n; j++)
        {
            if (j % x == 0) // 번호가 x의 배수인 원판은 d 방향으로 k칸 회전한다.
            {
                vector<int> v(circle[j].begin(), circle[j].begin() + m);

                if (d == CLOCKWISE)
                {
					rotate(v.rbegin(), v.rbegin() + k, v.rend());
				}
                else
                {
					rotate(v.begin(), v.begin() + k, v.end());
				}
				copy(v.begin(), v.end(), circle[j].begin());
            }
        }

  //      for (int r = 1; r <= n; r++)
  //      {
  //          for (int c = 0; c < m; c++)
  //          {
		//		cout << circle[r][c] << ' ';
		//	}
		//	cout << '\n';
		//}
  //      cout << '\n';


        // 인접하면서 수가 같은 것을 모두 찾는다.
        vector<vector<int>> target(n + 1);
        for (int r = 1; r <= n; r++)
        {
            // 원판에 수가 하나도 없으면 다음 원판으로 넘어간다.
            if (all_of(circle[r].begin(), circle[r].end(), [](int s) { return s == 0; })) continue;

            // 원판의 수가 하나라도 있으면 인접하면서 수가 같은 것을 찾는다.
            for (int c = 0; c < m; c++)
            {
                if (circle[r][c] == 0) continue;

                int pr = r - 1;
                int nr = r + 1;
                int pc = (c - 1 + m) % m;
                int nc = (c + 1) % m;

                if (circle[r][c] == circle[r][nc])
                {
					target[r].push_back(c);
					target[r].push_back(nc);
				}
                if (circle[r][c] == circle[r][pc])
                {
                    target[r].push_back(c);
                    target[r].push_back(pc);
                }
                if (pr >= 1 && circle[r][c] == circle[pr][c])
                {
					target[r].push_back(c);
					target[pr].push_back(c);
				}
                if (nr <= n && circle[r][c] == circle[nr][c])
                {
                    target[r].push_back(c);
                    target[nr].push_back(c);
                }
            }
        }

        // 인접하는 수가 없다면 원판에 적힌 수의 평균을 구해 원판에 적힌 수를 갱신한다.
        if (all_of(target.begin(), target.end(), [](const vector<int>& v) { return v.empty(); }))
        {
            int sum = 0;
            int cnt = 0;
            for (int r = 1; r <= n; r++)
            {
                sum += accumulate(circle[r].begin(), circle[r].end(), 0);
                cnt += count_if(circle[r].begin(), circle[r].end(), [](int s) { return s > 0; });
            }
            if (cnt > 0)
            {
                double avg = static_cast<double>(sum) / cnt;

                for (int r = 1; r <= n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
						if (circle[r][c] == 0) continue;

                        if (circle[r][c] > avg)
                        {
							circle[r][c]--;
						}
                        else if (circle[r][c] < avg)
                        {
							circle[r][c]++;
						}
					}
				}
            }
        }
        // 인접하는 수가 있다면 인접하면서 수가 같은 것을 모두 지운다.
        else
        {
            for (int r = 1; r <= n; r++)
            {
                for (int c : target[r])
                {
                    circle[r][c] = 0;
                }
            }
        }
    }

    for (int r = 1; r <= n; r++)
    {
		ans += accumulate(circle[r].begin(), circle[r].end(), 0);
	}

    cout << ans << '\n';

    return 0;
}
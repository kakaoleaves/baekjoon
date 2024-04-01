#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

enum { BLANK, WALL, VIRUS };

int n; // 연구소의 크기; 4 <= n <= 50
int m; // 바이러스의 개수; 1 <= m <= 10
vector<vector<int>> lab(50, vector<int>(50, 0));
vector<pair<int, int>> virus;

const vector<int> dr = {0, 0, -1, 1};
const vector<int> dc = {-1, 1, 0, 0};

int ans = numeric_limits<int>::max();

void backtracking(int cnt, int last_idx, vector<int>& active)
{
    if (cnt == m)
    {
  //      cout << "Case : ";
  //      for (int i = 0; i < active.size(); i++)
  //      {
		//	cout << active[i] << ' ';
		//}
		//cout << '\n';

        // m개의 바이러스를 선택했으므로 활성화시킨다.
        vector<vector<int>> visited(50, vector<int>(50, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < active.size(); i++)
        {
            auto [r, c] = virus[active[i]];
            q.push({r, c});
            visited[r][c] = 0;
        }

        while (!q.empty())
        {
            auto [r, c] = q.front(); q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (lab[nr][nc] == WALL) continue;
                if (visited[nr][nc] != -1) continue;

                visited[nr][nc] = visited[r][c] + 1;
                q.push({ nr, nc });
            }
        }

        int t = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (lab[i][j] == BLANK && visited[i][j] == -1) // 빈 칸이면서 바이러스가 퍼지지 않은 곳 존재 -> 불가능
                {
					return;
				}
                else
                {
                    if (lab[i][j] == VIRUS) continue;
                    else
                    {
                        t = max(t, visited[i][j]);
                    }
                }
            }
        }

       /* for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == -1)
                {
                    if (lab[i][j] == WALL)
                    {
                        cout << "- ";
                    }
                    else
                    {
						cout << "* ";
					}
                }
                else
                    cout << visited[i][j] << ' ';                
			}
			cout << '\n';
		}*/

        ans = min(ans, t);

        //cout << "ans : " << ans << '\n' << endl;

        return;
    }

    for (int i = last_idx + 1; i < virus.size(); i++)
    {
		active.push_back(i);
		backtracking(cnt + 1, i, active);
		active.pop_back();
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == VIRUS)
            {
				virus.push_back({i, j});
			}
        }
    }

    vector<int> active;
    backtracking(0, -1, active);

    cout << (ans == numeric_limits<int>::max() ? -1 : ans) << '\n';

    return 0;
}
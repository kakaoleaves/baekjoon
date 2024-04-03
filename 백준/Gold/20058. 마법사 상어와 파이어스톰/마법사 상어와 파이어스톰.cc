#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int n; // 2 <= n <= 6; 격자의 크기(지수)
int q; // 1 <= q <= 1000; 파이어스톰 시전 횟수
vector<vector<int>> iceboard(65, vector<int>(65)); // 격자의 크기는 최대 64x64
vector<int> l(1000); // 시전한 단계

const vector<int> dr = { -1, 1, 0, 0 };
const vector<int> dc = { 0, 0, -1, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    
    int sz = 1 << n; // 격자의 크기

    // 격자 입력
    for (int i = 1; i <= sz; i++)
    {
        for (int j = 1; j <= sz; j++)
        {
            cin >> iceboard[i][j];
        }
    }

    // 단계 입력
    for (int i = 0; i < q; i++)
    {
        cin >> l[i];
    }

    // 파이어스톰 시전
    for (int i = 0; i < q; i++)
    {
        int level = l[i];
        int ssz = 1 << level;

        // 시계방향으로 90도 회전
        for (int j = 1; j <= sz; j += ssz)
        {
            for (int k = 1; k <= sz; k += ssz)
            {
                vector<vector<int>> tmp(ssz, vector<int>(ssz));

                for (int r = 0; r < ssz; r++)
                {
                    for (int c = 0; c < ssz; c++)
                    {
                        tmp[r][c] = iceboard[j + r][k + c];
                    }
                }

                // 시계방향으로 90도 회전
                for (int r = 0; r < ssz; r++)
                {
                    for (int c = 0; c < ssz; c++)
                    {
						iceboard[j + r][k + c] = tmp[ssz - 1 - c][r];
					}
				}
            }
        }
        // 얼음 양 줄이기
        vector<vector<int>> tmp(65, vector<int>(65));

        // 얼음 양 줄일 공간 찾기
        for (int r = 1; r <= sz; r++)
        {
            for (int c = 1; c <= sz; c++)
            {
                if (iceboard[r][c] == 0) continue;

                int cnt = 0;

                for (int j = 0; j < 4; j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if (nr < 1 || nr > sz || nc < 1 || nc > sz)
                    {
						continue;
					}

                    if (iceboard[nr][nc] > 0) cnt++;
                }

                if (cnt < 3) tmp[r][c] = -1;
            }
        }

        // 갱신
        for (int r = 1; r <= sz; r++)
        {
            for (int c = 1; c <= sz; c++)
            {
				iceboard[r][c] += tmp[r][c];
			}
		}
    }

    // 남아있는 얼음의 합
    int sum = 0;

    for (int i = 1; i <= sz; i++)
    {
		sum += accumulate(iceboard[i].begin(), iceboard[i].end(), 0);
	}

    // 가장 큰 덩어리의 크기
    int max_ice = 0;

    vector<vector<bool>> visited(sz + 1, vector<bool>(sz + 1, false));
    for (int i = 1; i <= sz; i++)
    {
        for (int j = 1; j <= sz; j++)
        {
            if (iceboard[i][j] == 0 || visited[i][j]) continue;

            int ice = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            visited[i][j] = true;

            while (!q.empty())
            {
                auto [r, c] = q.front();
				q.pop();
				ice++;

                for (int k = 0; k < 4; k++)
                {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (nr < 1 || nr > sz || nc < 1 || nc > sz)
					{
                        continue;
                    }

                    if (iceboard[nr][nc] > 0 && !visited[nr][nc])
                    {
						visited[nr][nc] = true;
						q.push({ nr, nc });
                    }
                }
            }
            max_ice = max(max_ice, ice);
        }
    }

    // 덩어리가 없을 경우 처리
    if (max_ice == 1) max_ice = 0;

    // 출력
    cout << sum << '\n' << max_ice << '\n';


    return 0;
}
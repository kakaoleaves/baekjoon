#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 격자 크기; 2 <= n <= 20
int M; // 상어의 개수; 20 <= m <= n^2
int K; // 냄새가 사라지기 위한 이동 수; 1 <= k <= 1000

const vector<int> dr = { 0, -1, 1, 0, 0 };
const vector<int> dc = { 0, 0, 0, -1, 1 };

struct Shark
{
    int r;
    int c;
	int dir;
    vector<vector<int>> priority;

    Shark() : r(0), c(0), dir(0), priority(5, vector<int>(5, 0)) {}
};

vector<vector<pair<int,int>>> board(21, vector<pair<int,int>>(21, make_pair(0, 0)));
vector<Shark> sharks;
vector<bool> isAlive;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    sharks.assign(M + 1, Shark());
    isAlive.assign(M + 1, true);
    isAlive.front() = false; // 0번 상어는 없음.

    // 입력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int shark_num;
            cin >> shark_num;

            if (shark_num != 0)
            {
				board[i][j] = make_pair(shark_num, K);
				sharks[shark_num].r = i;
				sharks[shark_num].c = j;
			}
        }
    }

    // 상어의 방향 입력
    for (int i = 1; i <= M; i++)
    {
		cin >> sharks[i].dir;
	}

    // 상어의 방향 별 우선순위 입력
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
				cin >> sharks[i].priority[j][k];
			}
		}
	}

    // 1000초가 기준
    while (t <= 1000)
    {
        t++;

        // 상어의 이동 : 한번에 이동하므로 한번에 업데이트 해야함.
        vector<Shark> next_sharks = sharks;
        vector<vector<pair<int,int>>> next_board = board;

        // 냄새 시간 감소 (미리 해야 새로 냄새를 뿌린 곳 값이 수정되지 않음)
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
				auto& [shark_num, smell_t] = next_board[i][j];

                if (shark_num != 0)
                {
					smell_t--;
					if (smell_t == 0) shark_num = 0;
				}
			}
		}

        // 상어 이동 결정 (반대로 해야 뒤에 있는 상어를 덮어씀)
        for (int i = M; i >= 1; i--)
        {
            auto& [r, c, dir, priority] = sharks[i];

            if (!isAlive[i]) continue; // 죽은 상어는 넘어감.

            bool isMove = false;

            for (int j = 1; j <= 4; j++)
            {
                int ndir = priority[dir][j];
                int nr = r + dr[ndir];
                int nc = c + dc[ndir];

                if (nr < 1 || nr > N || nc < 1 || nc > N) continue; // 범위를 벗어나면 넘어감.

                auto const& [shark_num, smell_t] = board[nr][nc];

                if (shark_num == 0) // 냄새가 없는 빈칸
                {
                    //cout << i << "번 상어 : " << r << ' ' << c << " -> " << nr << ' ' << nc << '\n';

                    isMove = true;
					next_sharks[i].r = nr;
					next_sharks[i].c = nc;
					next_sharks[i].dir = ndir;
                    next_board[nr][nc] = make_pair(i, K);
					break;
				}
            }

            if (!isMove) // 빈칸이 없으므로 자신의 냄새 있는 곳으로
            {
                for (int j = 1; j <= 4; j++)
                {
                    int ndir = priority[dir][j];
					int nr = r + dr[ndir];
					int nc = c + dc[ndir];

					if (nr < 1 || nr > N || nc < 1 || nc > N) continue; // 범위를 벗어나면 넘어감.

					const auto& [shark_num, smell_t] = board[nr][nc];

                    if (shark_num == i) // 자신의 냄새가 있는 곳
                    {
                        //cout << i << "번 상어 : " << r << ' ' << c << " -> " << nr << ' ' << nc << '\n';
                        next_sharks[i].r = nr;
						next_sharks[i].c = nc;
						next_sharks[i].dir = ndir;
                        next_board[nr][nc] = make_pair(i, K);
						break;
					}
                }
            }
        }

        // 상어 이동 후 상어의 위치와 냄새 갱신
        sharks = next_sharks;
        board = next_board;

        // 상어 이동 후 상어가 겹치는 경우 처리
        for (int i = 1; i <= M; i++)
        {
            if (!isAlive[i]) continue;
            const int& fsr = sharks[i].r;
            const int& fsc = sharks[i].c;

            for (int j = i + 1; j <= M; j++)
            {
                if (!isAlive[j]) continue;

                const int& ssr = sharks[j].r;
                const int& ssc = sharks[j].c;                
                if (fsr == ssr && fsc == ssc) // 겹치는 경우
                {
					isAlive[j] = false; // 뒤에 있는 상어 쫓겨남
				}
            }
        }

        //cout << "Board " << '\n';
        //for (int i = 1; i <= N; i++)
        //{
        //    for (int j = 1; j <= N; j++)
        //    {
        //        cout << board[i][j].first << ' ';
        //    }
        //    cout << '\n';
        //}

        //cout << "Sharks " << '\n';
        //for (int i = 1; i <= N; i++)
        //{
        //    for (int j = 1; j <= N; j++)
        //    {
        //        cout << board[i][j].second << ' ';
        //    }
        //    cout << '\n';
        //}

  //      for (int i = 1; i <= M; i++)
  //      {
  //          if (!isAlive[i]) continue;
		//	cout << i << "번 상어 : " << sharks[i].r << ' ' << sharks[i].c << ' ' << sharks[i].dir << '\n';
		//}

        // 살아있는 상어의 수 확인
        if (count(isAlive.begin(), isAlive.end(), true) == 1) break;
    }

    cout << (t > 1000 ? -1 : t) << '\n';   

    return 0;
}
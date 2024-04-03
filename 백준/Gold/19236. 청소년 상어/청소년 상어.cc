#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish
{
    int r, c, dir;
};

vector<vector<int>> board(4, vector<int>(4, 0));
vector<Fish> fish(17);
vector<bool> alive(17, true);

const vector<int> dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
const vector<int> dc = { 0, -1, -1, -1, 0, 1, 1, 1 };

int ans = 0;

bool IsValid(int r, int c)
{
    return r >= 0 && r < 4 && c >= 0 && c < 4;
}

void FishMove(int sr, int sc)
{
    for (int i = 1; i <= 16; i++)
    {
        if (!alive[i]) continue; // 죽은 물고기는 통과

        auto [r, c, dir] = fish[i];

        for (int j = 0; j < 8; j++)
        {
            int ndir = (dir + j) % 8; // 45도씩 반시계 방향으로 회전

            int nr = r + dr[ndir];
            int nc = c + dc[ndir];

            if (!IsValid(nr, nc) || (nr == sr && nc == sc)) continue;

            fish[i] = { nr, nc, ndir };

            if (board[nr][nc] > 0) // 다른 물고기가 있다면 해당 물고기 정보 갱신
            {
                int other = board[nr][nc];
				fish[other] = { r, c, fish[other].dir };
            }
            // 물고기 이동 : 현재 위치와 다음 위치 swap
            swap(board[r][c], board[nr][nc]);
            break;
        }

    }
}

bool SharkMovable(int sr, int sc, int sd)
{
    bool canMove = false;
    for (int i = 1; i <= 3; i++)
    {
        int nsr = sr + dr[sd] * i;
        int nsc = sc + dc[sd] * i;

        if (!IsValid(nsr, nsc)) break;

        if (board[nsr][nsc] == 0) continue;

        canMove = true;
        break;
    }

    return canMove;
}

void backtracking(int sr, int sc, int sd, int sum)
{
    vector<vector<int>> board_copy = board;
    vector<Fish> fish_copy = fish;
    vector<bool> alive_copy = alive;

    // 물고기 이동
    FishMove(sr, sc);

    board_copy = board;
	fish_copy = fish;

    // 물고기 이동 후 상어 이동 가능 여부 확인
    if (!SharkMovable(sr, sc, sd))
    {
        ans = max(ans, sum);
        return;
    }

    // 상어 이동 : 백트래킹 - 상어가 물고기를 먹는 경우에 대해
    for (int i = 1; i <= 3; i++)
    {
        int nsr = sr + dr[sd] * i;
        int nsc = sc + dc[sd] * i;

        if (!IsValid(nsr, nsc)) break;
        if (board[nsr][nsc] == 0) continue;

        int fishNum = board[nsr][nsc];
        int fishDir = fish[fishNum].dir;

        board[sr][sc] = 0;
        board[nsr][nsc] = -1;
        alive[fishNum] = false;

        backtracking(nsr, nsc, fishDir, sum + fishNum);

        board = board_copy;
        fish = fish_copy;
        alive = alive_copy;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b; // a : 번호, b : 방향
            cin >> a >> b;
            board[i][j] = a;
            fish[a] = { i, j, b - 1 };
        }
    }

    int fishNum = board[0][0];
    int fishDir = fish[fishNum].dir;

    board[0][0] = 0;
    alive[fishNum] = false;

    backtracking(0, 0, fishDir, fishNum);

    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n; // 체스판의 크기; 4 <= n <= 12
int k; // 말의 개수; 4 <= k <= 10

enum { WHITE, RED, BLUE };
enum { RIGHT = 1, LEFT, UP, DOWN };
const vector<int> dr = {0, 0, 0, -1, 1};
const vector<int> dc = {0, 1, -1, 0, 0};

struct Piece
{
	int r, c, dir;
};

vector<vector<int>> board(13, vector<int>(13, 0)); // 체스판
vector<Piece> pieces(11); // 말의 정보

vector<deque<int>> piece_map(13 * 13); // 체스판에 있는 말의 정보

int turn; // 현재 턴

bool is_valid(int r, int c)
{
    return 1 <= r && r <= n && 1 <= c && c <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
	}

    for (int i = 1; i <= k; i++)
    {
        int r, c, dir;
        cin >> r >> c >> dir;
        pieces[i] = {r, c, dir};
        piece_map[r * n + c].push_back(i);
	}

    while (true)
    {
        // 값이 1000보다 크거나 게임이 종료되지 않으면 -1 출력
        if (turn > 1000)
        {
            cout << -1 << '\n';
            break;
        }

        turn++;

        bool is_end = false;
        for (int i = 1; i <= k; i++)
        {
            auto& [r, c, dir] = pieces[i];
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (!is_valid(nr, nc) || board[nr][nc] == BLUE)
            {
                dir = (dir % 2 == 0) ? dir - 1 : dir + 1;
                nr = r + dr[dir];
                nc = c + dc[dir];
                pieces[i].dir = dir;

                if (!is_valid(nr, nc) || board[nr][nc] == BLUE) { continue; }
                i--; // 다시 이동 : WHITE, RED
                continue;
            }
            else if (board[nr][nc] == WHITE)
            {
                auto& dq = piece_map[r * n + c];
                auto it = find(dq.begin(), dq.end(), i);

                for (auto iter = it; iter != dq.end(); iter++)
                {
                    int num = *iter;
                    pieces[num].r = nr; pieces[num].c = nc;
				}

                auto& ndq = piece_map[nr * n + nc];
                ndq.insert(ndq.end(), it, dq.end());

                dq.erase(it, dq.end());

                if (ndq.size() >= 4) { is_end = true; break; }
            }
            else if (board[nr][nc] == RED)
            {
                auto& dq = piece_map[r * n + c];
                auto it = find(dq.begin(), dq.end(), i);
                deque<int> temp;
                reverse_copy(it, dq.end(), back_inserter(temp));

                for (auto iter = it; iter != dq.end(); iter++)
                {
					int num = *iter;
					pieces[num].r = nr; pieces[num].c = nc;
                }

                auto& ndq = piece_map[nr * n + nc];

                ndq.insert(ndq.end(), temp.begin(), temp.end());
                dq.erase(it, dq.end());

                if (ndq.size() >= 4) { is_end = true; break; }
            }
        }

        if (is_end)
        {
            cout << turn << '\n';
            break;
        }
    }

    return 0;
}
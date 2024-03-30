#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;  // 지도의 세로 크기
int m;  // 지도의 가로 크기
int k;  // 이동하는 횟수
vector<vector<int>> map(21, vector<int>(21, 0));

int x = 1;
int y = 1;
int dir = 0; // 0: 동, 1: 남, 2: 서, 3: 북
int score;

const vector<int> dr = { 0, 1, 0, -1 }; // 동 남 서 북
const vector<int> dc = { 1, 0, -1, 0 };
vector<int> dice = { 1, 2, 3, 4, 5, 6 };

enum
{
    EAST = 0,
    SOUTH,
    WEST,
	NORTH,	
};

enum
{
    TOP = 0,
    BACK,
    RIGHT,
    LEFT,
    FRONT,
    BOTTOM
};

void RollDice(int dir)
{
    int temp = 0;
    switch (dir)
    {
    case EAST:
        temp = dice[TOP];
        dice[TOP] = dice[LEFT];
        dice[LEFT] = dice[BOTTOM];
        dice[BOTTOM] = dice[RIGHT];
        dice[RIGHT] = temp;
        break;
    case WEST:
		temp = dice[TOP];
		dice[TOP] = dice[RIGHT];
		dice[RIGHT] = dice[BOTTOM];
		dice[BOTTOM] = dice[LEFT];
		dice[LEFT] = temp;
		break;
    case NORTH:
        temp = dice[TOP];
        dice[TOP] = dice[FRONT];
        dice[FRONT] = dice[BOTTOM];
        dice[BOTTOM] = dice[BACK];
        dice[BACK] = temp;
        break;
    case SOUTH:
        temp = dice[TOP];
		dice[TOP] = dice[BACK];
		dice[BACK] = dice[BOTTOM];
		dice[BOTTOM] = dice[FRONT];
		dice[FRONT] = temp;
		break;
    }
}

int GetScore(int _x, int _y)
{
    int _score = 1;
    vector<vector<bool>> visited(21, vector<bool>(21, false));
    queue<pair<int, int>> q;

    visited[_x][_y] = true;
    q.push({ _x, _y });

    while (!q.empty())
    {
        auto [r, c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
			int nr = r + dr[i];
			int nc = c + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > m)
            {
				continue;
			}

            if (visited[nr][nc] == false && map[nr][nc] == map[_x][_y])
            {
				visited[nr][nc] = true;
				q.push({ nr, nc });
                _score++;
			}
		}
    }

    _score *= map[x][y];

    return _score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
			cin >> map[i][j];
		}
	}

    while (k--)
    {
        int nr = x + dr[dir];
        int nc = y + dc[dir];

        if (nr < 1 || nr > n || nc < 1 || nc > m)
        {
            dir = (dir + 2) % 4;
            nr = x + dr[dir];
            nc = y + dc[dir];
        }

        RollDice(dir);

        x = nr;
        y = nc;
      
        if (dice[BOTTOM] > map[x][y])
        {
            dir = (dir + 1) % 4;
        }
        else if (dice[BOTTOM] < map[x][y])
        {
            dir = (dir + 3) % 4;
        }

        score += GetScore(x, y);
    }

    cout << score << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n; // 2 <= n <= 100
int k; // 0 <= k <= 100
int l; // 1 <= l <= 100
vector<vector<int>> board(101, vector<int>(101, 0));
vector<pair<int, char>> info;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1; // 사과가 있는 위치
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		info.push_back({ x, c });
	}

	int time = 0;

	// 동, 남, 서, 북
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int direction = 0;	// 뱀의 이동 방향
	int x = 1, y = 1;	// 뱀의 꼬리 위치
	board[x][y] = 2;	// 뱀이 존재하는 위치를 board에 표시
	int index = 0;
	deque<pair<int, int>> snake;
	snake.push_back({ x, y });

	while (true)
	{
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		bool x_range = nx >= 1 && nx <= n;
		bool y_range = ny >= 1 && ny <= n;

		if (!x_range || !y_range || board[nx][ny] == 2)
		{
			time++;
			break;
		}

		if (board[nx][ny] == 0)
		{
			board[nx][ny] = 2;
			snake.push_back({ nx, ny });
			int px = snake.front().first;
			int py = snake.front().second;
			board[px][py] = 0;
			snake.pop_front();
		} 
		else if (board[nx][ny] == 1)
		{
			board[nx][ny] = 2;
			snake.push_back({ nx, ny });
		}

		x = nx;
		y = ny;
		time++;

		if (index < l && time == info[index].first)
		{
			if (info[index].second == 'L')
			{
				direction = (direction - 1 + 4) % 4; // 음수 방지
			}
			else if (info[index].second == 'D')
			{
				direction = (direction + 1) % 4;
			}
			index++;
		}
	}

	cout << time << '\n';

	return 0;
}
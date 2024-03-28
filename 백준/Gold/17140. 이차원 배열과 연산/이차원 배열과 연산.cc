#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r;
int c;
int k;

vector<vector<int>> board(101, vector<int>(101, 0));

int row = 3;
int col = 3;
int t = 0;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> k;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> board[i][j];
		}
	}

	while (t <= 100)
	{
		if (board[r][c] == k) break;

		if (row >= col)
		{
			int new_col = -1; // 새로운 열
			// R 연산
			for (int i = 1; i <= row; i++)
			{
				map<int, int> m; // key : 숫자, val : 개수
				multimap<int, int> mm; // key : 개수, val : 숫자

				// 숫자 개수 세기 (map을 이용하여 자동 정렬)
				for (int j = 1; j <= col; j++)
				{
					if (board[i][j] == 0) continue;

					m[board[i][j]]++;
				}

				// map을 multimap으로 복사
				for (auto it = m.begin(); it != m.end(); it++)
				{
					auto [num, cnt] = *it;
					mm.insert({ cnt, num }); // 개수가 작은 순으로 정렬
				}

				// board 초기화
				for (int j = 1; j <= col; j++)
				{
					board[i][j] = 0;
				}

				// board 채우기
				int idx = 1;
				for (auto it = mm.begin(); it != mm.end(); it++)
				{
					auto [cnt, num] = *it;

					if (idx > 100) break;

					board[i][idx++] = num;
					board[i][idx++] = cnt;
				}

				new_col = max(new_col, idx - 1);
			}

			col = new_col;
		}
		else
		{
			int new_row = -1; // 새로운 행

			// C 연산

			for (int j = 1; j <= col; j++)
			{
				map<int, int> m; // key : 숫자, val : 개수
				multimap<int, int> mm; // key : 개수, val : 숫자

				// 숫자 개수 세기 (map을 이용하여 자동 정렬)
				for (int i = 1; i <= row; i++)
				{
					if (board[i][j] == 0) continue;

					m[board[i][j]]++;
				}

				// map을 multimap으로 복사
				for (auto it = m.begin(); it != m.end(); it++)
				{
					auto [num, cnt] = *it;
					mm.insert({ cnt, num }); // 개수가 작은 순으로 정렬
				}

				// board 초기화
				for (int i = 1; i <= row; i++)
				{
					board[i][j] = 0;
				}

				// board 채우기
				int idx = 1;
				for (auto it = mm.begin(); it != mm.end(); it++)
				{
					auto [cnt, num] = *it;

					if (idx > 100) break;

					board[idx++][j] = num;
					board[idx++][j] = cnt;
				}

				new_row = max(new_row, idx - 1);
			}

			row = new_row;
		}
		t++;
	}

	if (t > 100) t = -1;

	cout << t << '\n';


	return 0;
}
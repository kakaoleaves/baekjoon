#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int FAVORITES = 4;

int n; // 3 <= n <= 20
vector<vector<int>> classroom;
vector<int> students_order;
vector<vector<int>> favorites;
int ans;

const vector<int> dx = { 0, 0, -1, 1 };
const vector<int> dy = { -1, 1, 0, 0 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	const int total_students = n * n;

	classroom.assign(n, vector<int>(n, 0));
	students_order.assign(total_students, 0);
	favorites.assign(total_students, vector<int>(FAVORITES, 0));

	for (int i = 0; i < total_students; i++)
	{
		cin >> students_order[i];
		int f_idx = students_order[i] - 1;
		for (int j = 0; j < FAVORITES; j++)
		{
			cin >> favorites[f_idx][j];
		}
	}

	for (int i = 0; i < total_students; i++)
	{
		int student_num = students_order[i];
		if (i == 0) // 첫 학생은 항상 (1, 1)에 들어감
		{
			classroom[1][1] = student_num;
			continue;
		}

		int x_pos = -1;
		int y_pos = -1;
		int max_like = -1;
		int max_empty = -1;

		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (classroom[x][y] != 0) continue;

				int like = 0;
				int empty = 0;

				for (int a = 0; a < 4; a++) {
					int nx = x + dx[a];
					int ny = y + dy[a];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

					if (classroom[nx][ny] == 0) empty++;
					else {
						for (int b = 0; b < FAVORITES; b++) {
							if (classroom[nx][ny] == favorites[student_num - 1][b]) {
								like++;
								break;
							}
						}
					}
				}

				if (like > max_like || (like == max_like && empty > max_empty)) {
					max_like = like;
					max_empty = empty;
					x_pos = x;
					y_pos = y;
				}
				else if (like == max_like && empty == max_empty) {
					if (x < x_pos || (x == x_pos && y < y_pos)) {
						x_pos = x;
						y_pos = y;
					}
				}
			}
		}
		classroom[x_pos][y_pos] = student_num;
	}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			int student_num = classroom[x][y];
			int like = 0;
			for (int a = 0; a < 4; a++) {
				int nx = x + dx[a];
				int ny = y + dy[a];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				for (int b = 0; b < FAVORITES; b++) {
					if (classroom[nx][ny] == favorites[student_num - 1][b]) {
						like++;
						break;
					}
				}
			}
			if (like == 1) ans += 1;
			else if (like == 2) ans += 10;
			else if (like == 3) ans += 100;
			else if (like == 4) ans += 1000;
		}
	}

	cout << ans << "\n";

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct DragonCurve {
    int x;  // x 좌표
    int y;  // y 좌표
    int d;  // 시작 방향
    int g;  // 세대
};

vector<DragonCurve> dragon_curves(20);
vector<vector<int>> board(101, vector<int>(101, 0));
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    dragon_curves.resize(n);

    for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

        DragonCurve dc = { x, y, d, g };
        dragon_curves[i] = dc;
	}

    for (int i = 0; i < n; i++)
    {
        auto& [x, y, d, g] = dragon_curves[i];
        
        vector<int> dirs;
        dirs.push_back(d);

        for (int i = 0; i < g; i++)
        {
            int size = dirs.size();
            for (int j = size - 1; j >= 0; j--)
            {
                dirs.push_back((dirs[j] + 1) % 4);
            }
        }

        board[y][x] = 1;
        for (int i = 0; i < dirs.size(); i++)
        {
            if (dirs[i] == 0)
            {
				x += 1;
			}
            else if (dirs[i] == 1)
            {
				y -= 1;
			}
            else if (dirs[i] == 2)
            {
				x -= 1;
			}
            else if (dirs[i] == 3)
            {
				y += 1;
			}

			board[y][x] = 1;
		}
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
            {
				ans++;
			}
		}
	}

    cout << ans << '\n';

    return 0;
}
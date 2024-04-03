#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // 보드의 크기; 1<= n <= 20
vector<vector<int>> board(20, vector<int>(20, 0));
int ans = 0;

enum {UP, DOWN, LEFT, RIGHT};

void Print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

void Move(int dir)
{
    switch (dir)
    {
    case UP:
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(board[j][i]);

            // 0이 아닌 수들을 모두 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x != 0; });

            // 같은 수를 만나면 합친다.
            for (int j = 0; j < n - 1; j++)
            {
                if (tmp[j] == tmp[j + 1] && tmp[j] != 0)
                {
					tmp[j] *= 2;
					tmp[j + 1] = 0;
                    j++; // 합쳤으니 다음 수는 건너뛴다.
				}
			}

            // 0이 아닌 수들을 모두 앞으로 당긴다.
			stable_partition(tmp.begin(), tmp.end(), [](int x) {return x != 0; });

            // 보드에 다시 넣는다.
			for (int j = 0; j < n; j++)
				board[j][i] = tmp[j];
        }
        //cout << "UP" << endl;
        //Print();
        break;
    case DOWN:
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(board[j][i]);

            // 0인 수를 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x == 0; });

            // 같은 수를 만나면 합친다.
            for (int j = n - 1; j > 0; j--)
            {
                if (tmp[j] == tmp[j - 1] && tmp[j] != 0)
                {
					tmp[j] *= 2;
					tmp[j - 1] = 0;
                    j--; // 합쳤으니 다음 수는 건너뛴다.
				}
            }

            // 0인 수를 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x == 0; });

            // 보드에 다시 넣는다.
            for (int j = 0; j < n; j++)
                board[j][i] = tmp[j];
        }
        //cout << "DOWN" << endl;
        //Print();
        break;
    case RIGHT:
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
				tmp.push_back(board[i][j]);

            // 0인 수를 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x == 0; });

            // 같은 수를 만나면 합친다.
            for (int j = n - 1; j > 0; j--)
            {
                if (tmp[j] == tmp[j - 1] && tmp[j] != 0)
                {
					tmp[j] *= 2;
					tmp[j - 1] = 0;
                    j--; // 합쳤으니 다음 수는 건너뛴다.
				}
			}

            // 0인 수를 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x == 0; });

            // 보드에 다시 넣는다.
            for (int j = 0; j < n; j++)
				board[i][j] = tmp[j];
        }
        //cout << "RIGHT" << endl;
        //Print();
        break;
    case LEFT:
        for (int i = 0; i < n; i++)
        {
			vector<int> tmp;
			for (int j = 0; j < n; j++)
                tmp.push_back(board[i][j]);

			// 0이 아닌 수들을 모두 앞으로 당긴다.
			stable_partition(tmp.begin(), tmp.end(), [](int x) {return x != 0; });

			// 같은 수를 만나면 합친다.
            for (int j = 0; j < n - 1; j++)
            {
				if (tmp[j] == tmp[j + 1] && tmp[j] != 0)
				{
                    tmp[j] *= 2;
                    tmp[j + 1] = 0;
                    j++; // 합쳤으니 다음 수는 건너뛴다.
                }
            }

            // 0이 아닌 수들을 모두 앞으로 당긴다.
            stable_partition(tmp.begin(), tmp.end(), [](int x) {return x != 0; });

            // 보드에 다시 넣는다.
            for (int j = 0; j < n; j++)
				board[i][j] = tmp[j];
        }
        //cout << "LEFT" << endl;
        //Print();
        break;
    default:
        break;
    }
}


void backtracking(int cnt)
{
    if (cnt == 5)
    {
        for (int i = 0; i < n; i++)
        {
            int mx = *max_element(board[i].begin(), board[i].end());
            ans = max(ans, mx);
        }
        //cout << "================ 완료 ================" << endl;
        return;
    }

    vector<vector<int>> tmp = board;

    for (int i = 0; i < 4; i++)
    {
        // 원하는 방향으로 전체 블록을 옮긴다
        Move(i);
		backtracking(cnt + 1);
        board = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
			cin >> board[i][j];
		}
	}

    backtracking(0);

    cout << ans << '\n';

    return 0;
}
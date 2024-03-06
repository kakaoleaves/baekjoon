#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int n, m; // 8 <= n, m <= 50
vector<vector<char>> board(50, vector<char>(50, 0));
vector<vector<char>> whiteBoard(8, vector<char>(8, 'W'));
vector<vector<char>> blackBoard(8, vector<char>(8, 'B'));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            whiteBoard[i][j] = (i + j) % 2 == 0 ? 'W' : 'B';

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
			blackBoard[i][j] = (i + j) % 2 == 0 ? 'B' : 'W';

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = numeric_limits<int>::max();

    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++) {
            int whiteCount = 0;
			int blackCount = 0;

			for (int k = 0; k < 8; k++)
                for (int l = 0; l < 8; l++) {
					if (board[i + k][j + l] != whiteBoard[k][l])
						whiteCount++;
					if (board[i + k][j + l] != blackBoard[k][l])
						blackCount++;
				}

            ans = min(ans, min(whiteCount, blackCount));
        }

    cout << ans << '\n';

    return 0;
}
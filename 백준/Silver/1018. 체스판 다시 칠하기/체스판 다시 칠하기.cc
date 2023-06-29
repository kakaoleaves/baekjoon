#include <iostream>
#include <cassert>
using namespace std;

char board[50][50];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    assert(n >= 8 && n <= 50 && m >= 8 && m <= 50);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            assert(board[i][j] == 'W' || board[i][j] == 'B');
        }

    int min = 64;

    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++)
        {
            int cnt = 0;
            for (int k = i; k < i + 8; k++)
                for (int l = j; l < j + 8; l++)
                {
                    if ((k + l) % 2 == 0 && board[k][l] == 'B')
						cnt++;
					else if ((k + l) % 2 == 1 && board[k][l] == 'W')
						cnt++;
                }
            if (cnt > 32)
                cnt = 64 - cnt;
            if (cnt < min)
                min = cnt;
        }

    cout << min << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;

void cutPaper(vector<vector<int>>& p, vector<int>& ans, int x, int y, int n)
{
    if (n == 1)
        ans[p[x][y] + 1]++;
    else
    {
        bool isSame = true;
        int first = p[x][y];

        for (int i = x; i < x + n; i++)
            for (int j = y; j < y + n; j++) {
                if (first != p[i][j]) {
					isSame = false;
					break;
				}
            }

        if (isSame)
            ans[first + 1]++;
        else
        {
			int m = n / N;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
                    cutPaper(p, ans, x + i * m, y + j * m, m);
		}
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n; // 1 <= n <= 3^7, n = 3^k, k = 1, 2, 3, ...
    vector<vector<int>> v(n, vector<int>(n, 0));

    for (auto& row : v)
        for (auto& col : row)
			cin >> col;

    vector<int> paper(N);

    cutPaper(v, paper, 0, 0, n);

    for (const auto& p : paper)
		cout << p << '\n';

    return 0;
}
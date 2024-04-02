#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int n; // 재현시의 크기; 5 <= n <= 20
vector<vector<int>> population(21, vector<int>(21, 0)); // 재현시의 인구 수
int ans = numeric_limits<int>::max(); // 인구 차이의 최솟값

bool is_valid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> population[i][j];
        }
    }

    for (int d1 = 1; d1 <= n; d1++)
    {
        for (int d2 = 1; d2 <= n; d2++)
        {
            for (int x = 1; x + d1 + d2 <= n; x++)
            {
                for (int y = 1 + d1; y <= n - d2; y++)
                {
                    //cout << "x: " << x << " y: " << y << " d1: " << d1 << " d2: " << d2 << "\n";
                    vector<vector<int>> boundary(21, vector<int>(21, 0)); // 경계선 정보

                    for (int i = 0; i <= d1; i++)
                    {
                        int nr1 = x + i; // x ~ x + d1
                        int nc1 = y - i; // y ~ y - d1

                        int nr2 = x + d2 + i; // x + d2 ~ x + d2 + d1
                        int nc2 = y + d2 - i; // y + d2 ~ y + d2 - d1

                        //cout << "[" << nr1 << ", " << nc1 << "] [" << nr2 << ", " << nc2 << "]\n";

                        if (is_valid(nr1, nc1)) boundary[nr1][nc1] = 5;
                        if (is_valid(nr2, nc2)) boundary[nr2][nc2] = 5;
                    }

                    for (int i = 0; i <= d2; i++)
                    {
						int nr1 = x + i; // x ~ x + d2
						int nc1 = y + i; // y ~ y + d2
						int nr2 = x + d1 + i; // x + d1 ~ x + d1 + d2
						int nc2 = y - d1 + i; // y - d1 ~ y - d1 + d2

                        //cout << "[" << nr1 << ", " << nc1 << "] [" << nr2 << ", " << nc2 << "]\n";

                        if (is_valid(nr1, nc1)) boundary[nr1][nc1] = 5;
                        if (is_valid(nr2, nc2)) boundary[nr2][nc2] = 5;
                    }
                    
                    for (int i = 1; i <= n; i++)
                    {
                        vector<int>& b = boundary[i];
                        auto first = find(b.begin(), b.end(), 5);
                        auto second = find(b.rbegin(), b.rend(), 5);

                        if (first != b.end() && second != b.rend())
                        {
                            for (auto it = first; it != second.base(); it++)
                            {
                                *it = 5;
                            }
                        }
                    }

                    for (int r = 1; r <= n; r++)
                    {
                        for (int c = 1; c <= n; c++)
                        {
                            if (boundary[r][c] == 0)
                            {
                                if (r < x + d1 && c <= y) boundary[r][c] = 1;
								else if (r <= x + d2 && y < c) boundary[r][c] = 2;
								else if (x + d1 <= r && c < y - d1 + d2) boundary[r][c] = 3;
								else if (x + d2 < r && y - d1 + d2 <= c) boundary[r][c] = 4;
                            }
						}
                    }

                    vector<int> population_sum(6, 0);

                    for (int r = 1; r <= n; r++)
                    {
                        for (int c = 1; c <= n; c++)
                        {
							population_sum[boundary[r][c]] += population[r][c];
						}
					}

                    auto [mn, mx] = minmax_element(population_sum.begin() + 1, population_sum.end());
                    ans = min(ans, *mx - *mn);

                    //for (int r = 1; r <= n; r++)
                    //{
                    //    for (int c = 1; c <= n; c++)
                    //    {
                    //        cout << boundary[r][c] << " ";
                    //    }
                    //    cout << "\n";
                    //}
                    //cout << "\n";
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
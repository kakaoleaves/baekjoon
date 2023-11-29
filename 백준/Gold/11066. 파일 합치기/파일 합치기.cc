#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t; // 테스트 케이스의 수
	int k; // 소설을 구성하는 장의 수, 3 <= k <= 500
	vector<vector<int>> dp(501, vector<int>(501, 0));
	vector<int> sum(501, 0);

	cin >> t;
	
	while (t--)
	{
		cin >> k;

		for (int i = 1; i <= k; ++i)
		{
			int a;
			cin >> a;
			sum[i] = sum[i - 1] + a;
		}

		for (int i = 1; i < k; i++) // i는 간격
		{
			for (int x = 1; x + i <= k; x++) // x는 시작점
			{
				int y = x + i; // y는 끝점
				dp[x][y] = numeric_limits<int>::max(); // 최솟값을 구해야 하므로 최댓값으로 초기화

				for (int mid = x; mid < y; mid++) // mid는 중간점
				{
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
				}
			}
		}

		cout << dp[1][k] << "\n";
	}

	return 0;
}
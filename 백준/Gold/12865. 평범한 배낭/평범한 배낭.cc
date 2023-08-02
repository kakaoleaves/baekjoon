#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Obj {
	int w;
	int v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1<= n <= 100
    int k; // 1<= k <= 100'000

    cin >> n >> k;

    vector<Obj> obj(n + 1); // 입력받은 물건을 저장하는 vector
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); // dp[i][j] : i번째 물건까지 고려했을 때, j무게까지 고려했을 때 최대 가치

    for (int i = 1; i <= n; i++)
        cin >> obj[i].w >> obj[i].v; // 물건의 무게와 가치 입력

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (obj[i].w <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - obj[i].w] + obj[i].v);
			else
				dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}
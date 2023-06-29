#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int card[100];
    int ans = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
	}

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
				int sum = card[i] + card[j] + card[k];
				if (sum <= m && m - sum < m - ans)
					ans = sum;
			}

    cout << ans << endl;

    return 0;
}
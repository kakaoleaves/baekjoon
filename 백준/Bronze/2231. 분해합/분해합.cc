#include <iostream>
using namespace std;

int n; // 1 <= n <= 1'000'000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int tmp = i;
        int sum = i;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == n) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RGB {
    int r;
    int g;
    int b;
};

enum class Color {
    RED,
    GREEN,
    BLUE
};

const int R = static_cast<int>(Color::RED);
const int G = static_cast<int>(Color::GREEN);
const int B = static_cast<int>(Color::BLUE);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 2 <= n <= 1000
    cin >> n;
    vector<RGB> v(n);
    vector<vector<int>> dp(n, vector<int>(3));

    for (auto& i : v)
        cin >> i.r >> i.g >> i.b;

    for (int i = 0; i < n; i++) {
        vector<int>& colorSum = dp[i];
        const RGB& rgb = v[i];

        if (i == 0) {
            colorSum[R] = rgb.r;
            colorSum[G] = rgb.g;
            colorSum[B] = rgb.b;
            continue;
        }

        vector<int>& prevColorSum = dp[i - 1];
        colorSum[R] = min(prevColorSum[G], prevColorSum[B]) + rgb.r;
        colorSum[G] = min(prevColorSum[R], prevColorSum[B]) + rgb.g;
        colorSum[B] = min(prevColorSum[R], prevColorSum[G]) + rgb.b;
    }

    cout << min({ dp[n - 1][R], dp[n - 1][G], dp[n - 1][B] }) << '\n';

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << (long long) n * (n - 1) * (n - 2) / 6 << '\n';
    cout << 3 << '\n';

    return 0;
}
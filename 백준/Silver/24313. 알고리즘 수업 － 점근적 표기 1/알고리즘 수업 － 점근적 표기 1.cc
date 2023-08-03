#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a1; // -100 <= a1 <= 100
    int a0; // -100 <= a0 <= 100
    int c;  // 1 <= c <= 100
    int n0; // 1 <= n0 <= 100

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    if (c - a1 > 0) cout << (a0 / (c - a1) <= n0) << endl;
    else if (c - a1 == 0) cout << (a0 <= 0) << endl;
	else cout << 0 << endl;
}
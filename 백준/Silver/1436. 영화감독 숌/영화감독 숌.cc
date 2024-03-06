#include <iostream>
#include <string>
using namespace std;

int n; // 1 < = n <= 10'000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    int num = 0;
    int cnt = 0;

    while (cnt < n) {
        num++;
        string s = to_string(num);
        if (s.find("666") != string::npos) {
			cnt++;
		}
    }

    cout << num << '\n';

    return 0;
}
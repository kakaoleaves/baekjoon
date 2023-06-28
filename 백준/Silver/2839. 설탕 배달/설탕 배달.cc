#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a = 3;
    int b = 5;

    int cnt = 0;

    while (n >= 0) {
        if (n % b == 0) {
			cnt += n / b;
			cout << cnt;
			return 0;
		}
		n -= a;
		cnt++;
	}
	cout << -1;

    return 0;
}
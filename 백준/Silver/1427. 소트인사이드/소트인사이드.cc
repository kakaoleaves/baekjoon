#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<int> v(10); // 0 ~ 9

    while (n > 0) {
        v[n % 10]++;
        n /= 10;
	}

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < v[i]; j++) {
			cout << i;
		}
	}
  
    return 0;
}
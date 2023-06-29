#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v(5);
    int avg = 0;

    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        assert(num > 0 && num <= 100 && num % 10 == 0);
        v[i] = num;
        avg += num;
	}

    avg /= 5;
    sort(v.begin(), v.end());

    cout << avg << '\n';
    cout << v[2] << '\n';

    return 0;
}
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    assert(n >= 1 && n <= 1000000000);

    string s = to_string(n);
    sort(s.begin(), s.end(), greater<char>());

    cout << s << endl;

    return 0;
}
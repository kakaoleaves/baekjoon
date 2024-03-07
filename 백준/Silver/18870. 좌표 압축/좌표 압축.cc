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

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < n; i++)
		cout << lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() << ' ';

    return 0;
}
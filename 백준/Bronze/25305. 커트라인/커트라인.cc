#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int k;
vector<int> v(1000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    cout << v[k - 1] << '\n';

    return 0;
}
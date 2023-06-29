#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;    
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
	}

    vector<int> uv(v);
    sort(uv.begin(), uv.end());

    uv.erase(unique(uv.begin(), uv.end()), uv.end());

    for (int i = 0; i < n; i++) {
		cout << lower_bound(uv.begin(), uv.end(), v[i]) - uv.begin() << ' ';
    }

    return 0;
}
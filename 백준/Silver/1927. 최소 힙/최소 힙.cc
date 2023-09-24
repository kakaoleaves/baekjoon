#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n; // 1 <= n <= 100'000
    cin >> n;

    while (n--) {
        int op;
        cin >> op;
        if (op > 0)
            pq.emplace(op);
        else {
            if (pq.empty()) cout << 0 << '\n';
            else {
				cout << pq.top() << '\n';
				pq.pop();
			}
        }
    }

    return 0;
}
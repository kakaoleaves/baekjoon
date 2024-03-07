#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
    void Print() {
        cout << x << " " << y << "\n";
    }
};

vector<coordinate> v(100000);
int n;

bool Compare(coordinate a, coordinate b) {
    if (a.x == b.x) {
		return a.y < b.y;
	}
    else {
		return a.x < b.x;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        coordinate c;
		cin >> c.x >> c.y;
        v[i] = c;
	}

    sort(v.begin(), v.begin() + n, Compare);

    for (int i = 0; i < n; i++) {
        v[i].Print();
    }
  
    return 0;
}
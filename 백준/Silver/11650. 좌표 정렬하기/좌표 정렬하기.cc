#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

struct coordinate {
	int x;
	int y;
};


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    assert(n >= 1 && n <= 100000);

    coordinate* arr = new coordinate[n];
    for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		assert(arr[i].x >= -100000 && arr[i].x <= 100000);
        assert(arr[i].y >= -100000 && arr[i].y <= 100000);
	}

    sort(arr, arr + n, [](coordinate a, coordinate b) {
        if (a.x == b.x) {
			return a.y < b.y;
		}
        else {
			return a.x < b.x;
		}
	});

    for (int i = 0; i < n; i++) {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}
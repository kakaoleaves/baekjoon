#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    assert(n >= 1 && n <= 1000000);
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        assert(arr[i] >= -1000000 && arr[i] <= 1000000);
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";

    return 0;
}
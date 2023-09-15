#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& v, int num) {
    int left = 0;
	int right = (int)v.size() - 1;

    while (left <= right) {
		int mid = (left + right) / 2;

        if (v[mid] == num) {
			return true;
		}
        else if (v[mid] < num) {
			left = mid + 1;
		}
        else {
			right = mid - 1;
		}
	}

	return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> v(n);

    for (auto& i : v)
		cin >> i;

    sort(v.begin(), v.end());

    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        cout << binarySearch(v, num) << '\n';
    }

    return 0;
}
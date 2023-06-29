#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int counting[10000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    assert(n >= 1 && n <= 10000000);

    for (int i = 0; i < n; i++)
    {
		int num;
		cin >> num;
		assert(num >= 1 && num <= 10000);
        int index = num - 1;
		counting[index]++;
	}

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < counting[i]; j++)
        {
			cout << i + 1 << "\n";
		}
    }

    return 0;
}
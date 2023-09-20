#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    while (cin >> n)
    {
        long long num = 1;
        int count = 1;

        while (num % n != 0) {
            num = (num * 10 + 1) % n;
			count++;
        }

        cout << count << '\n';
	}

    return 0;
}
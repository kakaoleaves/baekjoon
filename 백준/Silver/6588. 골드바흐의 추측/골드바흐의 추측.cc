#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1'000'000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 에라토스테네스의 체
    vector<int> prime;
    vector<bool> isPrime;
    isPrime.resize(MAX + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= (int)sqrt(MAX); i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i * i; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        bool isGoldbach = false;
        for (int i = 0; i < prime.size(); i++) {
            int j = n - prime[i];
            if (i > j) break;
            if (isPrime[j]) {
				cout << n << " = " << prime[i] << " + " << j << '\n';
				isGoldbach = true;
				break;
			}
        }
        if (!isGoldbach) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
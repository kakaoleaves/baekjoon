#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;
const int64 MOD = 1'000'000'007;

int64 pow(int64 a, int64 b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
		int64 temp = pow(a, b / 2);
		return (temp * temp) % MOD;
	}
    else {
		return (a * pow(a, b - 1)) % MOD;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int64 a, b;
    a = b = 1;

    for (int i = 1; i <= n; i++) {
		a = (a * i) % MOD;
	}

    for (int i = 1; i <= k; i++) {
        b = (b * i) % MOD;
    }

    for (int i = 1; i <= n - k; i++) {
		b = (b * i) % MOD;
	}

    // Fermat's little theorem
    // a^(p-1) = 1 (mod p)
    // a^(p-2) = a^(-1) (mod p)
    int64 b2 = pow(b, MOD - 2);

    cout << (a * b2) % MOD << endl;
 
    return 0;
}
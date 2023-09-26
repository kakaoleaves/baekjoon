#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct Matrix
{
	long long a, b, c, d;
	Matrix(long long a, long long b, long long c, long long d) : a(a), b(b), c(c), d(d) {}

    Matrix operator*(const Matrix& other) const
    {
		return Matrix(a * other.a + b * other.c, a * other.b + b * other.d, c * other.a + d * other.c, c * other.b + d * other.d);
	}

    Matrix operator%(long long mod) const
    {
        return Matrix(a % mod, b % mod, c % mod, d % mod);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n; // 1 <= n <= 10^18
    cin >> n;

    Matrix ans(1, 0, 0, 1);
    Matrix a(1, 1, 1, 0);

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * a;
			ans = ans % MOD;
		}
		a = a * a;
        a = a % MOD;
		n /= 2;
	}

    cout << ans.b << '\n';


    return 0;
}
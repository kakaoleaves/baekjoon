#include <iostream>
using namespace std;

int pow(int a, int b, int c) {
    if (b == 1) return a % c;
    long long val = pow(a, b / 2, c);
    val = val * val % c;

    if (b % 2 == 0) return (int)val;
    return val * a % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;

    cin >> a >> b >> c;
    cout << pow(a, b, c) << '\n';

    return 0;
}
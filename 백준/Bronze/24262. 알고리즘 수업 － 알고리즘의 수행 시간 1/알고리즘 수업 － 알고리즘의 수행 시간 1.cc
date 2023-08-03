#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int degree = 0;

int MenOfPassion(vector<int>& v, int n)
{
    int i = n / 2;
    cnt++;
    return v[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 1 <= n <= 500,000
    cin >> n;

    vector<int> v(n, 1);

    MenOfPassion(v, n);

    cout << cnt << endl;
    cout << degree << endl;


    return 0;
}
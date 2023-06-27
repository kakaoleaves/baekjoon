#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int N = 0;
int arr[100000] = { 0, };
int len = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	do {
		cin >> N;
		if (N == -1) break;
		assert(N >= 2 && N <= 100000);

		int sum = 0;
		for (int i = 1; i < N; ++i) {
			if (N % i == 0) {
				arr[len++] = i;
				sum += i;
			}
		}
		if (sum == N) {
			cout << N << " = ";
			for (int i = 0; i < len; ++i) {
				cout << arr[i];
				if (i != len - 1) cout << " + ";
			}
			cout << "\n";
		}
		else {
			cout << N << " is NOT perfect.\n";
		}
		len = 0;
	} while (N != -1);

	return 0;
}
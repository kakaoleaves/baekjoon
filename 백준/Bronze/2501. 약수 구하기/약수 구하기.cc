#include <iostream>
#include <cassert>

using namespace std;

int N, K;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	assert(N >= 1 && N <= 10000);
	assert(K >= 1 && K <= N);

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			cnt++;
			if (cnt == K) {
				cout << i << endl;
				return 0;
			}
		}
	}

	cout << 0 << endl;

	return 0;
}
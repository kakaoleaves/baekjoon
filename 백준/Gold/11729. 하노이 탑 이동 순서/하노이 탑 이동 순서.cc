#include <iostream>
using namespace std;

int n; // 1 <= n <= 20

void Hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}
	Hanoi(n - 1, from, to, by); // n-1개를 by로 옮긴다!
	cout << from << " " << to << "\n"; // n번째를 to로 옮긴다!
	Hanoi(n - 1, by, from, to); // n-1개를 from으로 옮긴다!
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	cout<< (1 << n) - 1<<"\n"; // 하노이 탑의 이동 횟수는 2^n - 1이다.

	Hanoi(n, 1, 2, 3);

	return 0;
}
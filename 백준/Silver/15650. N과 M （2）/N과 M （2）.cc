#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& sequence, int n, int m, int start)
{
	// 수열의 길이가 m에 도달하면 출력
	if (sequence.size() == m)
	{
		for (int num : sequence)
			cout << num << ' ';
		cout << '\n';
		return;
	}

	// 백트래킹
	for (int i = start; i <= n; i++)
	{
		sequence.push_back(i); // 수열에 숫자 추가
		backtrack(sequence, n, m, i + 1); // 다음 숫자로 재귀 호출
		sequence.pop_back(); // 수열에서 숫자 제거
	}
}

void generateSequence(int n, int m)
{
	vector<int> sequence;
	backtrack(sequence, n, m, 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	generateSequence(n, m);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;

	int n;
	vector<int> v;

	cin >> n;
	v.resize(n);

	for (auto& p: v)
		cin >> p;

	// 오름차순으로 정렬해야 가장 시간이 적게 걸림
	sort(v.begin(), v.end());

	int total = 0; // 총 소요시간
	int spending = 0; // 각 소요시간

	for (const auto& p : v)
	{
		spending += p;
		total += spending;
	}

	cout << total << '\n';
   
	return 0;
}
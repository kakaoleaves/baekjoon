#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;

	int n; // 1 <= n <= 100, 000;

	cin >> n;
	vector<pair<int, int>> meeting_times(n);

	for (auto & meeting_time : meeting_times)
		cin >> meeting_time.first >> meeting_time.second;

	sort(meeting_times.begin(), meeting_times.end(), [](auto& a, auto& b) {
		if (a.second == b.second) return a.first < b.first;
			return a.second < b.second;
	});

	int cnt = 0, end_time = 0;

	for (auto& meeting_time : meeting_times)
		if (meeting_time.first >= end_time) {
			end_time = meeting_time.second;
			cnt++;
		}

	cout << cnt << '\n';
	
   
	return 0;
}
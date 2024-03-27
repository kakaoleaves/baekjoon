#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

enum {
	BLANK,
	HOUSE,
	CHICKEN_PLACE
};
int N; // 2 <= N <= 50
int M; // 1 <= M <= 13
vector<pair<int, int>> chicken_places;
vector<pair<int, int>> houses;
int ans = numeric_limits<int>::max();

void SelectChickenPlaces(int idx, vector<pair<int, int>>& places) {
	if (places.size() == M) {
		// 치킨 거리 구하기
		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int min_dist = numeric_limits<int>::max();
			for (int j = 0; j < places.size(); j++) {
				int dist = abs(houses[i].first - places[j].first) + abs(houses[i].second - places[j].second);
				min_dist = min(min_dist, dist);
			}
			sum += min_dist;
		}
		ans = min(ans, sum);
		return;
	}
	for (int i = idx; i < chicken_places.size(); i++) {
		places.push_back(chicken_places[i]);
		SelectChickenPlaces(i + 1, places);
		places.pop_back();
	}

}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if (input == HOUSE) {
				houses.push_back({ i, j });
			}
			else if (input == CHICKEN_PLACE) {
				chicken_places.push_back({ i, j });
			}
		}
	}

	vector<pair<int, int>> places;

	SelectChickenPlaces(0, places);

	cout << ans << '\n';

	return 0;
}
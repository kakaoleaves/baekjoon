#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, vector<string>, less<>> clothes_map;

    for (auto& e : clothes) {
        clothes_map[e[1]].push_back(e[0]);
    }

    for (const auto& e : clothes_map) {
        answer *= (e.second.size() + 1);
	}

    answer -= 1;

    return answer;
}
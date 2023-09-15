#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    vector<int> v;
    
    for (int i = 0; i < tangerine.size(); i++) {
        int target = tangerine[i];
        auto it = m.find(target);
        if (it == m.end()) {
            m.insert({target, 1});
        } else {
            m[target] += 1;
        }
    }
    
    for (auto element : m)
        v.emplace_back(element.second);
    
    sort(v.begin(), v.end(), greater<int>());
    
    while (k > 0) {
        if (v[answer] > k) return answer + 1;
        k -= v[answer++];
    }
    
    return answer;
}
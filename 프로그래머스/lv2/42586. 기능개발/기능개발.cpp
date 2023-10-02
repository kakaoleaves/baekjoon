#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    int sz = (int) progresses.size();
    
    vector<int> days(sz, 0);
    
    for (int i = 0; i < sz; i++) {
        days[i] = 100 - progresses[i];
        if (days[i] % speeds[i] > 0) {
            days[i] /= speeds[i];
            days[i]++;
        } else {
            days[i] /= speeds[i];            
        }
    }
    
    for (int i = 0; i < sz; i++)
        q.push(days[i]);
    
    while (!q.empty()) {
        int cnt = 1;
        int front = q.front();
        q.pop();
        while (!q.empty() && q.front() <= front) {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }

    
    
    return answer;
}
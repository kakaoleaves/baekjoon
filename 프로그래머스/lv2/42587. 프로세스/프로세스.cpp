#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
        int answer = 0;
    queue<int> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
		q.push(i);
		pq.push(priorities[i]);
	}

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (priorities[now] == pq.top()) {
			pq.pop();
			answer++;
            if (now == location) {
				break;
			}
		}
        else {
			q.push(now);
		}
    }

    return answer;

    return answer;
}
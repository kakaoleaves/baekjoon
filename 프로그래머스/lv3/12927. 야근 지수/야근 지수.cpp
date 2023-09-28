#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for (const int& work : works)
        pq.push(work);
    
    while (n--) {
        int top = pq.top();
        pq.pop();
        if (top > 0) pq.push(top - 1);
        else return 0;
    }

    while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		answer += ((long long)top * top);
	}

    return answer;
}
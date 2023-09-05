#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s)
    {
        answer.emplace_back(-1);
    }
    else
    {
        int quo = s / n;
        int rem = s % n;
        
        int num = n - rem;
        
        while (num--)
            answer.emplace_back(quo);
        while (rem--)
            answer.emplace_back(quo + 1);        
    }
    
    return answer;
}
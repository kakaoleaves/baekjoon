#include <string>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> v;
    
    v.resize(m * (t - 1) + p);
    int idx = 0;
    int num = 0;

    while (idx < v.size()) {
        if (num == 0) v[idx++] = '0';
        else {
            int tempNum = num;
            stack<char> st;
            while (tempNum > 0) {
                int mod = tempNum % n;
                char c;
                if (mod >= 10) 
                    c = mod - 10 + 'A';
                else 
                    c = mod + '0';
                st.push(c);
                tempNum /= n;
            }
            while (!st.empty()) {
                v[idx++] = st.top();
                st.pop();
            }
        }
        num++;
    }

    for (int i = p - 1; i < v.size(); i += m) {
        answer += v[i];
    }
    
    return answer;
}
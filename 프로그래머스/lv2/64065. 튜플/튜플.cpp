#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Compare {
	public:
		bool operator()(pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
	}
};

vector<int> solution(string s) {
    vector<int> answer;
    stack<char> st;
    string temp = "";
    vector<int> v;
    map<int, int> m;

    // 시작의 { } 제외
    for (int i = 1; i < s.size() - 1; i++) {
        char ch = s[i];
        if (ch == '{') st.push('{');
        else {
            if (!st.empty()) {
                switch (ch) {
                    case ',' : // 원소 추가 
                        v.push_back(stoi(temp));
                        temp = "";
                        break;
                    case '}' : // 튜플 종료 
                        if (temp != "") {
                            v.push_back(stoi(temp));
                            temp = "";
                        }
                        for (int &e: v) {
                            if (m[e]) m[e]++;
                            else m[e] = 1;
                        }
                        v.clear();
                        st.pop();
                        break;
                    default: // 숫자
                        temp += ch;
                        break;
                }
            }
        }        
    }
    
    map<int, int, greater<>> sm;
    
    for (auto it = m.begin(); it != m.end(); it++) {
        sm[(*it).second] = (*it).first;
    }
    
    for (auto it = sm.begin(); it != sm.end(); it++) {
        answer.push_back((*it).second);
    }    
  
    return answer;
}
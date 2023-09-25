#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    string explosion;
    stack<char> st;

    cin >> s;
    cin >> explosion;

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        st.push(*it);
        if (st.size() >= explosion.size()) {
            if (st.top() == explosion.front()) {
				bool flag = true;
				stack<char> temp;
                for (int i = 0; i < explosion.size(); i++) {
                    if (st.top() != explosion[i]) {
						flag = false;
						break;
					}
					temp.push(st.top());
					st.pop();
				}
                if (!flag) {
                    while (!temp.empty()) {
						st.push(temp.top());
						temp.pop();
					}
				}
			}
        }
    }

    if (st.empty()) cout << "FRULA" << "\n";
    else {
        while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
    } 

    return 0;
}
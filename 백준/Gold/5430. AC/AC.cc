#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    while (t--) {
        string p;
        int n;
        string arr;
        deque<int> dq;

        cin >> p >> n >> arr;

        bool isReverse = false;
        bool isError = false;

        string temp = "";

        for (char c : arr)
        {
            if (isdigit(c))
            {
                temp += c;
			}
            else if (c == ',' || c == ']')
            {
                if (!temp.empty())
                {
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
        }

        for (char cmd : p) {
            if (cmd == 'R') {
                isReverse = !isReverse;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                else {
                    if (isReverse) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (isError) {
			cout << "error" << '\n';
		}
        else {
			cout << '[';

            while (!dq.empty()) {
                cout << (isReverse ? dq.back() : dq.front());
                isReverse ? dq.pop_back() : dq.pop_front();
                if (!dq.empty()) {
                    cout << ',';
                }
            }

			cout << ']' << '\n';
		}
    }
}
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    int num = 666;

    while (true) {
		string str = to_string(num);
        if (str.find("666") != string::npos) {
			cnt++;
		}
        if (cnt == n) {
			cout << num << endl;
			break;
		}
		num++;
	}

    return 0;
}
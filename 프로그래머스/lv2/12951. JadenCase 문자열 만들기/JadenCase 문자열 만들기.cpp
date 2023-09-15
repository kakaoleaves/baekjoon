#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    string temp = "";

    for (const char& c : s) {
        if (c == ' ') {
            temp[0] = static_cast<char>(toupper(static_cast<int>(temp[0])));
            v.push_back(temp);
			temp = "";
		}
		else {
            temp += static_cast<char>(tolower(static_cast<int>(c)));
		}
	}

    temp[0] = static_cast<char>(toupper(static_cast<int>(temp[0])));
    v.push_back(temp);

    for (string str : v) {
		answer += str + " ";
	}
    answer.pop_back();

    return answer;
}

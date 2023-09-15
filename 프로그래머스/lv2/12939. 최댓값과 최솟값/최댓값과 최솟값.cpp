#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    string temp = "";

    for (char c : s)
    {
        if (c == ' ')
        {
			v.push_back(stoi(temp));
			temp = "";
		}
        else
        {
			temp += c;
		}
    }

    v.push_back(stoi(temp));

    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());

    answer = to_string(min) + " " + to_string(max);

    return answer;
}
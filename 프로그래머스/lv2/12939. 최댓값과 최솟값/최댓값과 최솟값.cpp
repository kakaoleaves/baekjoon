#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string s) {
    string answer = "";
    set<int> numberSet;

    string tmp = "";
    for (const char& c : s) {
        if (c == ' ') {
            numberSet.insert(stoi(tmp));
            tmp = "";
        }
        else 
            tmp += c;
    }
    
    if (tmp.size() > 0) numberSet.insert(stoi(tmp));
    
    answer += to_string(*numberSet.begin());
    answer += " ";
    answer += to_string(*numberSet.rbegin());
    
    return answer;
}
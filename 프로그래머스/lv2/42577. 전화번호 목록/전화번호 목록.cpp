#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    
    for (string phone_num : phone_book)
        s.insert(phone_num);
    
    for (auto it = s.begin(); it != s.end(); it++) {
        for (auto it2 = next(it); it2 != s.end(); it2++) {
            if (it2->find(*it) == 0) return false;
            else break;
        }
    }

    return true;
}
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int, less<>> m1;
    map<string, int, less<>> m2;

    for (int i = 0; i < str1.size() - 1; i++) {
		string temp = str1.substr(i, 2);
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            if (m1.find(temp) == m1.end()) {
				m1.insert(make_pair(temp, 1));
            }
            else {
				m1[temp]++;
			}
		}
	}

    for (int i = 0; i < str2.size() - 1; i++) {
        string temp = str2.substr(i, 2);
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            if (m2.find(temp) == m2.end()) {
                m2.insert(make_pair(temp, 1));
            }
            else {
                m2[temp]++;
            }
        }
    }

    int intersect_set = 0;
    int union_set = 0;

    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        if (m2.find(iter->first) != m2.end()) {
			intersect_set += min(iter->second, m2[iter->first]);
			union_set += max(iter->second, m2[iter->first]);
            m2.erase(iter->first);
		}
        else {
			union_set += iter->second;
		}
	}

    for (auto iter = m2.begin(); iter != m2.end(); iter++) {
        if (m1.find(iter->first) == m1.end()) {
            union_set += iter->second;
        }
    }

    double jaccard = 0;
    if (union_set == 0) {
		jaccard = 1;
	}
    else {
		jaccard = (double)intersect_set / (double)union_set;
	}

    answer = (int)(jaccard * 65536);
        
    
    return answer;
}
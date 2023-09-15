#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    string copied = s;
    int round = 0;
    int count = 0;

    while (copied != "1")
    {
        round++;
        int tempCount = 0;

        for (auto c : copied)
        {
            if (c == '0')
				tempCount++;
        }

        count += tempCount;

        int temp = copied.size() - tempCount;
        string tempString = "";

        while (temp != 0)
        {
            tempString  = to_string(temp % 2) + tempString;
			temp /= 2;
		}

        copied = tempString;
    }

    answer.push_back(round);
    answer.push_back(count);
    
    return answer;
}
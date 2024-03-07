#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n; // 1 <= n <= 20000
vector<string> words;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    words.reserve(20000);

    cin >> n;

    for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.size() == b.size()) {
			return a < b;
		}
        else {
			return a.size() < b.size();
		}
    });

    words.erase(unique(words.begin(), words.end()), words.end());
  
    for (const auto& word : words) {
        cout << word << '\n';
    }

    return 0;
}
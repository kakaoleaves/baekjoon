#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Member {
    short age;
    string name;
    void Print() const { cout << age << ' ' << name << '\n'; }
};

int n;
vector<Member> members;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    members.reserve(100000);

    cin >> n;

    for (int i = 0; i < n; i++) {
        Member member;
        cin >> member.age >> member.name;
        members.push_back(member);
    }

    stable_sort(members.begin(), members.end(), [](const Member& a, const Member& b) {
        return a.age < b.age;
        });

    for (const auto& member : members) {
        member.Print();
    }

    return 0;
}
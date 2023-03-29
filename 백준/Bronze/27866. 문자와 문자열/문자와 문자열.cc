#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str;
    int i;

    cin >> str;
    cin >> i;
    cout << str.at(i-1);
    return 0;
}